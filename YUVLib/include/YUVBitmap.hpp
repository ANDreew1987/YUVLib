#ifndef YUV_BITMAP_H
#define YUV_BITMAP_H

#include <cstdint>

namespace YUVLib {

	class Bitmap{
	private:
		uint32_t m_width, m_height;
		uint8_t *m_data;
	public:
		Bitmap() :m_width(0), m_height(0), m_data(nullptr) {};
		~Bitmap();

		void FlipHorizontal();
		bool Load(const char *fileName);
		void Free();
		void Create(const uint32_t width, const uint32_t height);

		/*const uint8_t* operator*()const {
			return m_data;
		}
		uint8_t* operator*() {
			return m_data;
		}*/

		const uint8_t* Data()const {
			return m_data;
		}
		uint8_t* Data() {
			return m_data;
		}

		const uint32_t GetPixelSize() const {
			return 4; //RGBA
		}

		const uint32_t GetWidth() const {
			return m_width;
		}
		const uint32_t GetHeight() const {
			return m_height;
		}
		const uint32_t GetPixelsCount() const {
			return m_width * m_height;
		}
		const uint32_t GetSize() const {
			return GetPixelsCount() * GetPixelSize();
		}

	};

}

#endif





