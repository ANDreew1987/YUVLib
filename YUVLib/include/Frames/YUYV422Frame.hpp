#ifndef YUYV_422_FRAME_H
#define YUYV_422_FRAME_H

#include <cstdint>
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUYV422Frame : public YUVFrame {
	public:
		YUYV422Frame() {
			m_format = YUVFormat::YUV_FORMAT_YUYV422;
		}

		bool AddOvelayFrame(YUVFrame *overlay, const uint32_t x, const uint32_t y);

	};

}

#endif

