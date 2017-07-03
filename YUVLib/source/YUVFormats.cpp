#include "YUVFormats.hpp"

namespace YUVLib {

	uint32 GetBitsCount(const YUVFormats format) {
		switch (format) {
		case YUV420:
			return 12;
			break;
		case YUYV422:
			return 16;
			break;
		case UNKNOW:
		default:
			return 0;
		}
	}

	uint32 GetYBitsCount(const YUVFormats format) {
		switch (format) {
		case YUV420:
			return 8;
			break;
		case YUYV422:
			return 8;
			break;
		case UNKNOW:
		default:
			return 0;
		}
	}

	uint32 GetUBitsCount(const YUVFormats format) {
		switch (format) {
		case YUV420:
			return 2;
			break;
		case YUYV422:
			return 2;
			break;
		case UNKNOW:
		default:
			return 0;
		}
	}

	uint32 GetVBitsCount(const YUVFormats format) {
		switch (format) {
		case YUV420:
			return 2;
			break;
		case YUYV422:
			return 2;
			break;
		case UNKNOW:
		default:
			return 0;
		}
	}

}