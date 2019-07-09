#include "opencv2/opencv.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	cv::VideoCapture cap("D:/Kepek/Editor.mp4");

	if (!cap.isOpened())
	{
		std::cout << "Cannot open the video file" << std::endl;
		return -1;
	}

	cv::namedWindow("Rotated Video", cv::WINDOW_AUTOSIZE);

	int angle = 180;
	cv::createTrackbar("Angle", "Rotated Video", &angle, 360);


	while (true)
	{
		cv::Mat originalFrame;

		bool bSuccess = cap.read(originalFrame);

		if (!bSuccess)
		{
			std::cout << "Cannot read the frame from video file" << std::endl;
			break;
		}

		cv::Mat rotationMat = cv::getRotationMatrix2D(cv::Point(originalFrame.cols / 2, originalFrame.rows / 2), (angle - 180), 1);

		cv::Mat rotatedFrame;
		warpAffine(originalFrame, rotatedFrame, rotationMat, originalFrame.size());

		imshow("Rotated Video", rotatedFrame);

		if (cv::waitKey(30) == 27)
		{
			break;
		}
	}

	return 0;
}