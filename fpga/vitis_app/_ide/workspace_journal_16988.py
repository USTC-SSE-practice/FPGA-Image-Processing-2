# 2025-06-26T02:50:14.005047600
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis_app")

platform = client.create_platform_component(name = "multi_filter_platform",hw_design = "$COMPONENT_LOCATION/../../vitis_xsa/filter_bd_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0")

comp = client.create_app_component(name="multi_filter_app",platform = "$COMPONENT_LOCATION/../multi_filter_platform/export/multi_filter_platform/multi_filter_platform.xpfm",domain = "standalone_ps7_cortexa9_0")

platform = client.get_component(name="multi_filter_platform")
status = platform.build()

comp = client.get_component(name="multi_filter_app")
comp.build()

vitis.dispose()

