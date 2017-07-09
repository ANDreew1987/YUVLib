#include <iostream>
#include <cstring>
#include "YUVLib.hpp"

using namespace YUVLib;

const char *help = "Use -format [format] -size [width] [height] [in.yuv] [in.bmp] [out.yuv]\nFormats: yuv420 yuyv422";

int main(int argc, char *argv[]){

	if (argc < 9) {
		std::cout << help << std::endl;
		return EXIT_FAILURE;
	}
	if (strcmp("-format", argv[1]) != 0) {
		std::cout << help << std::endl;
		return EXIT_FAILURE;
	}

	YUVFrame *bmpFrame, *currentFrame;
	if (strcmp("yuv420", argv[2]) == 0) {
		bmpFrame = new YUV420Frame();
		currentFrame = new YUV420Frame();
	}
	else if (strcmp("yuyv422", argv[2]) == 0) {
		bmpFrame = new YUYV422Frame();
		currentFrame = new YUYV422Frame();
	}
	else {
		std::cout << help << std::endl;
		return EXIT_FAILURE;
	}

	int width = 0, height = 0;
	width = atoi(argv[4]);
	height = atoi(argv[5]);
	if (width == 0 || height == 0) {
		std::cout << help << std::endl;
		delete bmpFrame;
		delete currentFrame;
		return EXIT_FAILURE;
	}

	currentFrame->Create(width, height);

	Bitmap bmp;
	if (!bmp.Load(argv[7])) {
		std::cout << "Could not open image" << std::endl;
		delete bmpFrame;
		delete currentFrame;
		return EXIT_FAILURE;
	}

	YUVReader reader;
	if (!reader.Open(argv[6], width, height, bmpFrame->GetFormat())) {
		std::cout << "Could not open input" << std::endl;
		delete bmpFrame;
		delete currentFrame;
		return EXIT_FAILURE;
	}

	YUVWriter writer;
	if (!writer.Open(argv[8])) {
		std::cout << "Could not open output" << std::endl;
		delete bmpFrame;
		delete currentFrame;
		return EXIT_FAILURE;
	}

	bmpFrame->Create(bmp.GetWidth(), bmp.GetHeight());
	bmp.FlipHorizontal();
	RGBToYUV420_BT709_AVX_ST(bmpFrame, &bmp);

	for (uint32_t i = 0; i < reader.GetFramesCount(); i++) {
		reader >> currentFrame;
		currentFrame->AddOvelayFrame(
			bmpFrame,
			currentFrame->GetWidth() - bmpFrame->GetWidth() - 10,
			currentFrame->GetHeight() - bmpFrame->GetHeight() - 10
		);
		writer << currentFrame;
	}

	reader.Close();
	writer.Close();
	delete bmpFrame;
	delete currentFrame;

    return EXIT_SUCCESS;
}

