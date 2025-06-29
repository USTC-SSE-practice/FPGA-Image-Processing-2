// multi_filter.h
#ifndef MULTI_FILTER_H
#define MULTI_FILTER_H

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

#define IMG_ROWS 128
#define IMG_COLS 128

typedef ap_axiu<8,1,1,1> pixel_t;

void multi_filter_top(hls::stream<pixel_t> &in_stream,
                      hls::stream<pixel_t> &out_box,
                      hls::stream<pixel_t> &out_sobel,
                      hls::stream<pixel_t> &out_unsharp,
                      hls::stream<pixel_t> &out_high,
                      hls::stream<pixel_t> &out_low,
                      int rows,
                      int cols);

#endif