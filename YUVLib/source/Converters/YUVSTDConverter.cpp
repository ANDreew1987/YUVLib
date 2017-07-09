#include "Converters/YUVSTDConverter.hpp"
#include "YUVColorSpaces.hpp"

#define clip(var) ((var>=255)?255:(var<=0)?0:var)

namespace YUVLib {

	void RGBToYUV420_STD(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount) {
		const uint32_t yStride = width;
		const uint32_t uStride = width / 2;
		const uint32_t vStride = width / 2;
		const uint32_t bmpStride = width * 4;

		uint8_t *yPos = frame + yStride * startLine;
		uint8_t *uPos = frame + width * height + uStride * startLine / 2;
		uint8_t *vPos = frame + width * height + width * height / 4 + vStride * startLine / 2;
		uint8_t *bmpPos = bmp + bmpStride * startLine;

		int32_t r[2], g[2], b[2], tempY1, tempY2, tempY3, tempY4, tempU, tempV;

		for (uint32_t y = 0; y < linesCount; y += 2) {
			for (uint32_t x = 0; x < width; x += 2) {
				b[0] = *(bmpPos);
				b[1] = *(bmpPos + bmpStride); bmpPos++;
				g[0] = *(bmpPos);
				g[1] = *(bmpPos + bmpStride); bmpPos++;
				r[0] = *(bmpPos);
				r[1] = *(bmpPos + bmpStride); bmpPos++;
				bmpPos++;
				tempY1 = ((koeff[0][0] * r[0] + koeff[0][1] * g[0] + koeff[0][2] * b[0]) >> 8) + koeff[0][3];
				tempY2 = ((koeff[0][0] * r[1] + koeff[0][1] * g[1] + koeff[0][2] * b[1]) >> 8) + koeff[0][3];
				tempU =  ((koeff[1][0] * r[0] + koeff[1][1] * g[0] + koeff[1][2] * b[0]) >> 8) + koeff[1][3];
				tempU += ((koeff[1][0] * r[1] + koeff[1][1] * g[1] + koeff[1][2] * b[1]) >> 8) + koeff[1][3];
				tempV =  ((koeff[2][0] * r[0] + koeff[2][1] * g[0] + koeff[2][2] * b[0]) >> 8) + koeff[2][3];
				tempV += ((koeff[2][0] * r[1] + koeff[2][1] * g[1] + koeff[2][2] * b[1]) >> 8) + koeff[2][3];

				b[0] = *(bmpPos);
				b[1] = *(bmpPos + bmpStride); bmpPos++;
				g[0] = *(bmpPos);
				g[1] = *(bmpPos + bmpStride); bmpPos++;
				r[0] = *(bmpPos);
				r[1] = *(bmpPos + bmpStride); bmpPos++;
				bmpPos++;
				tempY3 = ((koeff[0][0] * r[0] + koeff[0][1] * g[0] + koeff[0][2] * b[0]) >> 8) + koeff[0][3];
				tempY4 = ((koeff[0][0] * r[1] + koeff[0][1] * g[1] + koeff[0][2] * b[1]) >> 8) + koeff[0][3];
				tempU += ((koeff[1][0] * r[0] + koeff[1][1] * g[0] + koeff[1][2] * b[0]) >> 8) + koeff[1][3];
				tempU += ((koeff[1][0] * r[1] + koeff[1][1] * g[1] + koeff[1][2] * b[1]) >> 8) + koeff[1][3];
				tempV += ((koeff[2][0] * r[0] + koeff[2][1] * g[0] + koeff[2][2] * b[0]) >> 8) + koeff[2][3];
				tempV += ((koeff[2][0] * r[1] + koeff[2][1] * g[1] + koeff[2][2] * b[1]) >> 8) + koeff[2][3];

				*(yPos          ) = (uint8_t)(tempY1);
				*(yPos + yStride) = (uint8_t)(tempY2); yPos++;
				*(yPos          ) = (uint8_t)(tempY3);
				*(yPos + yStride) = (uint8_t)(tempY4); yPos++;
				*uPos = (uint8_t)(tempU / 4); uPos++;
				*vPos = (uint8_t)(tempV / 4); vPos++;
			}
			yPos += yStride;
			bmpPos += bmpStride;
		}
	}

