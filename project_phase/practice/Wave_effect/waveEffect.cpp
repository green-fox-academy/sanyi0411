#include <iostream>
#include <opencv2/opencv.hpp>

void wave(const cv::Mat &image, cv::Mat &result);

int main()
{
	cv::Mat input = cv::imread("D:/Kepek/FB_IMG_1483277797808.jpg");
	cv::Mat output;
	wave(input, output);

	cv::imshow("Output", output);

	//cv::imshow("Output image", outputImage);
	cv::waitKey(0);

	return 0;
}

void wave(const cv::Mat &image, cv::Mat &result)
{
	cv::Mat sourceX(image.rows, image.cols, CV_32F);
	cv::Mat sourceY(image.rows, image.cols, CV_32F);

	for (int i = 0; i < image.rows; ++i) {
		for (int j = 0; j < image.cols; ++j) {
			sourceX.at<float>(i, j) = j;
			sourceY.at<float>(i, j) = i + 5 * sin(j / 10.0);
		}
	}
	cv::remap(image, result, sourceX, sourceY, cv::INTER_LINEAR);
}