#include <iostream>
#include <cstring>
#include "YUVLib.hpp"

using namespace YUVLib;

int main(int argc, char *argv[]) {
	if(argc < 8)
		return EXIT_FAILURE;
	uint32_t n = atoi(argv[5]);
	uint32_t w = atoi(argv[6]);
	uint32_t h = atoi(argv[7]);
	Bitmap bmp;
	bmp.Create(w, h);
	YUV420Frame frame;
	frame.Create(w, h);
	if (strcmp(argv[1], "yuv420") == 0) {
		if (strcmp(argv[2], "bt601") == 0) {
			if (strcmp(argv[3], "std") == 0) {
				if (strcmp(argv[4], "st") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT601_STD_ST(&frame, &bmp);
				}
				else if (strcmp(argv[4], "mt") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT601_STD_MT(&frame, &bmp);
				}
				else
					return EXIT_FAILURE;
			}
			else if (strcmp(argv[3], "avx") == 0) {
				if (strcmp(argv[4], "st") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT601_AVX_ST(&frame, &bmp);
				}
				else if (strcmp(argv[4], "mt") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT601_AVX_MT(&frame, &bmp);
				}
				else
					return EXIT_FAILURE;
			}
			else
				return EXIT_FAILURE;
		}
		else if (strcmp(argv[2], "bt709") == 0) {
			if (strcmp(argv[3], "std") == 0) {
				if (strcmp(argv[4], "st") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT709_STD_ST(&frame, &bmp);
				}
				else if (strcmp(argv[4], "mt") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT709_STD_MT(&frame, &bmp);
				}
				else
					return EXIT_FAILURE;
			}
			else if (strcmp(argv[3], "avx") == 0) {
				if (strcmp(argv[4], "st") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT709_AVX_ST(&frame, &bmp);
				}
				else if (strcmp(argv[4], "mt") == 0) {
					for (uint32_t i = 0; i < n; i++)
						RGBToYUV420_BT709_AVX_MT(&frame, &bmp);
				}
				else
					return EXIT_FAILURE;
			}
			else
				return EXIT_FAILURE;
		}
		else
			return EXIT_FAILURE;
	}
	else
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}