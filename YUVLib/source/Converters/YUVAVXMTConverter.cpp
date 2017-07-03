#include "YUVAVXMTConverter.hpp"

namespace YUVLib {

	

	void YUVAVXMTConverter::threadProc(){

	}

	YUVAVXMTConverter::YUVAVXMTConverter(){
		nProc = std::thread::hardware_concurrency();
		threads = new std::thread[nProc];
	}

	YUVFrame * YUVAVXMTConverter::RGBToYUV420(Bitmap * bmp){
		for (int i = 0; i < nProc; i++) {
			//threads[i] = std::thread(threadProc);
		}
		for (int i = 0; i < nProc; i++) {
			if (threads[i].joinable()) {
				threads[i].join();
			}
		}
		return nullptr;
	}

}