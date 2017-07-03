#ifndef YUV_FORMATS_H
#define YUV_FORMATS_H
#include "YUVTypes.hpp"

namespace YUVLib {

	enum YUVFormats {
		UNKNOW = 0,
		YUV420,
		YUYV422			//YUY2
	};

	uint32 GetBitsCount (const YUVFormats format);
	uint32 GetYBitsCount(const YUVFormats format);
	uint32 GetUBitsCount(const YUVFormats format);
	uint32 GetVBitsCount(const YUVFormats format);

}

#endif