// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xmulti_filter.h"

extern XMulti_filter_Config XMulti_filter_ConfigTable[];

#ifdef SDT
XMulti_filter_Config *XMulti_filter_LookupConfig(UINTPTR BaseAddress) {
	XMulti_filter_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XMulti_filter_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XMulti_filter_ConfigTable[Index].Ctrl_bus_BaseAddress == BaseAddress) {
			ConfigPtr = &XMulti_filter_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMulti_filter_Initialize(XMulti_filter *InstancePtr, UINTPTR BaseAddress) {
	XMulti_filter_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMulti_filter_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMulti_filter_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XMulti_filter_Config *XMulti_filter_LookupConfig(u16 DeviceId) {
	XMulti_filter_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMULTI_FILTER_NUM_INSTANCES; Index++) {
		if (XMulti_filter_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMulti_filter_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMulti_filter_Initialize(XMulti_filter *InstancePtr, u16 DeviceId) {
	XMulti_filter_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMulti_filter_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMulti_filter_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

