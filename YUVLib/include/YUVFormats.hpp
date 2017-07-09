#ifndef YUV_FORMATS_H
#define YUV_FORMATS_H

#include <cstdint>

namespace YUVLib {

	enum YUVFormat {
		YUV_FORMAT_UNKNOWN = 0,
		YUV_FORMAT_YUV420,
		YUV_FORMAT_YUYV422
	};

	static uint32_t GetBitsCount(const YUVFormat format) {
		switch (format) {
		case YUV_FORMAT_YUV420:
			return 12;
			break;
		case YUV_FORMAT_YUYV422:
			return 16;
			break;
		case YUV_FORMAT_UNKNOWN:
		default:
			return 0;
		}
	}

	static uint32_t GetYBitsCount(const YUVFormat format) {
		switch (format) {
		case YUV_FORMAT_YUV420:
			return 8;
			break;
		case YUV_FORMAT_YUYV422:
			return 8;
			break;
		case YUV_FORMAT_UNKNOWN:
		default:
			return 0;
		}
	}

	static uint32_t GetUBitsCount(const YUVFormat format) {
		switch (format) {
		case YUV_FORMAT_YUV420:
			return 2;
			break;
		case YUV_FORMAT_YUYV422:
			return 2;
			break;
		case YUV_FORMAT_UNKNOWN:
		default:
			return 0;
		}
	}

	static uint32_t GetVBitsCount(const YUVFormat format) {
		switch (format) {
		case YUV_FORMAT_YUV420:
			return 2;
			break;
		case YUV_FORMAT_YUYV422:
			return 2;
			break;
		case YUV_FORMAT_UNKNOWN:
		default:
			return 0;
		}
	}

}

#endif