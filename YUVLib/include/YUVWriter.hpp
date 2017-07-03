#ifndef YUV_WRITER_H
#define YUV_WRITER_H

#include <fstream>
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUVWriter {
	private:
		/*uint32 m_width;
		uint32 m_height;
		YUVFormats m_format;*/
		std::ofstream stream;
	public:
		YUVWriter()/* : m_width(0), m_height(0), m_format(YUVFormats::UNKNOW)*/ {};
		~YUVWriter();
		bool Open(const char *file/*, const uint32 width, const uint32 height, const YUVFormats format = YUVFormats::YUV420*/);
		void Close();
		YUVWriter &operator << (const YUVFrame *frame);
	};

}

#endif