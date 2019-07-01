#include "opencv2/opencv.hpp"

int main(int argc, char** argv)
{
	cv::Mat original = cv::imread("D:/Kepek/test_pic.jpg");

	namedWindow("Rotated image", cv::WINDOW_AUTOSIZE);

	int angle = 180;
	cv::createTrackbar("Angle", "Rotated image", &angle, 360);

	int imageHieght = original.rows / 2;
	int imageWidth = original.cols / 2;

	while (true)
	{
		cv::Mat rotationMatrix = cv::getRotationMatrix2D(cv::Point(imageWidth, imageHieght), (angle - 180), 1);
		cv::Mat rotated;

		warpAffine(original, rotated, rotationMatrix, original.size());

		cv::imshow("Rotated image", rotated);

		if (cv::waitKey(30) == 27)
		{
			break;
		}
	}
	return 0;
}