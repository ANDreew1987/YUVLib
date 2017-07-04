#ifndef YUV_AVX_MT_CONVERTER
#define YUV_AVX_MT_CONVERTER
#include "YUVConverter.hpp"
#include <thread>

namespace YUVLib {

	class YUVAVXMTConverter: public YUVConverter{
	private:
		uint32 nProc;
		std::thread *threads;
		//void threadProc(Bitmap * bmp, YUVFrame *frame, const uint32 offsetY, const uint32 linesCount);
	public:
		YUVAVXMTConverter();
		YUVFrame* RGBToYUV420(Bitmap *bmp);
	};

}

#endif