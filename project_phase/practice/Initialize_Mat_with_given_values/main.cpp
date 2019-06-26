#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat test = (cv::Mat_<char>(3, 3) <<
	0, 4, 0,
	2, 4, 2,
	2, 4, 0);

int main(int argc, char** argv)
{
	//Access single pixel:
	std::cout << test.at<char>(0, 1) + 48 << std::endl;

	//Print out the hole matrix
	std::cout << test << std::endl;

	return 0;
}