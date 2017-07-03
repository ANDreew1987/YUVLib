#ifndef YUV_BITMAP_H
#define YUV_BITMAP_H
#include "YUVTypes.hpp"

namespace YUVLib {

	class Bitmap{
	private:
		uint32 m_width, m_height;
		byteData data, r, g, b;
	public:
		Bitmap() :m_width(0), m_height(0), data(nullptr), r(nullptr), g(nullptr), b(nullptr) {};
		~Bitmap();

		void FlipHorizontal();
		bool Load(const char *fileName);
		void Free();
		void LockChannels();
		void UnlockChannels();
		void Create(const uint32 width, const uint32 height);

		const byteData operator*()const {
			return data;
		}
		byteData operator*() {
			return data;
		}

		const byteData Data()const {
			return data;
		}
		byteData Data() {
			return data;
		}

		byteData GetR() {
			return r;
		}
		byteData GetG() {
			return g;
		}
		byteData GetB() {
			return b;
		}
		const uint32 GetPixelSize() const {
			return 4;
		}

		const byteData GetR() const {
			return r;
		}
		const byteData GetG() const {
			return g;
		}
		const byteData GetB() const {
			return b;
		}

		const uint32 GetWidth() const {
			return m_width;
		}
		const uint32 GetHeight() const {
			return m_height;
		}
		const uint32 GetPixelsCount() const {
			return m_width * m_height;
		}
		const uint32 GetSize() const {
			return GetPixelsCount() * GetPixelSize();
		}

	};

}

#endif





