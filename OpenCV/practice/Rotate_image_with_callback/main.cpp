#include "opencv2/opencv.hpp"

int iAngle = 180;
int iScale = 50;
int iBorderMode = 0;
cv::Mat original;
int iImageCenterY = 0;
int iImageCenterX = 0;

void CallbackForTrackBar(int, void*)
{
	cv::Mat matRotation = cv::getRotationMatrix2D(cv::Point(iImageCenterX, iImageCenterY), (iAngle - 180), iScale / 50.0);
	cv::Mat imgRotated;

	warpAffine(original, imgRotated, matRotation, original.size(), cv::INTER_LINEAR, iBorderMode, cv::Scalar());

	imshow("Rotated Image", imgRotated);

}

int main(int argc, char** argv)
{
	// Load the image
	original = cv::imread("D:/Kepek/test_pic.jpg", 1);

	iImageCenterY = original.rows / 2;
	iImageCenterX = original.cols / 2;

	//show the original image
	const char* pzOriginalImage = "Original Image";
	cv::namedWindow(pzOriginalImage, cv::WINDOW_AUTOSIZE);
	imshow(pzOriginalImage, original);

	//create the "Rotated Image" window and 3 trackbars in it
	cv::namedWindow("Rotated Image", cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("Angle", "Rotated Image", &iAngle, 360, CallbackForTrackBar);
	cv::createTrackbar("Scale", "Rotated Image", &iScale, 100, CallbackForTrackBar);
	cv::createTrackbar("Border Mode", "Rotated Image", &iBorderMode, 5, CallbackForTrackBar);

	int iDummy = 0;

	CallbackForTrackBar(iDummy, &iDummy);

	cv::waitKey(0);

	return 0;
}