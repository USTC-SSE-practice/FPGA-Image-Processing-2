#include "multi_filter.h"
#include <iostream>
#include <fstream>

int main() {
    hls::stream<pixel_t> in_stream;
    hls::stream<pixel_t> out_box;
    hls::stream<pixel_t> out_sobel;
    hls::stream<pixel_t> out_unsharp;
    hls::stream<pixel_t> out_high;
    hls::stream<pixel_t> out_low;

    // Create a synthetic 128x128 grayscale test image
    for (int i = 0; i < IMG_ROWS * IMG_COLS; ++i) {
        pixel_t px;
        px.data = i % 256;  // Pattern: 0, 1, 2, ..., 255, 0, 1, ...
        px.keep = -1;
        px.strb = -1;
        px.user = 0;
        px.id = 0;
        px.dest = 0;
        px.last = (i == IMG_ROWS * IMG_COLS - 1) ? 1 : 0;
        in_stream.write(px);
    }

    // Call top-level filter function
    multi_filter_top(in_stream, out_box, out_sobel, out_unsharp, out_high, out_low, IMG_ROWS, IMG_COLS);

    // Read and print first 10 output pixels from each filter
    std::cout << "First 10 output pixels from each filter:\n";
    for (int i = 0; i < 10; ++i) {
        pixel_t px_box    = out_box.read();
        pixel_t px_sobel  = out_sobel.read();
        pixel_t px_unsharp= out_unsharp.read();
        pixel_t px_high   = out_high.read();
        pixel_t px_low    = out_low.read();

        std::cout << "Pixel[" << i << "] "
                  << "Box: " << (int)px_box.data
                  << ", Sobel: " << (int)px_sobel.data
                  << ", Unsharp: " << (int)px_unsharp.data
                  << ", High: " << (int)px_high.data
                  << ", Low: " << (int)px_low.data
                  << "\n";
    }

    return 0;
}
