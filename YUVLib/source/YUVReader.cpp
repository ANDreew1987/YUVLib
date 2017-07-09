#include "YUVReader.hpp"

namespace YUVLib {

	static uint32_t GetFrameSize(const uint32_t width, const uint32_t height, const YUVFormat format) {
		return width * height * GetBitsCount(format) / 8;
	}

	YUVReader::~YUVReader() {
		Close();
	}

	bool YUVReader::Open(const char *file, const uint32_t width, const uint32_t height, const YUVFormat format) {
        if(Open(file)){
            SetFrameParams(width, height, format);
            return true;
        }
        return false;
	}

    bool YUVReader::Open(const char *file){
        m_stream.open(file, std::ios_base::binary);
        if (!m_stream.is_open())
            return false;
        return true;
    }

    void YUVReader::SetFrameParams(const uint32_t width, const uint32_t height, const YUVFormat format){
        m_width = width;
        m_height = height;
        m_format = format;
        m_stream.seekg(0, std::ios_base::end);
        uint32_t realSize = (uint32_t) m_stream.tellg();
        m_stream.seekg(0, std::ios_base::beg);
        m_framesCount = realSize / GetFrameSize(m_width, m_height, m_format);
    }

	void YUVReader::Close() {
		if (m_stream.is_open())
			m_stream.close();
	}

	bool YUVReader::End() {
		return m_stream.eof();
	}

	void YUVReader::MoveToFrame(uint32_t frameIndex) {
        m_currentFrame = frameIndex;
        if (m_currentFrame < m_framesCount) {
			m_stream.seekg(frameIndex * GetFrameSize(m_width, m_height, m_format));
		}
	}

	YUVReader &YUVReader::operator>>(YUVFrame *result) {
		m_stream.read((char *)result->Data(), result->GetSize());
		return *this;
	}

}
