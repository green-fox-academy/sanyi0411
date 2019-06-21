#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	cv::VideoCapture cap("D:/Kepek/Hadházi - Mirtil cica.mp4");

	if (cap.isOpened() == false)
	{
		std::cout << "Cannot open the video file" << std::endl;
		std::cin.get();
		return -1;
	}

	int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH)); //get the width of frames of the video
	int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT)); //get the height of frames of the video

	cv::Size frame_size(frame_width, frame_height);
	int frames_per_second = 10;

	//Create and initialize the VideoWriter object 
	cv::VideoWriter oVideoWriter("D:/MyVideo.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
		frames_per_second, frame_size, true);

	if (oVideoWriter.isOpened() == false)
	{
		std::cout << "Cannot save the video to a file" << std::endl;
		std::cin.get(); 
		return -1;
	}

	std::string window_name = "My Camera Feed";
	cv::namedWindow(window_name); //create a window called "My Camera Feed"

	while (true)
	{
		cv::Mat frame;
		bool isSuccess = cap.read(frame); // read a new frame from the video file

		//Breaking the while loop if frames cannot be read from the camera
		if (isSuccess == false)
		{
			std::cout << "Video camera is disconnected" << std::endl;
			std::cin.get(); //Wait for any key press
			break;
		}

		/*
		Make changes to the frame as necessary
		e.g.
		 1. Change brightness/contrast of the image
		 2. Smooth/Blur image
		 3. Crop the image
		 4. Rotate the image
		 5. Draw shapes on the image
		*/

		//write the video frame to the file
		oVideoWriter.write(frame);

		//show the frame in the created window
		cv::imshow(window_name, frame);

		//Wait for for 10 milliseconds until any key is pressed.  
		//If the 'Esc' key is pressed, break the while loop.
		//If any other key is pressed, continue the loop 
		//If any key is not pressed within 10 milliseconds, continue the loop 
		if (cv::waitKey(10) == 27)
		{
			std::cout << "Esc key is pressed by the user. Stopping the video" << std::endl;
			break;
		}
	}

	//Flush and close the video file
	oVideoWriter.release();

	return 0;
}