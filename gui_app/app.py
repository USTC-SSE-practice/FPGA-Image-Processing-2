import tkinter as tk
from tkinter import filedialog
from tkinter import ttk
from PIL import Image, ImageTk
import numpy as np
import serial
import time
import os

class FPGAOutputViewer:
    def __init__(self, root):
        self.root = root
        self.root.title("FPGA Image Processing GUI App")
        self.root.attributes('-fullscreen', True)

        screen_width = self.root.winfo_screenwidth()
        screen_height = self.root.winfo_screenheight()

        self.canvas = tk.Canvas(root, width=screen_width, height=screen_height, highlightthickness=0)
        self.canvas.pack(fill=tk.BOTH, expand=True)

        try:
            bg_img = Image.open('Background.png').resize((screen_width, screen_height), Image.LANCZOS)
            self.bg_image = ImageTk.PhotoImage(bg_img)
            self.canvas.create_image(0, 0, anchor=tk.NW, image=self.bg_image, tags="bg")
            self.canvas.tag_lower("bg")
        except Exception as e:
            print("Background load failed:", e)
            self.canvas.config(bg="gray")

        style = ttk.Style()
        style.theme_use('default')
        style.configure('Upload.TButton', font=('Helvetica', 25, 'bold'), foreground='black', background='#26C4D3', padding=10, highlightbackground='black', highlightcolor='white', borderwidth=1.5)
        style.map('Upload.TButton', background=[('active', '#1DAEBE')])
        style.configure('Save.TButton', font=('Helvetica', 25, 'bold'), foreground='black', background='#21F391', padding=10, highlightbackground='black', highlightcolor='white', borderwidth=1.5)
        style.map('Save.TButton', background=[('active', '#1FD382')])

        self.upload_btn = ttk.Button(root, text="Upload Image", style='Upload.TButton', command=self.upload_input)
        self.save_btn = ttk.Button(root, text="Save Outputs", style='Save.TButton', command=self.save_all)

        self.canvas.create_window(screen_width - 340, 355, anchor=tk.NW, window=self.upload_btn)
        self.canvas.create_window(screen_width - 340, 435, anchor=tk.NW, window=self.save_btn)

        self.image_refs = []
        self.image_files = [None] * 6
        self.image_labels = ["Input Image", "Box Blur", "Edge Detection", "Sharpening", "High Pass", "Low Pass"]

    def upload_input(self):
        input_path = filedialog.askopenfilename(title="Select 128x128 Grayscale Input Image")
        if not input_path:
            return

        # Load and flatten image
        image = Image.open(input_path).convert('L').resize((128, 128))
        image_array = np.array(image, dtype=np.uint8).flatten()
        self.image_files[0] = input_path

        try:
            port = 'COM4'
            baudrate = 115200
            timeout = 15
            ser = serial.Serial(port, baudrate, timeout=timeout)
            time.sleep(1.5)

            print("[UART] Sending handshake...")
            ser.write(b'\x01')

            print("[UART] Waiting for FPGA ready...")
            buffer = b""
            start_time = time.time()
            while b"ready\n" not in buffer:
                if ser.in_waiting:
                    buffer += ser.read(ser.in_waiting)
                if time.time() - start_time > timeout:
                    raise TimeoutError("Timeout waiting for 'ready' from FPGA")

            print("[UART] Sending image data...")
            ser.write(image_array.tobytes())

            print("[UART] Receiving filtered results...")
            INPUT_SIZE = 128 * 128
            OUTPUT_SIZE = INPUT_SIZE * 5
            received = bytearray()
            while len(received) < OUTPUT_SIZE:
                chunk = ser.read(OUTPUT_SIZE - len(received))
                if not chunk:
                    break
                received.extend(chunk)

            if len(received) != OUTPUT_SIZE:
                raise IOError(f"Expected {OUTPUT_SIZE} bytes, got {len(received)}")

            print("[UART] Data received. Updating GUI...")
            for i in range(5):
                arr = np.frombuffer(received[i*INPUT_SIZE:(i+1)*INPUT_SIZE], dtype=np.uint8).reshape((128, 128))
                img_path = f"fpga_output_{i}.png"
                Image.fromarray(arr).save(img_path)
                self.image_files[i+1] = img_path

        except Exception as e:
            print(f"[ERROR] {e}")
        finally:
            if 'ser' in locals() and ser.is_open:
                ser.close()

        self.display_images()

    def display_images(self):
        self.canvas.delete("img")
        self.image_refs.clear()

        start_x, start_y = 40, 260
        gap_x, gap_y = 320, 320

        for i, path in enumerate(self.image_files):
            if not path:
                continue
            try:
                img = Image.open(path).resize((250, 220), Image.LANCZOS)
                img_tk = ImageTk.PhotoImage(img)
                row, col = divmod(i, 3)
                x = start_x + col * gap_x
                y = start_y + row * gap_y
                self.canvas.create_image(x, y, anchor=tk.NW, image=img_tk, tags="img")
                self.canvas.create_text(x + 125, y + 230, text=self.image_labels[i], fill="white", font=("Helvetica", 14), tags="img")
                self.image_refs.append(img_tk)
            except Exception as e:
                print(f"Failed to load {path}: {e}")

    def save_all(self):
        folder = filedialog.askdirectory(title="Select Folder to Save Images")
        if not folder:
            return

        for i, path in enumerate(self.image_files):
            if path:
                try:
                    img = Image.open(path)
                    save_path = os.path.join(folder, f"{self.image_labels[i].replace(' ', '_').lower()}.png")
                    img.save(save_path)
                    print(f"Saved: {save_path}")
                except Exception as e:
                    print(f"Failed to save image {path}: {e}")

if __name__ == "__main__":
    root = tk.Tk()
    app = FPGAOutputViewer(root)
    root.mainloop()
