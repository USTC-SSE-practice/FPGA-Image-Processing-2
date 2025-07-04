// (c) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// (c) Copyright 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of AMD and is protected under U.S. and international copyright
// and other intellectual property laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// AMD, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND AMD HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) AMD shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or AMD had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// AMD products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of AMD products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: xilinx.com:hls:multi_filter:1.0
// IP Revision: 2114144014

`timescale 1ns/1ps

(* IP_DEFINITION_SOURCE = "HLS" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module filter_bd_multi_filter_0_0 (
  s_axi_CTRL_BUS_ARADDR,
  s_axi_CTRL_BUS_ARREADY,
  s_axi_CTRL_BUS_ARVALID,
  s_axi_CTRL_BUS_AWADDR,
  s_axi_CTRL_BUS_AWREADY,
  s_axi_CTRL_BUS_AWVALID,
  s_axi_CTRL_BUS_BREADY,
  s_axi_CTRL_BUS_BRESP,
  s_axi_CTRL_BUS_BVALID,
  s_axi_CTRL_BUS_RDATA,
  s_axi_CTRL_BUS_RREADY,
  s_axi_CTRL_BUS_RRESP,
  s_axi_CTRL_BUS_RVALID,
  s_axi_CTRL_BUS_WDATA,
  s_axi_CTRL_BUS_WREADY,
  s_axi_CTRL_BUS_WSTRB,
  s_axi_CTRL_BUS_WVALID,
  ap_clk,
  ap_rst_n,
  interrupt,
  in_stream_TDATA,
  in_stream_TDEST,
  in_stream_TID,
  in_stream_TKEEP,
  in_stream_TLAST,
  in_stream_TREADY,
  in_stream_TSTRB,
  in_stream_TUSER,
  in_stream_TVALID,
  out_stream_TDATA,
  out_stream_TDEST,
  out_stream_TID,
  out_stream_TKEEP,
  out_stream_TLAST,
  out_stream_TREADY,
  out_stream_TSTRB,
  out_stream_TUSER,
  out_stream_TVALID
);

(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS ARADDR" *)
(* X_INTERFACE_MODE = "slave" *)
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME s_axi_CTRL_BUS, ADDR_WIDTH 5, DATA_WIDTH 32, PROTOCOL AXI4LITE, READ_WRITE_MODE READ_WRITE, FREQ_HZ 50000000, ID_WIDTH 0, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_BURST 0, HAS_LOCK 0, HAS_PROT 0, HAS_CACHE 0, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 1, NUM_WRITE_OUTSTANDING 1, MAX_BURST_LENGTH 1, PHASE 0.0, CLK_DOMAIN filter_bd_processing_system7_0_0_FCLK_CLK0, NUM_READ_\
THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0" *)
input wire [4 : 0] s_axi_CTRL_BUS_ARADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS ARREADY" *)
output wire s_axi_CTRL_BUS_ARREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS ARVALID" *)
input wire s_axi_CTRL_BUS_ARVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS AWADDR" *)
input wire [4 : 0] s_axi_CTRL_BUS_AWADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS AWREADY" *)
output wire s_axi_CTRL_BUS_AWREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS AWVALID" *)
input wire s_axi_CTRL_BUS_AWVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS BREADY" *)
input wire s_axi_CTRL_BUS_BREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS BRESP" *)
output wire [1 : 0] s_axi_CTRL_BUS_BRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS BVALID" *)
output wire s_axi_CTRL_BUS_BVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS RDATA" *)
output wire [31 : 0] s_axi_CTRL_BUS_RDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS RREADY" *)
input wire s_axi_CTRL_BUS_RREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS RRESP" *)
output wire [1 : 0] s_axi_CTRL_BUS_RRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS RVALID" *)
output wire s_axi_CTRL_BUS_RVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS WDATA" *)
input wire [31 : 0] s_axi_CTRL_BUS_WDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS WREADY" *)
output wire s_axi_CTRL_BUS_WREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS WSTRB" *)
input wire [3 : 0] s_axi_CTRL_BUS_WSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 s_axi_CTRL_BUS WVALID" *)
input wire s_axi_CTRL_BUS_WVALID;
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 ap_clk CLK" *)
(* X_INTERFACE_MODE = "slave" *)
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ap_clk, ASSOCIATED_BUSIF s_axi_CTRL_BUS:in_stream:out_stream, ASSOCIATED_RESET ap_rst_n, FREQ_HZ 50000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN filter_bd_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0" *)
input wire ap_clk;
(* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 ap_rst_n RST" *)
(* X_INTERFACE_MODE = "slave" *)
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME ap_rst_n, POLARITY ACTIVE_LOW, INSERT_VIP 0" *)
input wire ap_rst_n;
(* X_INTERFACE_INFO = "xilinx.com:signal:interrupt:1.0 interrupt INTERRUPT" *)
(* X_INTERFACE_MODE = "master" *)
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME interrupt, SENSITIVITY LEVEL_HIGH, PortWidth 1" *)
output wire interrupt;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TDATA" *)
(* X_INTERFACE_MODE = "slave" *)
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME in_stream, TUSER_WIDTH 1, TDATA_NUM_BYTES 1, TDEST_WIDTH 1, TID_WIDTH 1, HAS_TREADY 1, HAS_TSTRB 1, HAS_TKEEP 1, HAS_TLAST 1, FREQ_HZ 50000000, PHASE 0.0, CLK_DOMAIN filter_bd_processing_system7_0_0_FCLK_CLK0, LAYERED_METADATA undef, INSERT_VIP 0" *)
input wire [7 : 0] in_stream_TDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TDEST" *)
input wire [0 : 0] in_stream_TDEST;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TID" *)
input wire [0 : 0] in_stream_TID;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TKEEP" *)
input wire [0 : 0] in_stream_TKEEP;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TLAST" *)
input wire [0 : 0] in_stream_TLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TREADY" *)
output wire in_stream_TREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TSTRB" *)
input wire [0 : 0] in_stream_TSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TUSER" *)
input wire [0 : 0] in_stream_TUSER;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 in_stream TVALID" *)
input wire in_stream_TVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TDATA" *)
(* X_INTERFACE_MODE = "master" *)
(* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME out_stream, TUSER_WIDTH 1, TDATA_NUM_BYTES 1, TDEST_WIDTH 1, TID_WIDTH 1, HAS_TREADY 1, HAS_TSTRB 1, HAS_TKEEP 1, HAS_TLAST 1, FREQ_HZ 50000000, PHASE 0.0, CLK_DOMAIN filter_bd_processing_system7_0_0_FCLK_CLK0, LAYERED_METADATA undef, INSERT_VIP 0" *)
output wire [7 : 0] out_stream_TDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TDEST" *)
output wire [0 : 0] out_stream_TDEST;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TID" *)
output wire [0 : 0] out_stream_TID;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TKEEP" *)
output wire [0 : 0] out_stream_TKEEP;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TLAST" *)
output wire [0 : 0] out_stream_TLAST;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TREADY" *)
input wire out_stream_TREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TSTRB" *)
output wire [0 : 0] out_stream_TSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TUSER" *)
output wire [0 : 0] out_stream_TUSER;
(* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 out_stream TVALID" *)
output wire out_stream_TVALID;

(* SDX_KERNEL = "true" *)
(* SDX_KERNEL_TYPE = "hls" *)
(* SDX_KERNEL_SIM_INST = "" *)
  multi_filter #(
    .C_S_AXI_CTRL_BUS_ADDR_WIDTH(5),
    .C_S_AXI_CTRL_BUS_DATA_WIDTH(32)
  ) inst (
    .s_axi_CTRL_BUS_ARADDR(s_axi_CTRL_BUS_ARADDR),
    .s_axi_CTRL_BUS_ARREADY(s_axi_CTRL_BUS_ARREADY),
    .s_axi_CTRL_BUS_ARVALID(s_axi_CTRL_BUS_ARVALID),
    .s_axi_CTRL_BUS_AWADDR(s_axi_CTRL_BUS_AWADDR),
    .s_axi_CTRL_BUS_AWREADY(s_axi_CTRL_BUS_AWREADY),
    .s_axi_CTRL_BUS_AWVALID(s_axi_CTRL_BUS_AWVALID),
    .s_axi_CTRL_BUS_BREADY(s_axi_CTRL_BUS_BREADY),
    .s_axi_CTRL_BUS_BRESP(s_axi_CTRL_BUS_BRESP),
    .s_axi_CTRL_BUS_BVALID(s_axi_CTRL_BUS_BVALID),
    .s_axi_CTRL_BUS_RDATA(s_axi_CTRL_BUS_RDATA),
    .s_axi_CTRL_BUS_RREADY(s_axi_CTRL_BUS_RREADY),
    .s_axi_CTRL_BUS_RRESP(s_axi_CTRL_BUS_RRESP),
    .s_axi_CTRL_BUS_RVALID(s_axi_CTRL_BUS_RVALID),
    .s_axi_CTRL_BUS_WDATA(s_axi_CTRL_BUS_WDATA),
    .s_axi_CTRL_BUS_WREADY(s_axi_CTRL_BUS_WREADY),
    .s_axi_CTRL_BUS_WSTRB(s_axi_CTRL_BUS_WSTRB),
    .s_axi_CTRL_BUS_WVALID(s_axi_CTRL_BUS_WVALID),
    .ap_clk(ap_clk),
    .ap_rst_n(ap_rst_n),
    .interrupt(interrupt),
    .in_stream_TDATA(in_stream_TDATA),
    .in_stream_TDEST(in_stream_TDEST),
    .in_stream_TID(in_stream_TID),
    .in_stream_TKEEP(in_stream_TKEEP),
    .in_stream_TLAST(in_stream_TLAST),
    .in_stream_TREADY(in_stream_TREADY),
    .in_stream_TSTRB(in_stream_TSTRB),
    .in_stream_TUSER(in_stream_TUSER),
    .in_stream_TVALID(in_stream_TVALID),
    .out_stream_TDATA(out_stream_TDATA),
    .out_stream_TDEST(out_stream_TDEST),
    .out_stream_TID(out_stream_TID),
    .out_stream_TKEEP(out_stream_TKEEP),
    .out_stream_TLAST(out_stream_TLAST),
    .out_stream_TREADY(out_stream_TREADY),
    .out_stream_TSTRB(out_stream_TSTRB),
    .out_stream_TUSER(out_stream_TUSER),
    .out_stream_TVALID(out_stream_TVALID)
  );
endmodule
