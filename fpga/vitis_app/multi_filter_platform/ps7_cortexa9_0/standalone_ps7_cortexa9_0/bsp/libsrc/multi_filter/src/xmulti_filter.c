// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xmulti_filter.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMulti_filter_CfgInitialize(XMulti_filter *InstancePtr, XMulti_filter_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_bus_BaseAddress = ConfigPtr->Ctrl_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMulti_filter_Start(XMulti_filter *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_AP_CTRL) & 0x80;
    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMulti_filter_IsDone(XMulti_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMulti_filter_IsIdle(XMulti_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMulti_filter_IsReady(XMulti_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMulti_filter_EnableAutoRestart(XMulti_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_AP_CTRL, 0x80);
}

void XMulti_filter_DisableAutoRestart(XMulti_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_AP_CTRL, 0);
}

void XMulti_filter_Set_rows(XMulti_filter *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_ROWS_DATA, Data);
}

u32 XMulti_filter_Get_rows(XMulti_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_ROWS_DATA);
    return Data;
}

void XMulti_filter_Set_cols(XMulti_filter *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_COLS_DATA, Data);
}

u32 XMulti_filter_Get_cols(XMulti_filter *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_COLS_DATA);
    return Data;
}

void XMulti_filter_InterruptGlobalEnable(XMulti_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_GIE, 1);
}

void XMulti_filter_InterruptGlobalDisable(XMulti_filter *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_GIE, 0);
}

void XMulti_filter_InterruptEnable(XMulti_filter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_IER);
    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_IER, Register | Mask);
}

void XMulti_filter_InterruptDisable(XMulti_filter *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_IER);
    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_IER, Register & (~Mask));
}

void XMulti_filter_InterruptClear(XMulti_filter *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMulti_filter_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_ISR, Mask);
}

u32 XMulti_filter_InterruptGetEnabled(XMulti_filter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_IER);
}

u32 XMulti_filter_InterruptGetStatus(XMulti_filter *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMulti_filter_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMULTI_FILTER_CTRL_BUS_ADDR_ISR);
}

