#ifndef YUV_COLOR_SPACES_H
#define YUV_COLOR_SPACES_H
#include <cstdint>

namespace YUVLib {

	enum YUVColorSpaces {
		YUV_COLOR_SPACE_UNKNOW = 0,
		YUV_COLOR_SPACE_BT601,
		YUV_COLOR_SPACE_BT709
	};

	const float BT601_f[3][3] = {
		{ 0.257f,  0.504f,  0.098f},
		{-0.148f, -0.291f,  0.439f},
		{ 0.439f, -0.368f, -0.071f}
	};

	const float BT709_f[3][3] = {
		{ 0.183f,  0.614f,  0.062f},
		{-0.101f, -0.339f,  0.439f},
		{ 0.439f, -0.399f, -0.040f}
	};

	const float BT601_RGB_f[3][3] = {
		{ 1.164f,  0.000f,  1.596f },
		{ 1.164f, -0.392f, -0.813f },
		{ 1.164f,  2.017f,  0.000f }
	};

	const float BT709_RGB_f[3][3] = {
		{ 1.164f,  0.000f,  1.793f },
		{ 1.164f, -0.213f, -0.533f },
		{ 1.164f,  2.112f,  0.000f }
	};

	const int16_t BT601[3][4] = {
		{
			int16_t(BT601_f[0][0] * (1 << 8)),
			int16_t(BT601_f[0][1] * (1 << 8)),
			int16_t(BT601_f[0][2] * (1 << 8)),
									 1 << 4
		},
		{
			int16_t(BT601_f[1][0] * (1 << 8)),
			int16_t(BT601_f[1][1] * (1 << 8)),
			int16_t(BT601_f[1][2] * (1 << 8)),
									 1 << 7
		},
		{
			int16_t(BT601_f[2][0] * (1 << 8)),
			int16_t(BT601_f[2][1] * (1 << 8)),
			int16_t(BT601_f[2][2] * (1 << 8)),
									 1 << 7
		}
	};

	const int16_t BT709[3][4] = {
		{
			int16_t(BT709_f[0][0] * (1 << 8)),
			int16_t(BT709_f[0][1] * (1 << 8)),
			int16_t(BT709_f[0][2] * (1 << 8)),
									 1 << 4
		},
		{
			int16_t(BT709_f[1][0] * (1 << 8)),
			int16_t(BT709_f[1][1] * (1 << 8)),
			int16_t(BT709_f[1][2] * (1 << 8)),
									 1 << 7
		},
		{
			int16_t(BT709_f[2][0] * (1 << 8)),
			int16_t(BT709_f[2][1] * (1 << 8)),
			int16_t(BT709_f[2][2] * (1 << 8)),
									 1 << 7
		}
	};

	const int16_t BT601_RGB[3][4] = {
		{
			int16_t(BT601_RGB_f[0][0] * (1 << 8)),
			int16_t(BT601_RGB_f[0][1] * (1 << 8)),
			int16_t(BT601_RGB_f[0][2] * (1 << 8)),
										 1 << 4
		},
		{
			int16_t(BT601_RGB_f[1][0] * (1 << 8)),
			int16_t(BT601_RGB_f[1][1] * (1 << 8)),
			int16_t(BT601_RGB_f[1][2] * (1 << 8)),
										 1 << 7
		},
		{
			int16_t(BT601_RGB_f[2][0] * (1 << 8)),
			int16_t(BT601_RGB_f[2][1] * (1 << 8)),
			int16_t(BT601_RGB_f[2][2] * (1 << 8)),
										 1 << 7
		}
	};

	const int16_t BT709_RGB[3][4] = {
		{
			int16_t(BT709_RGB_f[0][0] * (1 << 8)),
			int16_t(BT709_RGB_f[0][1] * (1 << 8)),
			int16_t(BT709_RGB_f[0][2] * (1 << 8)),
										 1 << 4
		},
		{
			int16_t(BT709_RGB_f[1][0] * (1 << 8)),
			int16_t(BT709_RGB_f[1][1] * (1 << 8)),
			int16_t(BT709_RGB_f[1][2] * (1 << 8)),
										 1 << 7
		},
		{
			int16_t(BT709_RGB_f[2][0] * (1 << 8)),
			int16_t(BT709_RGB_f[2][1] * (1 << 8)),
			int16_t(BT709_RGB_f[2][2] * (1 << 8)),
										 1 << 7
		}
	};

}

#endif