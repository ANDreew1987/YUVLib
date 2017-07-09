#include "YUVFrame.hpp"

namespace YUVLib{

	void YUVFrame::Alloc(){
		Free();
		m_data = new uint8_t[m_width * m_height * GetBitsCount(m_format) / 8];
	}

	YUVFrame::~YUVFrame() {
		Free();
	}

	void YUVFrame::Create(const uint32_t width, const uint32_t height){
		m_width = width;
		m_height = height;
		Alloc();
	}

	void YUVFrame::Free() {
		if (m_data != nullptr) {
			delete[] m_data;
			m_data = nullptr;
		}
	}

}

