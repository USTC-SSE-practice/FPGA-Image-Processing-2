#include "xparameters.h"
#include "xaxidma.h"
#include "xil_printf.h"

#ifdef STDOUT_BASEADDRESS
#undef STDOUT_BASEADDRESS
#define STDOUT_BASEADDRESS XPAR_XUARTPS_0_BASEADDR
#endif

#ifdef STDIN_BASEADDRESS
#undef STDIN_BASEADDRESS
#define STDIN_BASEADDRESS XPAR_XUARTPS_0_BASEADDR
#endif

#include "xil_cache.h"
#include "xuartps.h"

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 128
#define INPUT_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)              // 16384
#define OUTPUT_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT * 5)         // 81920

#define DMA_DEV_ID      0
#define UART_DEVICE_ID  0
#define FILTER_BASE_ADDR XPAR_MULTI_FILTER_0_BASEADDR        // Update if needed

XAxiDma AxiDma;
XUartPs Uart_Ps;

u8 tx_buffer[INPUT_SIZE] __attribute__ ((aligned(32)));      // Input image
u8 rx_buffer[OUTPUT_SIZE] __attribute__ ((aligned(32)));     // All 5 outputs

int main() {
    xil_printf("\n--- Multi-Filter UART-DMA Image Processor ---\r\n");

    // --- UART Initialization ---
    XUartPs_Config *Uart_Config;
    Uart_Config = XUartPs_LookupConfig(UART_DEVICE_ID);
    if (!Uart_Config || XUartPs_CfgInitialize(&Uart_Ps, Uart_Config, Uart_Config->BaseAddress) != XST_SUCCESS) {
        xil_printf("ERROR: UART init failed\r\n");
        return XST_FAILURE;
    }
    xil_printf("UART Initialized\r\n");

    // --- AXI DMA Initialization ---
    XAxiDma_Config *Dma_Config;
    Dma_Config = XAxiDma_LookupConfig(DMA_DEV_ID);
    if (!Dma_Config || XAxiDma_CfgInitialize(&AxiDma, Dma_Config) != XST_SUCCESS) {
        xil_printf("ERROR: DMA init failed\r\n");
        return XST_FAILURE;
    }
    if (XAxiDma_HasSg(&AxiDma)) {
        xil_printf("ERROR: DMA is in Scatter-Gather mode\r\n");
        return XST_FAILURE;
    }
    xil_printf("DMA Initialized\r\n");

    // --- Configure multi_filter IP ---
    *((volatile u32 *)(FILTER_BASE_ADDR + 0x10)) = IMAGE_HEIGHT;
    *((volatile u32 *)(FILTER_BASE_ADDR + 0x18)) = IMAGE_WIDTH;
    xil_printf("Filter IP configured (rows=%d, cols=%d)\r\n", IMAGE_HEIGHT, IMAGE_WIDTH);

    // --- Wait for Start Byte ---
    xil_printf("Waiting for handshake from PC...\r\n");
    while (!XUartPs_IsReceiveData(Uart_Ps.Config.BaseAddress));
    u8 start_signal = XUartPs_RecvByte(Uart_Ps.Config.BaseAddress);
    if (start_signal != 0x01) {
        xil_printf("Invalid start byte received: %02X\r\n", start_signal);
        return XST_FAILURE;
    }
    xil_printf("Start signal received\r\n");

    // --- Send "ready" message to PC ---
    char *ready_msg = "ready\n";
    for (int i = 0; ready_msg[i] != '\0'; i++) {
        while (XUartPs_IsTransmitFull(Uart_Ps.Config.BaseAddress));
        XUartPs_SendByte(Uart_Ps.Config.BaseAddress, ready_msg[i]);
    }

    // --- Receive Image from PC ---
    xil_printf("Receiving %d bytes of image data...\r\n", INPUT_SIZE);
    for (int i = 0; i < INPUT_SIZE; i++) {
        while (!XUartPs_IsReceiveData(Uart_Ps.Config.BaseAddress));
        tx_buffer[i] = XUartPs_RecvByte(Uart_Ps.Config.BaseAddress);
    }
    xil_printf("Image received\r\n");

    // --- Cache Maintenance ---
    Xil_DCacheFlushRange((UINTPTR)tx_buffer, INPUT_SIZE);
    Xil_DCacheFlushRange((UINTPTR)rx_buffer, OUTPUT_SIZE);

    // --- Start DMA Transfers ---
    xil_printf("Starting DMA transfers (TX/RX)...\r\n");
    if (XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR)rx_buffer, OUTPUT_SIZE, XAXIDMA_DEVICE_TO_DMA) != XST_SUCCESS) {
        xil_printf("ERROR: S2MM transfer failed\r\n");
        return XST_FAILURE;
    }
    if (XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR)tx_buffer, INPUT_SIZE, XAXIDMA_DMA_TO_DEVICE) != XST_SUCCESS) {
        xil_printf("ERROR: MM2S transfer failed\r\n");
        return XST_FAILURE;
    }

    while (XAxiDma_Busy(&AxiDma, XAXIDMA_DMA_TO_DEVICE));
    while (XAxiDma_Busy(&AxiDma, XAXIDMA_DEVICE_TO_DMA));
    xil_printf("DMA Processing Complete\r\n");

    Xil_DCacheInvalidateRange((UINTPTR)rx_buffer, OUTPUT_SIZE);

    // --- Send Back Result (All 5 Filters) ---
    xil_printf("Sending back %d bytes...\r\n", OUTPUT_SIZE);
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        while (XUartPs_IsTransmitFull(Uart_Ps.Config.BaseAddress));
        XUartPs_SendByte(Uart_Ps.Config.BaseAddress, rx_buffer[i]);
    }

    xil_printf("All results sent!\r\n");
    xil_printf("--- DONE ---\r\n");

    return 0;
}
