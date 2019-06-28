#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("D:/test_pic.jpg");

	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get();
		return -1;
	}

	//Erode the image with 3x3 kernel
	cv::Mat image_eroded_with_3x3_kernel;
	erode(image, image_eroded_with_3x3_kernel, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));

	//Erode the image with 5x5 kernel
	cv::Mat image_eroded_with_5x5_kernel;
	erode(image, image_eroded_with_5x5_kernel, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)));

	imshow("Original", image);
	imshow("Eroded with 3x3 kernel", image_eroded_with_3x3_kernel);
	imshow("Eroded with 5x5 kernel", image_eroded_with_5x5_kernel);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}