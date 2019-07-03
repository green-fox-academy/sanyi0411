#include <iostream>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

int main(int argc, char* argv[])
{
	cv::VideoCapture cap;
	cap.open(1);

	if (cap.isOpened() == false)
	{
		std::cout << "Cannot open the video camera" << std::endl;
		std::cin.get();
		return -1;
	}

	double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	cv::namedWindow("Original");
	cv::Mat frame;

	while (true)
	{
		cap >> frame;
		//bool bSuccess = cap.read(frame);
		if (frame.empty())
		{
			std::cout << "Video camera is disconnected" << std::endl;
			std::cin.get();
			break;
		}
		else {
			imshow("Original", frame);
			cv::Mat result(frame.size(), frame.type());
			cv::Mat grayImage;
			cv::cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY);
			cv::Mat detectedEdges;
			cv::blur(grayImage, detectedEdges, cv::Size(3, 3));
			cv::Canny(detectedEdges, detectedEdges, 100, 300);
			result = cv::Scalar::all(0);

			//This will show a purely black and white image
			//White where edges were detected, black everywhere else
			cv::imshow("Detected edges", detectedEdges);

			//With copyTo the detected edges will appear colored, everything else black
			frame.copyTo(result, detectedEdges);
			cv::imshow("Result", result);
		}
		if (cv::waitKey(10) == 27)
		{
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}
	}
	return 0;
}