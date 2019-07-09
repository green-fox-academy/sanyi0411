#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	cv::VideoCapture cap("D:/Kepek/testVideo.mp4");

	if (cap.isOpened() == false)
	{
		std::cout << "Cannot open the video file" << std::endl;
		std::cin.get();
		return -1;
	}

	cv::String window_name_of_original_video = "Original Video";
	cv::String window_name_of_video_blurred_with_15x15_kernel = "Video Blurred with 5 x 5 Gaussian Kernel";

	cv::namedWindow(window_name_of_original_video, cv::WINDOW_NORMAL);
	cv::namedWindow(window_name_of_video_blurred_with_15x15_kernel, cv::WINDOW_NORMAL);

	while (true)
	{
		cv::Mat frame;
		bool bSuccess = cap.read(frame);
		if (bSuccess == false)
		{
			std::cout << "Found the end of the video" << std::endl;
			break;
		}

		//Blur the frame with 15x15 Gaussian kernel
		cv::Mat frame_blurred_with_15x15_kernel;
		GaussianBlur(frame, frame_blurred_with_15x15_kernel, cv::Size(15, 15), 0, 0);

		//show the frames in the created windows
		imshow(window_name_of_original_video, frame);
		imshow(window_name_of_video_blurred_with_15x15_kernel, frame_blurred_with_15x15_kernel);

		if (cv::waitKey(10) == 27)
		{
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}
	}

	return 0;

}