#include <opencv2/opencv.hpp>
#include <iostream>
#include <time.h>

cv::Mat salt(cv::Mat input, int parameter);

int main(int argc, char** argv)
{
	srand(time(NULL));

	cv::Mat picture = cv::imread("D:/Kepek/lowpoly.jpg", 1);

	cv::Mat result = salt(picture, 100);

	cv::imshow("Result", result);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}

cv::Mat salt(cv::Mat input, int parameter)
{
	//parameter should be 0-100

	cv::Mat result(input); //clone Mat

	int pixels = input.total();

	//parameter defines how many % of the image should be salty
	int i, j;
	for (int k = 0; k < (pixels * parameter / 50); ++k) {
		i = rand() % result.rows;
		j = rand() % result.cols;

		if (result.type() == CV_8UC1 && result.at<char>(i, j) != 255) { 
			result.at<char>(i, j) = 255;
		}
		else if (result.type() == CV_8UC3 && result.at<cv::Vec3b>(i, j)[0] != 255 && result.at<cv::Vec3b>(i, j)[1] != 255 && result.at<cv::Vec3b>(i, j)[2] != 255) {
			result.at<cv::Vec3b>(i, j)[0] = 255;
			result.at<cv::Vec3b>(i, j)[1] = 255;
			result.at<cv::Vec3b>(i, j)[2] = 255;
		}
		//If you are in Christmas mood and want to see the snow fall, uncomment the following:
		//cv::waitKey(2);
		//cv::imshow("Result", result);
	}
	return result;
}