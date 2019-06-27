#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	cv::Mat image = cv::imread("D:/Kepek/Minion.jpg");
	cv::Mat inverted;

	cv::bitwise_not(image, inverted);

	cv::imshow("Original", image);
	cv::imshow("Inverted", inverted);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;

}