#ifndef YUV_CONVERTER_H
#define YUV_CONVERTER_H
#include "YUVBitmap.hpp"
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUVConverter {
	public:
		virtual YUVFrame* RGBToYUV420(Bitmap *bmp) = 0;
	};

	YUVConverter* GetConverter();

}

#endif
