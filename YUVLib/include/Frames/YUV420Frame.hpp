#ifndef YUV_420_H
#define YUV_420_H
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUV420Frame: public YUVFrame{
	public:
		YUV420Frame() {
			format = YUVFormats::YUV420;
		}

		bool AddOvelayFrame(YUVFrame *overlay, const uint32 x, const uint32 y);
		void LockChannels();
		void UnlockChannels();

	};

}

#endif

