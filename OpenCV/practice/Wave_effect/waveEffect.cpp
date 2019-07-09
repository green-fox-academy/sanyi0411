#include <iostream>
#include <opencv2/opencv.hpp>

void wave(std::string inputPath, int parameter, bool nogui, bool save, std::string savePath);

int main()
{
	wave("D:/Kepek/FB_IMG_1483277797808.jpg", 10, false, false, "0");

	return 0;
}

void wave(std::string inputPath, int parameter, bool nogui, bool save, std::string savePath)
{
	const cv::Mat image = cv::imread(inputPath);
	cv::Mat result;

	cv::Mat sourceX(image.rows, image.cols, CV_32F);
	cv::Mat sourceY(image.rows, image.cols, CV_32F);

	for (int i = 0; i < image.rows; ++i) {
		for (int j = 0; j < image.cols; ++j) {
			sourceX.at<float>(i, j) = j;
			sourceY.at<float>(i, j) = i + parameter * sin(j / 10.0);
		}
	}
	cv::remap(image, result, sourceX, sourceY, cv::INTER_LINEAR);

	if (nogui == false) {
		cv::imshow("Output", result);
		cv::waitKey(0);
	}
	if (save) {
		cv::imwrite(savePath, result);
	}
}