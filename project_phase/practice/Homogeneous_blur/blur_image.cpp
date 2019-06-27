#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("D:/Kepek/FB_IMG_1483277797808.jpg");

	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get();
		return -1;
	}

	//Blur the image with 3x3 kernel
	cv::Mat image_blurred_with_3x3_kernel;
	blur(image, image_blurred_with_3x3_kernel, cv::Size(3, 3));

	//Blur the image with 5x5 kernel
	cv::Mat image_blurred_with_5x5_kernel;
	blur(image, image_blurred_with_5x5_kernel, cv::Size(5, 5));

	cv::String window_name = "Original";
	cv::String window_name_blurred_with_3x3_kernel = "Original Blurred with 3 x 3 Kernel";
	cv::String window_name_blurred_with_5x5_kernel = "Original Blurred with 5 x 5 Kernel";

	cv::namedWindow(window_name);
	cv::namedWindow(window_name_blurred_with_3x3_kernel);
	cv::namedWindow(window_name_blurred_with_5x5_kernel);

	imshow(window_name, image);
	imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
	imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}