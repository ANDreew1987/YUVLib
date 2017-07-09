#include "YUVBitmap.hpp"
#include <fstream>
#ifdef __GNUC__
#include <cstring>
#endif

namespace YUVLib {

	typedef struct tagBITMAPFILEHEADER {
		uint16_t bfType;
		uint32_t bfSize;
		uint16_t bfReserved1;
		uint16_t bfReserved2;
		uint32_t bfOffBits;
	} BITMAPFILEHEADER;

	typedef struct tagBITMAPINFOHEADER {
		uint32_t biSize;
		int32_t biWidth;
		int32_t biHeight;
		uint16_t biPlanes;
		uint16_t biBitCount;
		uint32_t biCompression;
		uint32_t biSizeImage;
		int32_t biXPelsPerMeter;
		int32_t biYPelsPerMeter;
		uint32_t biClrUsed;
		uint32_t biClrImportant;
	} BITMAPINFOHEADER;

	typedef struct tagRGBA {
		uint8_t Red;
		uint8_t Green;
		uint8_t Blue;
	} RGB;

#define BITMAP_FILEHEADER_SIZE 14
#define BITMAP_SIGNATURE 0x4D42

	Bitmap::~Bitmap(){
		Free();
	}

	void Bitmap::FlipHorizontal(){
		if (m_data != nullptr) {
			uint8_t *tempBitmap = new uint8_t[GetSize()];
			uint32_t stride = GetWidth() * 4;
			uint8_t *srcLine = m_data + stride * (GetHeight() - 1);
			uint8_t *dstLine = tempBitmap;
			for (uint32_t y = 0; y < GetHeight(); y++) {
				memcpy(dstLine, srcLine, stride);
				srcLine -= stride;
				dstLine += stride;
			}
			memcpy(m_data, tempBitmap, GetSize());
			delete[] tempBitmap;
		}
	}

	bool Bitmap::Load(const char * fileName){
		std::ifstream bmpFile (fileName, std::ios::binary | std::ios::in);

		if (bmpFile.bad()) {
			return false;
		}

		if (bmpFile.is_open() == false) {
			return false;
		}

		BITMAPFILEHEADER bmpFileHeder;
		bmpFile.read((char*)&bmpFileHeder, BITMAP_FILEHEADER_SIZE);

		if (bmpFileHeder.bfType != BITMAP_SIGNATURE) {
			return false;
		}

		BITMAPINFOHEADER bmpHeader;
		bmpFile.read((char*)&bmpHeader, sizeof(BITMAPINFOHEADER));

		bool Result = false;
		if (bmpHeader.biBitCount == 24 && bmpHeader.biCompression == 0) {

			Create(bmpHeader.biWidth, bmpHeader.biHeight);

			RGB rgb;
			for (uint32_t i = 0; i < GetSize(); i+=4) {
				bmpFile.read((char*)&rgb, sizeof(RGB));
				m_data[i    ] = rgb.Red;
				m_data[i + 1] = rgb.Green;
				m_data[i + 2] = rgb.Blue;
				m_data[i + 3] = 0;
			}
			Result = true;
		}

		bmpFile.close();
		return Result;
	}

	void Bitmap::Free(){
		if (m_data != nullptr) {
			delete[] m_data;
			m_data = nullptr;
			m_width = m_height = 0;
		}
	}

	void Bitmap::Create(const uint32_t width, const uint32_t height){
		m_width = width;
		m_height = height;
		m_data = new uint8_t[GetSize()];
	}

}