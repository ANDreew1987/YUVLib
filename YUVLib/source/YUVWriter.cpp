#include "YUVWriter.hpp"

namespace YUVLib {

	YUVWriter::~YUVWriter() {
		Close();
	}

	bool YUVWriter::Open(const char * file/*, const uint32 width, const uint32 height, const YUVFormats format*/) {
		stream.open(file, std::ios_base::binary);
		if (!stream.is_open())
			return false;
		/*m_width = width;
		m_height = height;
		m_format = format;*/
		return true;
	}

	void YUVWriter::Close() {
		if (stream.is_open())
			stream.close();
	}

	YUVWriter &YUVWriter::operator<<(const YUVFrame *frame) {
		stream.write((char *)frame->Data(), frame->GetSize());
		return *this;
	}

}