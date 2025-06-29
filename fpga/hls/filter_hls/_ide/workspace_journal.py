# 2025-06-25T22:44:52.634027300
import vitis

client = vitis.create_client()
client.set_workspace(path="filter_hls")

comp = client.create_hls_component(name = "filter_hls",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="filter_hls")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

vitis.dispose()

