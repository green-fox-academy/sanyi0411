#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("D:/Kepek/FB_IMG_1483277797808.jpg");

	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get(); 
		return -1;
	}

	cv::Mat imageContrastHigh2;
	image.convertTo(imageContrastHigh2, -1, 2, 0); //increase the contrast by 2

	cv::Mat imageContrastHigh4;
	image.convertTo(imageContrastHigh4, -1, 4, 0); //increase the contrast by 4

	cv::Mat imageContrastLow0_5;
	image.convertTo(imageContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

	cv::Mat imageContrastLow0_25;
	image.convertTo(imageContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25

	cv::String windowNameOriginalImage = "Original Image";
	cv::String windowNameContrastHigh2 = "Contrast Increased by 2";
	cv::String windowNameContrastHigh4 = "Contrast Increased by 4";
	cv::String windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
	cv::String windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

	cv::namedWindow(windowNameOriginalImage, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastHigh2, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastHigh4, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastLow0_5, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameContrastLow0_25, cv::WINDOW_NORMAL);

	imshow(windowNameOriginalImage, image);
	imshow(windowNameContrastHigh2, imageContrastHigh2);
	imshow(windowNameContrastHigh4, imageContrastHigh4);
	imshow(windowNameContrastLow0_5, imageContrastLow0_5);
	imshow(windowNameContrastLow0_25, imageContrastLow0_25);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}