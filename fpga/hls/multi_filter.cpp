#include "multi_filter.h"

const int kernel_box[3][3]    = {{1,1,1},{1,1,1},{1,1,1}};
const int kernel_unsharp[3][3]= {{0,-1,0},{-1,5,-1},{0,-1,0}};
const int kernel_high[3][3]   = {{0,-7,-7},{0,45,0},{-7,-7,0}};
const int kernel_low[3][3]    = {{0,0,0},{0,5,0},{0,0,0}};
const int sobel_x[3][3]       = {{-1,0,1},{-2,0,2},{-1,0,1}};
const int sobel_y[3][3]       = {{1,2,1},{0,0,0},{-1,-2,-1}};

int clamp(int val) {
    if (val < 0) return 0;
    if (val > 255) return 255;
    return val;
}

void multi_filter_top(hls::stream<pixel_t> &in_stream,
                      hls::stream<pixel_t> &out_box,
                      hls::stream<pixel_t> &out_sobel,
                      hls::stream<pixel_t> &out_unsharp,
                      hls::stream<pixel_t> &out_high,
                      hls::stream<pixel_t> &out_low,
                      int rows,
                      int cols) {
#pragma HLS INTERFACE axis port=in_stream
#pragma HLS INTERFACE axis port=out_box
#pragma HLS INTERFACE axis port=out_sobel
#pragma HLS INTERFACE axis port=out_unsharp
#pragma HLS INTERFACE axis port=out_high
#pragma HLS INTERFACE axis port=out_low

#pragma HLS INTERFACE s_axilite port=rows bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=cols bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS

    ap_uint<8> linebuf[3][IMG_COLS];
#pragma HLS ARRAY_PARTITION variable=linebuf complete dim=1

    ap_uint<8> window[3][3];

    for (int row = 0; row < rows + 1; row++) {
        for (int col = 0; col < cols; col++) {
#pragma HLS PIPELINE II=1

            pixel_t in_pixel;
            ap_uint<8> in_val = 0;

            if (row < rows) {
                in_pixel = in_stream.read();
                in_val = in_pixel.data;
            }

            // Shift buffer
            linebuf[0][col] = linebuf[1][col];
            linebuf[1][col] = linebuf[2][col];
            linebuf[2][col] = in_val;

            if (row >= 2 && col >= 2) {
                // fill window
                for (int i = 0; i < 3; i++) {
#pragma HLS UNROLL
                    window[i][0] = linebuf[i][col - 2];
                    window[i][1] = linebuf[i][col - 1];
                    window[i][2] = linebuf[i][col];
                }

                // Apply filters
                int box_sum = 0, unsharp = 0, high = 0, low_sum = 0;
                int Gx = 0, Gy = 0;

                for (int i = 0; i < 3; i++) {
#pragma HLS UNROLL
                    for (int j = 0; j < 3; j++) {
#pragma HLS UNROLL
                        int val = window[i][j];
                        box_sum += kernel_box[i][j] * val;
                        unsharp  += kernel_unsharp[i][j] * val;
                        high     += kernel_high[i][j] * val;
                        low_sum  += kernel_low[i][j] * val;
                        Gx       += sobel_x[i][j] * val;
                        Gy       += sobel_y[i][j] * val;
                    }
                }

                int sobel_mag = (Gx*Gx + Gy*Gy) >> 8;

                // Clamp
                box_sum  = clamp(box_sum / 9);
                unsharp  = clamp(unsharp);
                high     = clamp(high/9);
                low_sum  = clamp(low_sum / 9);
                sobel_mag = clamp(sobel_mag);

                // Write outputs
                pixel_t out;
                out.keep = -1;
                out.strb = -1;
                out.user = 0;
                out.last = ((row == rows - 1) && (col == cols - 1)) ? 1 : 0;
                out.id = 0;
                out.dest = 0;

                out.data = box_sum;   out_box.write(out);
                out.data = sobel_mag; out_sobel.write(out);
                out.data = unsharp;   out_unsharp.write(out);
                out.data = high;      out_high.write(out);
                out.data = low_sum;   out_low.write(out);
            }
        }
    }
}
