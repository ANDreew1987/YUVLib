#include "Frames/YUYV422Frame.hpp"

namespace YUVLib {

	bool YUYV422Frame::AddOvelayFrame(YUVFrame *overlay, const uint32_t x, const uint32_t y) {
		if (overlay->GetFormat() != YUVFormat::YUV_FORMAT_YUV420)
			return false;
		if (overlay->GetWidth() + x > m_width || overlay->GetHeight() + y > m_height)
			return false;

		return true;
	}

}


