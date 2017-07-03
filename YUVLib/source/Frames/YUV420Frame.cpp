#include "../../include/Frames/YUV420Frame.hpp"
#include <cstring>

namespace YUVLib {

	bool YUV420Frame::AddOvelayFrame(YUVFrame *overlay, const uint32 x, const uint32 y){
		if (overlay->GetFormat() != YUVFormats::YUV420)
			return false;
		if (overlay->GetWidth() + x > m_width || overlay->GetHeight() + y > m_height)
			return false;

		uint32 yStride = m_width;
		uint32 uStride = m_width / 2;
		uint32 vStride = uStride;
		LockChannels();
		uint8 *yPos = GetY() + y * m_width + x;
		uint8 *uPos = GetU() + y / 2 * m_width / 2 + x / 2;
		uint8 *vPos = GetV() + y / 2 * m_width / 2 + x / 2;

		uint32 srcYStride = overlay->GetWidth();
		uint32 srcUStride = overlay->GetWidth() / 2;
		uint32 srcVStride = srcUStride;
		overlay->LockChannels();
		uint8 *srcYPos = overlay->GetY();
		uint8 *srcUPos = overlay->GetU();
		uint8 *srcVPos = overlay->GetV();

		for (uint32 i = 0; i < overlay->GetHeight() / 2; i++) {
			memcpy(yPos          , srcYPos             , srcYStride);
			memcpy(yPos + yStride, srcYPos + srcYStride, srcYStride);
			memcpy(uPos, srcUPos, srcUStride);
			memcpy(vPos, srcVPos, srcVStride);

			yPos += 2 * yStride;
			uPos += uStride;
			vPos += vStride;
			srcYPos += 2 * srcYStride;
			srcUPos += srcUStride;
			srcVPos += srcVStride;
		}

		overlay->UnlockChannels();
		UnlockChannels();
		return true;
	}

	void YUV420Frame::LockChannels(){
		y = data;
		u = data + m_width * m_height;
		v = u + m_width * m_height / 4;
	}

	void YUV420Frame::UnlockChannels(){
		y = u = v = nullptr;
	}

}


