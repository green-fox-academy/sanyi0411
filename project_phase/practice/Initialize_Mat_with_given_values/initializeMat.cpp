#include <iostream>
#include <opencv2\opencv.hpp>  

int main()
{
	cv::Mat test = (cv::Mat_<char>(3, 3) <<
		0, 4, 0,
		2, 4, 2,
		2, 4, 0);

	std::cout << test;
	
	return 0;
}