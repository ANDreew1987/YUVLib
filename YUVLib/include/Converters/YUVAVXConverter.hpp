#ifndef YUV_AVX_CONVERTER_H
#define YUV_AVX_CONVERTER_H

#include "YUVBitmap.hpp"
#include "YUVFrame.hpp"

namespace YUVLib{

	void RGBToYUV420_AVX (uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);
	void RGBToYUYV422_AVX(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);

	void YUV420ToRGB_AVX (uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);
	void YUYV422ToRGB_AVX(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);

}

#endif

