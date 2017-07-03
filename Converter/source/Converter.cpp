#include <iostream>
#include <cstring>
#include "YUVLib.hpp"

//#include <intrin.h>

using namespace YUVLib;

const char *help = "Use -format [format] -size [width] [height] [in.yuv] [in.bmp] [out.yuv]\nFormats: yuv420 yuyv422";

int main(int argc, char *argv[]){

	/*unsigned __int64 t1, t2;
	Bitmap bmpTest;
	bmpTest.Create(4096, 4096);
	YUVConverter *converterTest = GetConverter();
	YUVFrame *frameTest;
	const int nIter = 50;
	t1 = __rdtsc();
	for(int i = 0; i < nIter; i++){
		frameTest = converterTest->RGBToYUV420(&bmpTest);
		frameTest.Free();
	}
	t2 = __rdtsc();
	double avg = (t2 - t1) / nIter;
	std::cout << (unsigned __int64)avg << std::endl;*/

	if (argc < 9) {
		std::cout << help << std::endl;
		return EXIT_FAILURE;
	}
	if (strcmp("-format", argv[1]) != 0) {
		std::cout << help << std::endl;
		return EXIT_FAILURE;
	}
	YUVFormats format;
	if (strcmp("yuv420", argv[2]) == 0)
		format = YUVFormats::YUV420;
	else if (strcmp("yuyv422", argv[2]) == 0)
		format = YUVFormats::YUYV422;
	else {
		std::cout << help << std::endl;
		return EXIT_FAILURE;
	}
	int width = 0, height = 0;
	width = atoi(argv[4]);
	height = atoi(argv[5]);
	if (width == 0 || height == 0) {
		std::cout << help << std::endl;
		return EXIT_FAILURE;
	}

	Bitmap bmp;
	if (!bmp.Load(argv[7])) {
		std::cout << "Could not open image" << std::endl;
		return EXIT_FAILURE;
	}

	bmp.FlipHorizontal();

	YUVReader reader;
	if (!reader.Open(argv[6], width, height, format)) {
		std::cout << "Could not open input" << std::endl;
		return EXIT_FAILURE;
	}

	YUVWriter writer;
	if (!writer.Open(argv[8])) {
		std::cout << "Could not open output" << std::endl;
		return EXIT_FAILURE;
	}

	YUVConverter *converter = GetConverter();
	YUVFrame *image = converter->RGBToYUV420(&bmp);

	YUVFrame *currentFrame = GetFrame(format);
	currentFrame->Create(width, height);

	for (int i = 0; i < reader.GetFramesCount(); i++) {
		reader >> currentFrame;
		currentFrame->AddOvelayFrame(
			image,
			currentFrame->GetWidth() - image->GetWidth() - 10,
			currentFrame->GetHeight() - image->GetHeight() - 10
		);
		writer << currentFrame;
	}

	currentFrame->Free();
	image->Free();

    return EXIT_SUCCESS;
}

