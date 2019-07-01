#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("D:/Kepek/test.jpg");

	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get();
		return -1;
	}

	cv::Mat opened;
	cv::Mat closed;
	cv::morphologyEx(image, opened, cv::MORPH_CLOSE, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)));
	cv::morphologyEx(image, closed, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)));

	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Opened", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Closed", cv::WINDOW_AUTOSIZE);

	imshow("Original", image);
	imshow("Opened", opened);
	imshow("Closed", closed);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}