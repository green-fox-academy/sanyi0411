#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat input = cv::imread("D:/Kepek/lowpoly.jpg");

	cv::Mat result;
	cv::Mat colorBoost;
	cv::decolor(input, result, colorBoost);

	cv::imshow("Original", input);
	cv::imshow("Result", result);
	cv::imshow("Color Boost", colorBoost);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}
