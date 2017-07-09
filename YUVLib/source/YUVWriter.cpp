#include "YUVWriter.hpp"

namespace YUVLib {

	YUVWriter::~YUVWriter() {
		Close();
	}

	bool YUVWriter::Open(const char * file) {
		m_stream.open(file, std::ios_base::binary);
		if (!m_stream.is_open())
			return false;
		return true;
	}

	void YUVWriter::Close() {
		if (m_stream.is_open())
			m_stream.close();
	}

	YUVWriter &YUVWriter::operator<<(const YUVFrame *frame) {
		m_stream.write((char *)frame->Data(), frame->GetSize());
		return *this;
	}

}