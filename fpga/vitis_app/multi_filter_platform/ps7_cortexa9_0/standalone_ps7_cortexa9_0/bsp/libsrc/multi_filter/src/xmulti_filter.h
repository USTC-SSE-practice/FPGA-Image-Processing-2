// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XMULTI_FILTER_H
#define XMULTI_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmulti_filter_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Ctrl_bus_BaseAddress;
} XMulti_filter_Config;
#endif

typedef struct {
    u64 Ctrl_bus_BaseAddress;
    u32 IsReady;
} XMulti_filter;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMulti_filter_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMulti_filter_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMulti_filter_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMulti_filter_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XMulti_filter_Initialize(XMulti_filter *InstancePtr, UINTPTR BaseAddress);
XMulti_filter_Config* XMulti_filter_LookupConfig(UINTPTR BaseAddress);
#else
int XMulti_filter_Initialize(XMulti_filter *InstancePtr, u16 DeviceId);
XMulti_filter_Config* XMulti_filter_LookupConfig(u16 DeviceId);
#endif
int XMulti_filter_CfgInitialize(XMulti_filter *InstancePtr, XMulti_filter_Config *ConfigPtr);
#else
int XMulti_filter_Initialize(XMulti_filter *InstancePtr, const char* InstanceName);
int XMulti_filter_Release(XMulti_filter *InstancePtr);
#endif

void XMulti_filter_Start(XMulti_filter *InstancePtr);
u32 XMulti_filter_IsDone(XMulti_filter *InstancePtr);
u32 XMulti_filter_IsIdle(XMulti_filter *InstancePtr);
u32 XMulti_filter_IsReady(XMulti_filter *InstancePtr);
void XMulti_filter_EnableAutoRestart(XMulti_filter *InstancePtr);
void XMulti_filter_DisableAutoRestart(XMulti_filter *InstancePtr);

void XMulti_filter_Set_rows(XMulti_filter *InstancePtr, u32 Data);
u32 XMulti_filter_Get_rows(XMulti_filter *InstancePtr);
void XMulti_filter_Set_cols(XMulti_filter *InstancePtr, u32 Data);
u32 XMulti_filter_Get_cols(XMulti_filter *InstancePtr);

void XMulti_filter_InterruptGlobalEnable(XMulti_filter *InstancePtr);
void XMulti_filter_InterruptGlobalDisable(XMulti_filter *InstancePtr);
void XMulti_filter_InterruptEnable(XMulti_filter *InstancePtr, u32 Mask);
void XMulti_filter_InterruptDisable(XMulti_filter *InstancePtr, u32 Mask);
void XMulti_filter_InterruptClear(XMulti_filter *InstancePtr, u32 Mask);
u32 XMulti_filter_InterruptGetEnabled(XMulti_filter *InstancePtr);
u32 XMulti_filter_InterruptGetStatus(XMulti_filter *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
