#ifndef YUV_AVX_CONVERTER_H
#define YUV_AVX_CONVERTER_H
#include "YUVConverter.hpp"

namespace YUVLib{

	class YUVAVXConverter: public YUVConverter{
	public:
		YUVFrame* RGBToYUV420(Bitmap *bmp);
	};

}

#endif

