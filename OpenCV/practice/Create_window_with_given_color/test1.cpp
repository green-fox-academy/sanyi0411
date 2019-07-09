#include <opencv2/opencv.hpp>
int main(int argc, char** argv)
{
	cv::Mat img(500, 500, CV_8UC3, cv::Scalar(255, 255, 255));

	if (img.empty()) {
		std::cout << "Image cannot be created\n";
		return -1;
	}

	cv::namedWindow("myWindow", cv::WINDOW_AUTOSIZE);

	cv::imshow("myWindow", img);

	cv::waitKey(0);

	//cv::destroyWindow("myWindow");
	//cv::destroyAllWindows();

	return 0;
}