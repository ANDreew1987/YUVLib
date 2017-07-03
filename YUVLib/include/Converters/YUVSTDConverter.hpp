#ifndef YUV_STD_CONVERTER_H
#define YUV_STD_CONVERTER_H
#include "YUVConverter.hpp"

namespace YUVLib {

	class YUVSTDConverter: public YUVConverter {
	public:
		YUVFrame* RGBToYUV420(Bitmap *bmp);
	};

}

#endif
