#include <thread>
#include "YUVConverter.hpp"

namespace YUVLib {

	void Convert(YUVFrame *frame, Bitmap *bmp, const int16_t koeff[][4], const PFNYUVCONVERTPROC converrtProc, const bool mt) {
		if (mt) {
			uint32_t nProc = std::thread::hardware_concurrency();
			std::thread *threads = new std::thread[nProc];

			if (bmp->GetWidth() % 2 != 0 || bmp->GetHeight() % 2 != 0)
				return;
			uint32_t lines = frame->GetHeight() / nProc;

			if (lines % 2 != 0) {
				lines--;
			}

			uint32_t stratLine = 0;
			for (uint32_t i = 0; i < nProc; i++) {
				if (i == nProc - 1) {
					threads[i] = std::thread(
						converrtProc, 
						frame->Data(), 
						bmp->Data(),
						koeff,
						frame->GetWidth(), 
						frame->GetHeight(),
						stratLine, 
						frame->GetHeight() - stratLine
					);
				}
				else {
					threads[i] = std::thread(
						converrtProc, 
						frame->Data(),
						bmp->Data(),
						koeff,
						frame->GetWidth(),
						frame->GetHeight(),
						stratLine, 
						lines
					);
				}
				stratLine += lines;
			}
			for (uint32_t i = 0; i < nProc; i++) {
				if (threads[i].joinable()) {
					threads[i].join();
				}
			}
			delete[] threads;
		}
		else {
			converrtProc(
				frame->Data(),
				bmp->Data(),
				koeff,
				frame->GetWidth(),
				frame->GetHeight(),
				0, 
				frame->GetHeight()
			);
		}
		
	}

}