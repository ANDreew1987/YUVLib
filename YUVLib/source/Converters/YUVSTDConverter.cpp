#include "YUVSTDConverter.hpp"
//#include "YUV420Frame.h"

namespace YUVLib {

	YUVFrame* YUVSTDConverter::RGBToYUV420(Bitmap *bmp){
		if (bmp->GetWidth() % 2 != 0 || bmp->GetHeight() % 2 != 0)
			return nullptr;
		YUVFrame *frame = GetFrame(YUVFormats::YUV420);
		//YUV420Frame *frame = new YUV420Frame();
		frame->Create(bmp->GetWidth(), bmp->GetHeight());
		frame->LockChannels();
		uint8 *currentYLine = frame->GetY();
		uint8 *uPos         = frame->GetU();
		uint8 *vPos         = frame->GetV();
		bmp->LockChannels();
		uint8 *currentRLine = bmp->GetR();
		uint8 *currentGLine = bmp->GetG();
		uint8 *currentBLine = bmp->GetB();
		uint32 yStride = frame->GetWidth();
		uint32 rgbStride = yStride;
		uint8 *rPos, *gPos, *bPos, *yPos;
		int32 r[2], g[2], b[2], tempY1, tempY2, tempY3, tempY4, tempU, tempV;
		for (uint32 y = 0; y < frame->GetHeight(); y += 2) {
			rPos = currentRLine;
			gPos = currentGLine;
			bPos = currentBLine;
			yPos = currentYLine;
			for (uint32 x = 0; x < frame->GetWidth(); x += 2) {
				r[0] = *(rPos);
				r[1] = *(rPos + rgbStride); rPos++;
				g[0] = *(gPos);
				g[1] = *(gPos + rgbStride); gPos++;
				b[0] = *(bPos);
				b[1] = *(bPos + rgbStride); bPos++;
				tempY1 = ((66 * r[0] + 129 * g[0] + 25 * b[0] + 128) >> 8) + 16;
				tempY2 = ((66 * r[1] + 129 * g[1] + 25 * b[1] + 128) >> 8) + 16;
				tempU = ((-38 * r[0] - 74 * g[0] + 112 * b[0] + 128) >> 8) + 128;
				tempU += ((-38 * r[1] - 74 * g[1] + 112 * b[1] + 128) >> 8) + 128;
				tempV = ((112 * r[0] - 94 * g[0] - 18 * b[0] + 128) >> 8) + 128;
				tempV += ((112 * r[1] - 94 * g[1] - 18 * b[1] + 128) >> 8) + 128;

				r[0] = *(rPos);
				r[1] = *(rPos + rgbStride); rPos++;
				g[0] = *(gPos);
				g[1] = *(gPos + rgbStride); gPos++;
				b[0] = *(bPos);
				b[1] = *(bPos + rgbStride); bPos++;
				tempY3 = ((66 * r[0] + 129 * g[0] + 25 * b[0] + 128) >> 8) + 16;
				tempY4 = ((66 * r[1] + 129 * g[1] + 25 * b[1] + 128) >> 8) + 16;
				tempU += ((-38 * r[0] - 74 * g[0] + 112 * b[0] + 128) >> 8) + 128;
				tempU += ((-38 * r[1] - 74 * g[1] + 112 * b[1] + 128) >> 8) + 128;
				tempV += ((112 * r[0] - 94 * g[0] - 18 * b[0] + 128) >> 8) + 128;
				tempV += ((112 * r[1] - 94 * g[1] - 18 * b[1] + 128) >> 8) + 128;

				*(yPos) = (uint8)(tempY1);
				*(yPos + yStride) = (uint8)(tempY2); yPos++;
				*(yPos) = (uint8)(tempY3);
				*(yPos + yStride) = (uint8)(tempY4); yPos++;
				*uPos = (uint8)(tempU / 4); uPos++;
				*vPos = (uint8)(tempV / 4); vPos++;
				
			}
			currentRLine += 2 * rgbStride;
			currentGLine += 2 * rgbStride;
			currentBLine += 2 * rgbStride;
			currentYLine += 2 * yStride;
		}
		bmp->UnlockChannels();
		frame->UnlockChannels();
		return frame;
	}

}