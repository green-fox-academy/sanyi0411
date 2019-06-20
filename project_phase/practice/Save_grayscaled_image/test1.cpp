#include <opencv2/opencv.hpp>
int main(int argc, char** argv)
{
	std::string imageName = "D:/Kepek/FB_IMG_1483277797808.jpg";
	cv::Mat image;
	image = cv::imread(imageName, cv::IMREAD_COLOR);
	
	cv::Mat gray_image;
	cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
	imwrite("../Gray_Image.jpg", gray_image);
	cv::namedWindow(imageName, cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Gray image", cv::WINDOW_AUTOSIZE);
	imshow(imageName, image);
	imshow("Gray image", gray_image);
	cv::waitKey(0);
	return 0;
}