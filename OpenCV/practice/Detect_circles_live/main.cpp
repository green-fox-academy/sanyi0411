#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <cmath>
#include <iostream>

void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour)
{
	int fontface = cv::FONT_HERSHEY_SIMPLEX;
	double scale = 0.4;
	int thickness = 1;
	int baseline = 0;

	cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
	cv::Rect r = cv::boundingRect(contour);

	cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
	cv::rectangle(im, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255, 255, 255), cv::FILLED);
	cv::putText(im, label, pt, fontface, scale, CV_RGB(0, 0, 0), thickness, 8);
}

int main()
{
	cv::VideoCapture cap;
	cap.open(0);

	if (cap.isOpened() == false) {
		std::cout << "Cannot open webcam" << std::endl;
		std::cin.get();
		return -1;
	}

	cv::Mat frame;

	while (true) {

		cap >> frame;

		if (frame.empty()) {
			std::cout << "Video camera is disconnected" << std::endl;
			std::cin.get();
			break;
		} else {

			cv::Mat grayScale;
			cvtColor(frame, grayScale, cv::COLOR_BGR2GRAY);

			cv::Mat blackandwhite;
			cv::Canny(grayScale, blackandwhite, 0, 50, 5);

			std::vector<std::vector<cv::Point>> contours;
			cv::findContours(blackandwhite.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

			std::vector<cv::Point> approx;
			cv::Mat dest = frame.clone();

			int counter = 0;

			for (int i = 0; i < contours.size(); ++i) {
				cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true) * 0.02, true);

				if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
					continue;

				double area = cv::contourArea(contours[i]);
				cv::Rect r = cv::boundingRect(contours[i]);
				int radius = r.width / 2;

				if (approx.size() > 7 && std::abs(1 - ((double)r.width / r.height)) <= 0.2 && std::abs(1 - (area / (3.141592 * std::pow(radius, 2)))) <= 2) {
					setLabel(dest, "CIRCLE", contours[i]);
				}

				cv::imshow("Result", dest);
			}
		}

		if (cv::waitKey(10) == 27) {
			std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
			break;
		}
	}
	return 0;
}