#include <cstring>
#include "Frames/YUV420Frame.hpp"

namespace YUVLib {

	bool YUV420Frame::AddOvelayFrame(YUVFrame *overlay, const uint32_t x, const uint32_t y){
		if (overlay->GetFormat() != YUVFormat::YUV_FORMAT_YUV420)
			return false;
		if (overlay->GetWidth() + x > m_width || overlay->GetHeight() + y > m_height)
			return false;

		uint32_t m_width_2 = m_width / 2;
		uint32_t m_height_2 = m_height / 2;
		uint32_t src_width_2 = overlay->GetWidth() / 2;
		uint32_t src_height_2 = overlay->GetHeight() / 2;

		uint32_t m_ystride = m_width;
		uint32_t m_ustride = m_width_2;
		uint32_t m_vstride = m_width_2;
		uint32_t src_ystride = overlay->GetWidth();
		uint32_t src_ustride = src_width_2;
		uint32_t src_vstride = src_width_2;

		uint8_t *m_ystart = m_data;
		uint8_t *m_ustart = m_ystart + m_width * m_height;
		uint8_t *m_vstart = m_ustart + m_width * m_height / 4;
		uint8_t *m_ypos = m_ystart + (m_width * y + x);
		uint8_t *m_upos = m_ustart + (m_width * y / 4 + x / 2);
		uint8_t *m_vpos = m_vstart + (m_width * y / 4 + x / 2);

		uint8_t *src_ypos = overlay->Data();
		uint8_t *src_upos = src_ypos + overlay->GetWidth() * overlay->GetHeight();
		uint8_t *src_vpos = src_upos + overlay->GetWidth() * overlay->GetHeight() / 4;

		for (uint32_t i = 0; i < src_height_2; i++) {
			memcpy(m_ypos            , src_ypos              , src_ystride);
			memcpy(m_ypos + m_ystride, src_ypos + src_ystride, src_ystride);
			memcpy(m_upos, src_upos, src_ustride);
			memcpy(m_vpos, src_vpos, src_vstride);
			m_ypos += 2 * m_ystride;
			m_upos += m_ustride;
			m_vpos += m_vstride;
			src_ypos += 2 * src_ystride;
			src_upos += src_ustride;
			src_vpos += src_vstride;
		}

		return true;
	}

}


