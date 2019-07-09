#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char** argv)
{
	cv::VideoCapture cap(1);

	if (!cap.isOpened())
	{
		std::cout << "Cannot open the web cam" << std::endl;
		return -1;
	}

	cv::namedWindow("Control", cv::WINDOW_AUTOSIZE);

	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;

	//Create trackbars in "Control" window
	cv::createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	cv::createTrackbar("HighH", "Control", &iHighH, 179);

	cv::createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cv::createTrackbar("HighS", "Control", &iHighS, 255);

	cv::createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cv::createTrackbar("HighV", "Control", &iHighV, 255);

	while (true)
	{
		cv::Mat imgOriginal;

		bool bSuccess = cap.read(imgOriginal);

		if (!bSuccess)
		{
			std::cout << "Cannot read a frame from video stream" << std::endl;
			break;
		}

		cv::Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, cv::COLOR_BGR2HSV);

		cv::Mat imgThresholded;

		inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		//morphological opening (remove small objects from the foreground)

		erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
		dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

		//morphological closing (fill small holes in the foreground)
		dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
		erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

		imshow("Thresholded Image", imgThresholded);

		cv::Mat combined;
		imgOriginal.copyTo(combined, imgThresholded);
		imshow("Combined", combined);

		imshow("Original", imgOriginal);

		if (cv::waitKey(30) == 27)
		{
			std::cout << "esc key is pressed by user" << std::endl;
			break;
		}
	}
	return 0;
}