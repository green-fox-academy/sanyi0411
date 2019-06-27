#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	cv::VideoCapture cap("D:/testVideo.mp4");

	if (cap.isOpened() == false)
	{
		std::cout << "Cannot open the video file" << std::endl;
		std::cin.get();
		return -1;
	}

	cv::String window_name_of_original_video = "Original Video";
	cv::String window_name_of_video_blurred_with_5x5_kernel = "Video Blurred with 5 x 5 Kernel";

	cv::namedWindow(window_name_of_original_video, cv::WINDOW_NORMAL);
	cv::namedWindow(window_name_of_video_blurred_with_5x5_kernel, cv::WINDOW_NORMAL);

	while (true)
	{
		cv::Mat frame;
		bool bSuccess = cap.read(frame);
		if (bSuccess == false)
		{
			std::cout << "Found the end of the video" << std::endl;
			break;
		}

		cv::Mat frame_blurred_with_5x5_kernel;
		blur(frame, frame_blurred_with_5x5_kernel, cv::Size(10, 10)); //Increase these values to make it more blurred

		cv::imshow(window_name_of_original_video, frame);
		cv::imshow(window_name_of_video_blurred_with_5x5_kernel, frame_blurred_with_5x5_kernel);

		if (cv::waitKey(10) == 27)
		{
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}
	}
	return 0;
}