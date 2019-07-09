#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	//open the video file for reading
	cv::VideoCapture cap("D:/Kepek/Hadházi - Mirtil cica.mp4");

	// if not success, exit program
	if (cap.isOpened() == false)
	{
		std::cout << "Cannot open the video file" << std::endl;
		std::cin.get(); //wait for any key press
		return -1;
	}

	//cap.set(CAP_PROP_POS_FRAMES, 3); 

	double fps = cap.get(cv::CAP_PROP_FPS);
	std::cout << "Frames per seconds : " << fps << std::endl;

	cv::String window_name = "My First Video";

	cv::namedWindow(window_name, cv::WINDOW_NORMAL);

	while (true)
	{
		cv::Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video 

		//Breaking the while loop at the end of the video
		if (bSuccess == false)
		{
			std::cout << "Found the end of the video" << std::endl;
			break;
		}

		//show the frame in the created window
		imshow(window_name, frame);

		//wait for for 20 ms until any key is pressed.  
		//If the 'Esc' key is pressed, break the while loop.
		//If the any other key is pressed, continue the loop 
		//If any key is not pressed withing 20 ms, continue the loop
		//Change 20 to speed up or slow down video
		if (cv::waitKey(20) == 27)
		{
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}
	}

	return 0;

}