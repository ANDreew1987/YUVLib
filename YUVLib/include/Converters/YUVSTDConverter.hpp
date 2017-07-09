#ifndef YUV_STD_CONVERTER_H
#define YUV_STD_CONVERTER_H

#include "YUVBitmap.hpp"
#include "YUVFrame.hpp"

namespace YUVLib {

	void RGBToYUV420_STD (uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);
	void RGBToYUYV422_STD(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);

	void YUV420ToRGB_STD (uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);
	void YUYV422ToRGB_STD(uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);

}

#endif
