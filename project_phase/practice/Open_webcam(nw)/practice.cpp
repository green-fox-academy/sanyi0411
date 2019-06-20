#include <opencv2/opencv.hpp>
#include <iostream>


int main(int argc, char* argv[])
{
	//This line will initialize the VideoCapture object with the default camera
	//and the default back-end.
	cv::VideoCapture cap;
	cap.open(0);

	if (cap.isOpened() == false)
	{
		std::cout << "Cannot open the video camera" << std::endl;
		std::cin.get(); //wait for any key press
		return -1;
	}

	double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	std::cout << "Resolution of the video : " << dWidth << " x " << dHeight << std::endl;

	std::string window_name = "My Camera Feed";
	cv::namedWindow(window_name);
	cv::Mat frame;

	while (true)
	{
		cap >> frame;
		//bool bSuccess = cap.read(frame);
		if (frame.empty())
		{
			std::cout << "Video camera is disconnected" << std::endl;
			std::cin.get(); //Wait for any key press
			break;
		}
		else
			//show the frame in the created window
			imshow(window_name, frame);

		//wait for for 10 ms until any key is pressed.  
		//If the 'Esc' key is pressed, break the while loop.
		//If the any other key is pressed, continue the loop 
		//If any key is not pressed withing 10 ms, continue the loop 
		if (cv::waitKey(10) == 27)
		{
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}
	}

	return 0;

}