	void RGBToYUYV422_STD(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount) {

	}

	void YUV420ToRGB_STD(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount) {
		const uint32_t yStride = width;
		const uint32_t uStride = width / 2;
		const uint32_t vStride = width / 2;
		const uint32_t bmpStride = width * 4;

		uint8_t *yPos = frame + yStride * startLine;
		uint8_t *uPos = frame + width * height + uStride * startLine / 2;
		uint8_t *vPos = frame + width * height + width * height / 4 + vStride * startLine / 2;
		uint8_t *bmpPos = bmp + bmpStride * startLine;

		int16_t tempY, tempU, tempV;

		for (uint32_t y = 0; y < linesCount; y += 2) {
			for (uint32_t x = 0; x < width; x += 2) {
                tempY = *(yPos) - koeff[0][3];
                tempU = *(uPos) - koeff[1][3];
                tempV = *(vPos) - koeff[2][3];
                *(bmpPos    ) = (uint8_t)clip((koeff[0][0] * tempY + koeff[0][1] * tempU + koeff[0][2] * tempV) >> 8);
                *(bmpPos + 1) = (uint8_t)clip((koeff[1][0] * tempY + koeff[1][1] * tempU + koeff[1][2] * tempV) >> 8);
                *(bmpPos + 2) = (uint8_t)clip((koeff[2][0] * tempY + koeff[2][1] * tempU + koeff[2][2] * tempV) >> 8);
                *(bmpPos + 3) = 0;
                tempY = *(yPos + yStride) - koeff[0][3];
                *(bmpPos + bmpStride    ) = (uint8_t)clip((koeff[0][0] * tempY + koeff[0][1] * tempU + koeff[0][2] * tempV) >> 8);
                *(bmpPos + bmpStride + 1) = (uint8_t)clip((koeff[1][0] * tempY + koeff[1][1] * tempU + koeff[1][2] * tempV) >> 8);
                *(bmpPos + bmpStride + 2) = (uint8_t)clip((koeff[2][0] * tempY + koeff[2][1] * tempU + koeff[2][2] * tempV) >> 8);
				*(bmpPos + bmpStride + 3) = 0;
				bmpPos += 4;
				yPos++;

                tempY = *(yPos) - koeff[0][3];
                *(bmpPos    ) = (uint8_t)clip((koeff[0][0] * tempY + koeff[0][1] * tempU + koeff[0][2] * tempV) >> 8);
                *(bmpPos + 1) = (uint8_t)clip((koeff[1][0] * tempY + koeff[1][1] * tempU + koeff[1][2] * tempV) >> 8);
                *(bmpPos + 2) = (uint8_t)clip((koeff[2][0] * tempY + koeff[2][1] * tempU + koeff[2][2] * tempV) >> 8);
				*(bmpPos + 3) = 0;
                tempY = *(yPos + yStride) - koeff[0][3];
                *(bmpPos + bmpStride    ) = (uint8_t)clip((koeff[0][0] * tempY + koeff[0][1] * tempU + koeff[0][2] * tempV) >> 8);
                *(bmpPos + bmpStride + 1) = (uint8_t)clip((koeff[1][0] * tempY + koeff[1][1] * tempU + koeff[1][2] * tempV) >> 8);
                *(bmpPos + bmpStride + 2) = (uint8_t)clip((koeff[2][0] * tempY + koeff[2][1] * tempU + koeff[2][2] * tempV) >> 8);
				*(bmpPos + bmpStride + 3) = 0;
				bmpPos += 4;
				yPos++;
				uPos++;
				vPos++;
			}
			yPos += yStride;
			bmpPos += bmpStride;
		}
	}

	void YUYV422ToRGB_STD(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount) {

	}

}
