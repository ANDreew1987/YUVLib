#ifndef YUV_READER_H
#define YUV_READER_H

#include <cstdint>
#include <fstream>
#include "YUVFrame.hpp"

namespace YUVLib {

	class YUVReader {
	private:
		uint32_t m_width;
		uint32_t m_height;
		uint32_t m_framesCount;
        uint32_t m_currentFrame;
		YUVFormat m_format;
		std::ifstream m_stream;
	public:
        YUVReader() : m_width(0), m_height(0), m_framesCount(0), m_currentFrame(0), m_format(YUVFormat::YUV_FORMAT_UNKNOWN) {};
		~YUVReader();
		bool Open(const char *file, const uint32_t width, const uint32_t height, const YUVFormat format = YUVFormat::YUV_FORMAT_YUV420);
        bool Open(const char *file);
        void SetFrameParams(const uint32_t width, const uint32_t height, const YUVFormat format = YUVFormat::YUV_FORMAT_YUV420);
		void Close();
		uint32_t GetFramesCount() const {
			return m_framesCount;
		}

        uint32_t GetCurrentFrameNumber(){
            return m_currentFrame;
        }

        void MoveToPrevFrame(){
            if(m_currentFrame > 0){
                m_currentFrame--;
                MoveToFrame(m_currentFrame);
            }
        }

        void MoveToNextFrame(){
            if(m_currentFrame < m_framesCount){
                m_currentFrame++;
                MoveToFrame(m_currentFrame);
            }
        }

		bool End();
		void MoveToFrame(uint32_t frameIndex);
		YUVReader &operator >> (YUVFrame *result);
	};

}



#endif
