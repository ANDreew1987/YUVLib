#ifndef YUV_CONVERTER_H
#define YUV_CONVERTER_H

#include "YUVBitmap.hpp"
#include "YUVFrame.hpp"
#include "YUVColorSpaces.hpp"

#include "Converters/YUVSTDConverter.hpp"
#include "Converters/YUVAVXConverter.hpp"

namespace YUVLib {

	typedef void(*PFNYUVCONVERTPROC) (uint8_t *frame, uint8_t *bmp, const int16_t koeff[][4], const uint32_t width, const uint32_t height, const uint32_t startLine, const uint32_t linesCount);

	void Convert(YUVFrame *frame, Bitmap *bmp, const int16_t koeff[][4], const PFNYUVCONVERTPROC converrtProc, const bool mt);

	//RGBToYUV420 BT601

	inline void RGBToYUV420_BT601_STD_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUV420_STD, false);
	}

	inline void RGBToYUV420_BT601_STD_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUV420_STD, true);
	}

	inline void RGBToYUV420_BT601_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUV420_AVX, false);
	}

	inline void RGBToYUV420_BT601_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUV420_AVX, true);
	}

	//RGBToYUV420 BT709

	inline void RGBToYUV420_BT709_STD_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUV420_STD, false);
	}

	inline void RGBToYUV420_BT709_STD_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUV420_STD, true);
	}

	inline void RGBToYUV420_BT709_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUV420_AVX, false);
	}

	inline void RGBToYUV420_BT709_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUV420_AVX, true);
	}

	//RGBToYUYV422 BT601

	inline void RGBToYUYV422_BT601_STD_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUYV422_STD, false);
	}

	inline void RGBToYUYV422_BT601_STD_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUYV422_STD, true);
	}

	inline void RGBToYUYV422_BT601_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUYV422_AVX, false);
	}

	inline void RGBToYUYV422_BT601_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT601, RGBToYUYV422_AVX, true);
	}

	//RGBToYUYV422 BT709

	inline void RGBToYUYV422_BT709_STD_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUYV422_STD, false);
	}

	inline void RGBToYUYV422_BT709_STD_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUYV422_STD, true);
	}

	inline void RGBToYUYV422_BT709_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUYV422_AVX, false);
	}

	inline void RGBToYUYV422_BT709_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
		Convert(frame, bmp, BT709, RGBToYUYV422_AVX, true);
	}

	//YUV420ToRGB BT601

	inline void YUV420ToRGB_BT601_STD_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUV420ToRGB_STD, false);
	}

	inline void YUV420ToRGB_BT601_STD_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUV420ToRGB_STD, true);
	}

	inline void YUV420ToRGB_BT601_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUV420ToRGB_AVX, false);
	}

	inline void YUV420ToRGB_BT601_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUV420ToRGB_AVX, true);
	}

	//YUV420ToRGB BT709

	inline void YUV420ToRGB_BT709_STD_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUV420ToRGB_STD, false);
	}

	inline void YUV420ToRGB_BT709_STD_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUV420ToRGB_STD, true);
	}

	inline void YUV420ToRGB_BT709_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUV420ToRGB_AVX, false);
	}

	inline void YUV420ToRGB_BT709_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUV420ToRGB_AVX, true);
	}

	//YUYV422ToRGB BT601

	inline void YUYV422ToRGB_BT601_STD_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUYV422ToRGB_STD, false);
	}

	inline void YUYV422ToRGB_BT601_STD_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUYV422ToRGB_STD, true);
	}

	inline void YUYV422ToRGB_BT601_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUYV422ToRGB_AVX, false);
	}

	inline void YUYV422ToRGB_BT601_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT601_RGB, YUYV422ToRGB_AVX, true);
	}

	//YUYV422ToRGB BT709

	inline void YUYV422ToRGB_BT709_STD_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUYV422ToRGB_STD, false);
	}

	inline void YUYV422ToRGB_BT709_STD_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUYV422ToRGB_STD, true);
	}

	inline void YUYV422ToRGB_BT709_AVX_ST(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUYV422ToRGB_AVX, false);
	}

	inline void YUYV422ToRGB_BT709_AVX_MT(YUVFrame *frame, Bitmap *bmp) {
        Convert(frame, bmp, BT709_RGB, YUYV422ToRGB_AVX, true);
	}

}

#endif
