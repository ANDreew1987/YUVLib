#include <iostream>
#include <cstring>
#include "YUVLib.hpp"

using namespace YUVLib;

void GenerateRandomBMP(Bitmap *bmp) {
	for (uint32_t i = 0; i < bmp->GetSize(); i += 4) {
		bmp->Data()[i    ] = (uint8_t)rand() / (float)RAND_MAX * 255;
		bmp->Data()[i + 1] = (uint8_t)rand() / (float)RAND_MAX * 255;
		bmp->Data()[i + 2] = (uint8_t)rand() / (float)RAND_MAX * 255;
		bmp->Data()[i + 3] = 0;
	}
}

int main(int argc, char *argv[]) {
	if(argc < 6)
		return EXIT_FAILURE;
	uint32_t w = atoi(argv[4]);
	uint32_t h = atoi(argv[5]);

	Bitmap bmp;
	bmp.Create(w, h);
	GenerateRandomBMP(&bmp);

	YUV420Frame frameSTD, frameAVX;
	frameSTD.Create(w, h);
	frameAVX.Create(w, h);

	if (strcmp(argv[1], "yuv420") == 0) {
		if (strcmp(argv[2], "bt601") == 0) {
			if (strcmp(argv[3], "st") == 0) {
				RGBToYUV420_BT601_STD_ST(&frameSTD, &bmp);
				RGBToYUV420_BT601_AVX_ST(&frameAVX, &bmp);
			}
			else if (strcmp(argv[3], "mt") == 0) {
				RGBToYUV420_BT601_STD_MT(&frameSTD, &bmp);
				RGBToYUV420_BT601_AVX_MT(&frameAVX, &bmp);
			}
			else
				return EXIT_FAILURE;
		}
		else if (strcmp(argv[2], "bt709") == 0) {
			if (strcmp(argv[3], "st") == 0) {
				RGBToYUV420_BT709_STD_ST(&frameSTD, &bmp);
				RGBToYUV420_BT709_AVX_ST(&frameAVX, &bmp);
			}
			else if (strcmp(argv[3], "mt") == 0) {
				RGBToYUV420_BT709_STD_MT(&frameSTD, &bmp);
				RGBToYUV420_BT709_AVX_MT(&frameAVX, &bmp);
			}
			else
				return EXIT_FAILURE;
		}
		else
			return EXIT_FAILURE;
	}
	else
		return EXIT_FAILURE;

	int n = w * h + w * h / 2;
	for (int i = 0; i < n; i++)
		if(frameSTD.Data()[i] != frameAVX.Data()[i])
			return EXIT_FAILURE;

	return EXIT_SUCCESS;
}