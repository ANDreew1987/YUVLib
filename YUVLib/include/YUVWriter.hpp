#ifndef YUV_WRITER_H
#define YUV_WRITER_H

#include <fstream>
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUVWriter {
	private:
		std::ofstream m_stream;
	public:
		YUVWriter() {};
		~YUVWriter();
		bool Open(const char *file);
		void Close();
		YUVWriter &operator << (const YUVFrame *frame);
	};

}

#endif