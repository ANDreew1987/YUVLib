#ifndef YUV_420_FRAME_H
#define YUV_420_FRAME_H

#include <cstdint>
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUV420Frame: public YUVFrame{
	public:
		YUV420Frame() {
			m_format = YUVFormat::YUV_FORMAT_YUV420;
		}

		bool AddOvelayFrame(YUVFrame *overlay, const uint32_t x, const uint32_t y);

	};

}

#endif

