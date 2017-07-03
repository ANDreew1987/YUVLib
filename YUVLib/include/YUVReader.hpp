#ifndef YUV_READER_H
#define YUV_READER_H

#include <fstream>
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUVReader {
	private:
		uint32 m_width;
		uint32 m_height;
		uint32 framesCount;
		YUVFormats m_format;
		std::ifstream stream;
	public:
		YUVReader() : m_width(0), m_height(0), framesCount(0), m_format(YUVFormats::UNKNOW) {};
		~YUVReader();
		bool Open(const char *file, const uint32 width, const uint32 height, const YUVFormats format = YUVFormats::YUV420);
		void Close();
		uint32 GetFramesCount() const {
			return framesCount;
		}
		bool End();
		void MoveToFrame(uint32 frameIndex);
		YUVReader &operator >> (YUVFrame *result);
	};

}



#endif