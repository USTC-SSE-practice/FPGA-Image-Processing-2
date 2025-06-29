# FPGA-Image-Processing-2

Team Members:

      NAME: MARJAN UR RAHMAN REMO [SL24225005]
      NAME: RAOHA BIN MEJBA [SL24225002]
      NAME: MD HEZBULLAH [SL24225009]

## 📌 Project Overview

This project implements a hardware-accelerated image filtering system using a **ZedBoard (Zynq-7000 XC7Z020CLG484-1)**. It supports **five image filters**:
- Box Blur
- Sobel Filter Edge Detection
- Unsharp Masking
- High Pass Filter
- Low Pass Filter

The filters are implemented using a single **HLS IP module** called `multi_filter`. A Python GUI communicates with the board over UART, allowing users to upload an image, send it to the FPGA, and view the processed results.

<p align="center">
  <img src="Project Photos/User Interface of GUI.png" width="800">    
</p>

<p align="center">
  Fig: User Interface of GUI APP
</p>

---

## 🔧 Hardware Specifications

- **Board**: ZedBoard (Zynq-7000 XC7Z020CLG484-1)
- **Communication**: USB-UART (via UART1 on MIO 48/49)
- **Clock**: FCLK_CLK0 from Zynq PS
- **Interface**: AXI DMA + AXI-Lite

---

## ⚙️ Software Requirements

| Tool       | Version     |
|------------|-------------|
| Vivado     | 2024.2      |
| Vitis      | 2024.2      |
| Python     | 3.x         |
| Python Packages | `Pillow`, `pyserial`, `tkinter` |

---

## 📁 Folder Structure

      project-root/
      │
      ├── fpga/ 
      │ ├── hls/ # HLS source code and packaged IP (multi_filter.zip)
      │ ├── vivado_project/ # Vivado block design and exported XSA
      │ ├── vitis_xsa/ # exported XSA
      │ ├── vitis_app/ # Vitis application with main.c
      ├── gui_app/ # Python GUI
      │ ├── app.py
      │ ├── _pycache_
      │ └── Background.png
      ├── Project Photos/ # Contains the screenshots of GUI App implementation outputs and project diagrams
      ├── block_design.pdf
      └── README.md # This guide


---

## 🚀 How to Run the Project

### 1. Setup and Program FPGA

- Open **Vitis IDE**
- Import hardware platform using the provided `.xsa` file
- Import the **baremetal application** with the updated `main.c`
- Connect ZedBoard to PC (J14 USB-UART), power on the board
- Launch the application on hardware (Run → Launch on Hardware)

You should see the following messages via UART (e.g., Tera Term):

      |         Terminal         |
      |------------|-------------|
      |     UART Initialized     |
      |     DMA Initialized      |
      |   Filter IP configured   |
---

### 2. Run the Python GUI

1. Navigate to `gui_app/`:
   ```bash
   cd gui_app
   python main.py

2. In the GUI:
    * Click Upload Image and choose any .png, .jpg, or .bmp

    * The image will be resized to 128×128 grayscale

    * Click Run on FPGA

    * After a few seconds, you will see:

        * Original image

        * Sobel, Box Blur, Unsharp, High Pass, and Low Pass filtered results


# 🛠️ Troubleshooting

| Issue                        | Solution                                           |
| ---------------------------- | -------------------------------------------------- |
| No UART output               | Check COM port, power jumper, and UART1 MIO config |
| GUI stuck on "FPGA ready..." | Ensure the board is programmed and handshake works |
| Distorted output images      | Check that input is properly resized to 128×128    |
| Timeout waiting for result   | Recheck baud rate (should be 115200)               |


# 📸 Project Screenshot

<p align="center">
  <img src="Project Photos/GUI_Screenshoot_1.png" width="800">
  <img src="Project Photos/GUI_Screenshoot_2.png" width="800">
  <img src="Project Photos/GUI_Screenshoot_5.png" width="800">
</p>

# 📧 Contact
- Raoha Bin Mejba
- raoha@mail.ustc.edu.cn
