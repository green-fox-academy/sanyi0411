#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat test = (cv::Mat_<char>(3, 3) <<
	0, 4, 0,
	2, 4, 2,
	2, 4, 0);

//////////////////////////////////////

float data[9] = {1,2,3,4,5,6,7,8,9};
cv::Mat test2 = cv::Mat(3, 3, CV_32F, data);


int main(int argc, char** argv)
{
	//Access single pixel:
	std::cout << test.at<char>(0, 1) + 48 << std::endl;

	//Print out the hole matrix
	std::cout << test << std::endl;
	std::cout << test2 << std::endl;

	return 0;
}