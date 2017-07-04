#include "YUVConverter.hpp"
#include "YUVSTDConverter.hpp"
#include "YUVAVXConverter.hpp"
#include "YUVAVXMTConverter.hpp"

namespace YUVLib {

	static YUVConverter *converter = nullptr;

	YUVConverter* GetConverter(){
		if (converter == nullptr)
			//converter = new YUVSTDConverter;
			//converter = new YUVAVXConverter;
			converter = new YUVAVXMTConverter;
		return converter;
	}
}