#include "YUVReader.hpp"

namespace YUVLib {

	/*static uint32 GetFrameSize(const uint32 width, const uint32 height, const YUVFormats format) {
		return width * height * GetBitsCount(format) / 8;
	}*/

	YUVReader::~YUVReader() {
		Close();
	}

	bool YUVReader::Open(const char *file, const uint32 width, const uint32 height, const YUVFormats format) {
		stream.open(file, std::ios_base::binary);
		if (!stream.is_open())
			return false;
		m_width = width;
		m_height = height;
		m_format = format;
		stream.seekg(0, std::ios_base::end);
		size_t realSize = stream.tellg();
		stream.seekg(0, std::ios_base::beg);
		framesCount = realSize / m_width * m_height * GetBitsCount(m_format) / 8;
		return true;
	}

	void YUVReader::Close() {
		if (stream.is_open())
			stream.close();
	}

	bool YUVReader::End() {
		return stream.eof();
	}

	void YUVReader::MoveToFrame(uint32 frameIndex) {
		if (frameIndex < framesCount) {
			stream.seekg(frameIndex * m_width * m_height * GetBitsCount(m_format) / 8);
		}
	}

	YUVReader &YUVReader::operator>>(YUVFrame *result) {
		stream.read((char *)result->Data(), result->GetSize());
		return *this;
	}

}