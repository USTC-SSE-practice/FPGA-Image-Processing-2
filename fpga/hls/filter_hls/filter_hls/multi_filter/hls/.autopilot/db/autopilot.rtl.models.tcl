set SynModuleInfo {
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_96_1_VITIS_LOOP_97_2 MODELNAME multi_filter_Pipeline_VITIS_LOOP_96_1_VITIS_LOOP_97_2 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_96_1_VITIS_LOOP_97_2
    SUBMODULES {
      {MODELNAME multi_filter_mul_31ns_33ns_63_2_1 RTLNAME multi_filter_mul_31ns_33ns_63_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_urem_31ns_3ns_2_35_1 RTLNAME multi_filter_urem_31ns_3ns_2_35_1 BINDTYPE op TYPE urem IMPL auto LATENCY 34 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_flow_control_loop_pipe_sequential_init RTLNAME multi_filter_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME multi_filter_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_6_1_VITIS_LOOP_7_2 MODELNAME multi_filter_Pipeline_VITIS_LOOP_6_1_VITIS_LOOP_7_2 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_6_1_VITIS_LOOP_7_2
    SUBMODULES {
      {MODELNAME multi_filter_urem_7ns_3ns_2_11_1 RTLNAME multi_filter_urem_7ns_3ns_2_11_1 BINDTYPE op TYPE urem IMPL auto LATENCY 10 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_mul_7ns_9ns_15_1_1 RTLNAME multi_filter_mul_7ns_9ns_15_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_sparsemux_7_2_8_1_1 RTLNAME multi_filter_sparsemux_7_2_8_1_1 BINDTYPE op TYPE sparsemux IMPL onehotencoding_realdef}
      {MODELNAME multi_filter_sparsemux_253_7_8_1_1 RTLNAME multi_filter_sparsemux_253_7_8_1_1 BINDTYPE op TYPE sparsemux IMPL compactencoding_dontcare}
      {MODELNAME multi_filter_mul_11s_11s_22_1_1 RTLNAME multi_filter_mul_11s_11s_22_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_mac_muladd_11s_11s_22s_22_4_1 RTLNAME multi_filter_mac_muladd_11s_11s_22s_22_4_1 BINDTYPE op TYPE all IMPL dsp_slice LATENCY 3}
    }
  }
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_25_1_VITIS_LOOP_26_2 MODELNAME multi_filter_Pipeline_VITIS_LOOP_25_1_VITIS_LOOP_26_2 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_25_1_VITIS_LOOP_26_2
    SUBMODULES {
      {MODELNAME multi_filter_am_addmul_11ns_10ns_13ns_25_4_1 RTLNAME multi_filter_am_addmul_11ns_10ns_13ns_25_4_1 BINDTYPE op TYPE all IMPL dsp_slice LATENCY 3}
    }
  }
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_25_1_VITIS_LOOP_26_21 MODELNAME multi_filter_Pipeline_VITIS_LOOP_25_1_VITIS_LOOP_26_21 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_25_1_VITIS_LOOP_26_21}
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_42_1_VITIS_LOOP_43_2 MODELNAME multi_filter_Pipeline_VITIS_LOOP_42_1_VITIS_LOOP_43_2 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_42_1_VITIS_LOOP_43_2
    SUBMODULES {
      {MODELNAME multi_filter_urem_8ns_3ns_2_12_1 RTLNAME multi_filter_urem_8ns_3ns_2_12_1 BINDTYPE op TYPE urem IMPL auto LATENCY 11 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_mul_8ns_10ns_17_1_1 RTLNAME multi_filter_mul_8ns_10ns_17_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_sparsemux_257_7_8_1_1 RTLNAME multi_filter_sparsemux_257_7_8_1_1 BINDTYPE op TYPE sparsemux IMPL compactencoding_dontcare}
      {MODELNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_42_1_VITIS_LOOP_43_2_blur_127_local_RAM_AUTObkb RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_42_1_VITIS_LOOP_43_2_blur_127_local_RAM_AUTObkb BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_55_1_VITIS_LOOP_56_2 MODELNAME multi_filter_Pipeline_VITIS_LOOP_55_1_VITIS_LOOP_56_2 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_55_1_VITIS_LOOP_56_2}
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_70_1_VITIS_LOOP_71_2 MODELNAME multi_filter_Pipeline_VITIS_LOOP_70_1_VITIS_LOOP_71_2 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_70_1_VITIS_LOOP_71_2
    SUBMODULES {
      {MODELNAME multi_filter_am_addmul_10ns_8ns_12ns_23_4_1 RTLNAME multi_filter_am_addmul_10ns_8ns_12ns_23_4_1 BINDTYPE op TYPE all IMPL dsp_slice LATENCY 3}
    }
  }
  {SRCNAME multi_filter_Pipeline_VITIS_LOOP_112_3_VITIS_LOOP_113_4_VITIS_LOOP_114_5 MODELNAME multi_filter_Pipeline_VITIS_LOOP_112_3_VITIS_LOOP_113_4_VITIS_LOOP_114_5 RTLNAME multi_filter_multi_filter_Pipeline_VITIS_LOOP_112_3_VITIS_LOOP_113_4_VITIS_LOOP_114_5}
  {SRCNAME multi_filter MODELNAME multi_filter RTLNAME multi_filter IS_TOP 1
    SUBMODULES {
      {MODELNAME multi_filter_mul_31ns_31ns_62_2_1 RTLNAME multi_filter_mul_31ns_31ns_62_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_blur_RAM_AUTO_1R1W RTLNAME multi_filter_blur_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_image_RAM_AUTO_1R1W RTLNAME multi_filter_image_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_result_RAM_AUTO_1R1W RTLNAME multi_filter_result_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME multi_filter_CTRL_BUS_s_axi RTLNAME multi_filter_CTRL_BUS_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME multi_filter_regslice_both RTLNAME multi_filter_regslice_both BINDTYPE interface TYPE adapter IMPL reg_slice}
    }
  }
}
