#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::VideoCapture cap("D:/Kepek/Editor.mp4");

	if (cap.isOpened() == false)
	{
		std::cout << "Cannot open the video file" << std::endl;
		std::cin.get();
		return -1;
	}

	cv::String windowNameOriginalVideo = "Original Video";
	cv::String windowNameBrightnessHigh50 = "Brightness Increased by 50";
	cv::String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
	cv::String windowNameBrightnessLow50 = "Brightness Decreased by 50";
	cv::String windowNameBrightnessLow100 = "Brightness Decreased by 100";

	cv::namedWindow(windowNameOriginalVideo, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameBrightnessHigh50, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameWithBrightnessHigh100, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameBrightnessLow50, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameBrightnessLow100, cv::WINDOW_NORMAL);

	while (true)
	{
		cv::Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false)
		{
			std::cout << "Found the end of the video" << std::endl;
			break;
		}

		cv::Mat frameBrighnessHigh50;
		frame.convertTo(frameBrighnessHigh50, -1, 1, 50);

		cv::Mat frameBrighnessHigh100;
		frame.convertTo(frameBrighnessHigh100, -1, 1, 100);

		cv::Mat frameBrighnessLow50;
		frame.convertTo(frameBrighnessLow50, -1, 1, -50);

		cv::Mat frameBrighnessLow100;
		frame.convertTo(frameBrighnessLow100, -1, 1, -100);

		imshow(windowNameOriginalVideo, frame);
		imshow(windowNameBrightnessHigh50, frameBrighnessHigh50);
		imshow(windowNameWithBrightnessHigh100, frameBrighnessHigh100);
		imshow(windowNameBrightnessLow50, frameBrighnessLow50);
		imshow(windowNameBrightnessLow100, frameBrighnessLow100);

		if (cv::waitKey(10) == 27)
		{
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}
	}
	return 0;
}