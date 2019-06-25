#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat source = cv::imread("D:/Kepek/RGB.jpg", 1);

	cv::Mat bgr_gray[3];
	cv::split(source, bgr_gray);

	cv::Mat red;
	cv::Mat green;
	cv::Mat blue;
	cv::Mat temp = cv::Mat::zeros(cv::Size(source.cols, source.rows), CV_8UC1);

	//creating red picture
	std::vector<cv::Mat> redChannels;
	redChannels.push_back(temp);
	redChannels.push_back(temp);
	redChannels.push_back(bgr_gray[2]);

	merge(redChannels, red);
	cv::imshow("Red", red);

	//creating green picture
	std::vector<cv::Mat> greenChannels;
	greenChannels.push_back(temp);
	greenChannels.push_back(bgr_gray[1]);
	greenChannels.push_back(temp);

	merge(greenChannels, green);
	cv::imshow("Green", green);

	//creating blue picture
	std::vector<cv::Mat> blueChannels;
	blueChannels.push_back(bgr_gray[0]);
	blueChannels.push_back(temp);
	blueChannels.push_back(temp);

	merge(blueChannels, blue);
	cv::imshow("Blue", blue);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}
