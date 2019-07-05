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

	int iLowH = 95;
	int iHighH = 105;

	int iLowS = 170;
	int iHighS = 255;

	int iLowV = 100;
	int iHighV = 140;

	cv::createTrackbar("LowH", "Control", &iLowH, 179);
	cv::createTrackbar("HighH", "Control", &iHighH, 179);

	cv::createTrackbar("LowS", "Control", &iLowS, 255);
	cv::createTrackbar("HighS", "Control", &iHighS, 255);

	cv::createTrackbar("LowV", "Control", &iLowV, 255);
	cv::createTrackbar("HighV", "Control", &iHighV, 255);

	int iLastX = -1;
	int iLastY = -1;

	cv::Mat imgTmp;
	cap.read(imgTmp);

	cv::Mat imgLines = cv::Mat::zeros(imgTmp.size(), CV_8UC3);;

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

		inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded);

		//morphological opening (removes small objects from the foreground)
		erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
		dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

		//morphological closing (removes small holes from the foreground)
		dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
		erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

		//Calculate the moments of the thresholded image
		cv::Moments oMoments = moments(imgThresholded);

		double dM01 = oMoments.m01;
		double dM10 = oMoments.m10;
		double dArea = oMoments.m00;

		// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
		if (dArea > 10000)
		{
			//calculate the position of the ball
			int posX = dM10 / dArea;
			int posY = dM01 / dArea;

			if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
			{
				//Draw a red line from the previous point to the current point
				line(imgLines, cv::Point(posX, posY), cv::Point(iLastX, iLastY), cv::Scalar(0, 0, 255), 2);
			}

			iLastX = posX;
			iLastY = posY;
		}

		imshow("Thresholded Image", imgThresholded);

		imgOriginal = imgOriginal + imgLines;
		imshow("Original", imgOriginal);

		if (cv::waitKey(30) == 27)
		{
			std::cout << "esc key is pressed by user" << std::endl;
			break;
		}
	}

	return 0;
}