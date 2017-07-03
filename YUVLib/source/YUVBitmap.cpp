#include "YUVBitmap.hpp"
#include <FreeImage.h>
#include <cstring>

namespace YUVLib {

	static FIBITMAP *LoadImage(const char *path, int flag = 0) {
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

		fif = FreeImage_GetFileType(path);
		if (fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(path);
		if ((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)) {
			FIBITMAP *dib = FreeImage_Load(fif, path, flag);
			return dib;
		}
		return nullptr;
	}

	Bitmap::~Bitmap(){
		Free();
	}

	void Bitmap::FlipHorizontal(){
		if (data != nullptr) {
			byteData tempBitmap = new uint8[GetSize()];
			uint32 stride = GetWidth() * 4;
			byteData srcLine = data + stride * (GetHeight() - 1);
			byteData dstLine = tempBitmap;
			for (uint32 y = 0; y < GetHeight(); y++) {
				memcpy(dstLine, srcLine, stride);
				srcLine -= stride;
				dstLine += stride;
			}
			memcpy(data, tempBitmap, GetSize());
			delete[] tempBitmap;
		}
	}

	bool Bitmap::Load(const char * fileName){
		Free();
		bool result = false;
		FIBITMAP *bmp = LoadImage(fileName);
		if (bmp != nullptr) {
			m_width = FreeImage_GetWidth(bmp);
			m_height = FreeImage_GetHeight(bmp);
			FIBITMAP *rgb = FreeImage_ConvertTo32Bits(bmp);
			if (rgb != nullptr) {
				data = new uint8[GetSize()];
				memcpy(data, FreeImage_GetBits(rgb), GetSize());
				unsigned char *pos = data;
				for (int i = 0; i < m_width * m_height; i++) {
					*(pos + 3) = 0x00;
					pos += 4;
				}
				FreeImage_Unload(rgb);
				result = true;
			}
			FreeImage_Unload(bmp);
		}
		return result;
	}

	void Bitmap::Free(){
		UnlockChannels();
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
	}

	void Bitmap::LockChannels(){
		if (data != nullptr) {
			uint32 pixelsCount = GetPixelsCount();
			r = new uint8[pixelsCount];
			g = new uint8[pixelsCount];
			b = new uint8[pixelsCount];
			for (uint32 i = 0, j = 0; j < pixelsCount; i+=4, j++) {
				b[j] = data[i    ];
				g[j] = data[i + 1];
				r[j] = data[i + 2];
			}
		}
	}

	void Bitmap::UnlockChannels(){
		if (r != nullptr && g != nullptr && b != nullptr) {
			//TODO: �������� �������
			delete[] r;
			delete[] g;
			delete[] b;
			r = g = b = nullptr;
		}
	}

	void Bitmap::Create(const uint32 width, const uint32 height){
		m_width = width;
		m_height = height;
		data = new uint8[GetSize()];
	}

}