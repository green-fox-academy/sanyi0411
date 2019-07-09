#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("D:/test_pic.jpg");

	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get();
		return -1;
	}

	//change the color image to grayscale image
	cvtColor(image, image, cv::COLOR_BGR2GRAY);

	//equalize the histogram
	cv::Mat hist_equalized_image;
	equalizeHist(image, hist_equalized_image);

	cv::String windowNameOfOriginalImage = "Original Image";
	cv::String windowNameOfHistogramEqualized = "Histogram Equalized Image";

	cv::namedWindow(windowNameOfOriginalImage, cv::WINDOW_NORMAL);
	cv::namedWindow(windowNameOfHistogramEqualized, cv::WINDOW_NORMAL);

	imshow(windowNameOfOriginalImage, image);
	imshow(windowNameOfHistogramEqualized, hist_equalized_image);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}