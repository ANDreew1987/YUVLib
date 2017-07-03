#ifndef YUV_FRAME_H
#define YUV_FRAME_H

#include "YUVTypes.hpp"
#include "YUVFormats.hpp"

namespace YUVLib {

	class YUVFrame {
	protected:
		uint32 m_width, m_height;
		byteData data, y, u, v;
		YUVFormats format;
		void Alloc();
	public:
		YUVFrame() : m_width(0), m_height(0), data(nullptr) {};

		void Create(const uint32 width, const uint32 height);
		void Free();

		virtual bool AddOvelayFrame(YUVFrame *overlay, const uint32 x, const uint32 y) = 0;
		virtual void LockChannels() = 0;
		virtual void UnlockChannels() = 0;

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

		byteData GetY() {
			return y;
		}
		byteData GetU() {
			return u;
		}
		byteData GetV() {
			return v;
		}
		const byteData GetY() const {
			return y;
		}
		const byteData GetU() const {
			return u;
		}
		const byteData GetV() const {
			return v;
		}

		const uint32 GetWidth() const {
			return m_width;
		}
		const uint32 GetHeight() const {
			return m_height;
		}
		const uint32 GetSize() const {
			return m_width * m_height * GetBitsCount(format) / 8;
		}
		const uint32 GetYSize() const {
			return m_width * m_height * GetYBitsCount(format) / 8;
		}
		const uint32 GetUSize() const {
			return m_width * m_height * GetUBitsCount(format) / 8;
		}
		const uint32 GetVSize() const {
			return m_width * m_height * GetVBitsCount(format) / 8;
		}
		const YUVFormats GetFormat() const {
			return format;
		}
	};

	YUVFrame* GetFrame(const YUVFormats format);

}

#endif