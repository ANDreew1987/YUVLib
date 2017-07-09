#ifndef YUV_FRAME_H
#define YUV_FRAME_H

#include "YUVFormats.hpp"

namespace YUVLib {

	class YUVFrame {
	protected:
		uint32_t m_width, m_height;
		uint8_t *m_data;
		YUVFormat m_format;
		void Alloc();
	public:
		YUVFrame() : m_width(0), m_height(0), m_data(nullptr) {};
		~YUVFrame();

		void Create(const uint32_t width, const uint32_t height);
		void Free();

		virtual bool AddOvelayFrame(YUVFrame *overlay, const uint32_t x, const uint32_t y) = 0;

        const uint8_t *operator*()const {
			return m_data;
		}
		uint8_t *operator*() {
			return m_data;
        }

		const uint8_t *Data()const {
			return m_data;
		}
		uint8_t *Data() {
			return m_data;
		}

		const uint32_t GetWidth() const {
			return m_width;
		}
		const uint32_t GetHeight() const {
			return m_height;
		}
		const uint32_t GetSize() const {
			return m_width * m_height * GetBitsCount(m_format) / 8;
		}
		const uint32_t GetYSize() const {
			return m_width * m_height * GetYBitsCount(m_format) / 8;
		}
		const uint32_t GetUSize() const {
			return m_width * m_height * GetUBitsCount(m_format) / 8;
		}
		const uint32_t GetVSize() const {
			return m_width * m_height * GetVBitsCount(m_format) / 8;
		}
		const YUVFormat GetFormat() const {
			return m_format;
		}
	};

}

#endif
