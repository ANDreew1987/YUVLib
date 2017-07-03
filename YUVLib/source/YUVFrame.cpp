#include "YUVFrame.hpp"
#include "YUV420Frame.hpp"

namespace YUVLib{

	void YUVFrame::Alloc(){
		Free();
		data = new uint8[m_width * m_height * GetBitsCount(format) / 8];
	}

	/*YUVFrame::~YUVFrame() {
		Free();
	}*/

	void YUVFrame::Create(const uint32 width, const uint32 height){
		m_width = width;
		m_height = height;
		Alloc();
	}

	void YUVFrame::Free() {
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
	}

	YUVFrame* GetFrame(const YUVFormats format){
		switch (format) {
		case YUV420:
			return new YUV420Frame();
			break;
		/*case YUYV422:
			return 16;
			break;*/
		case UNKNOW:
		default:
			return nullptr;
		}
	}

}

