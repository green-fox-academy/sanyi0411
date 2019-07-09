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
	cv::Mat source = cv::imread("D:/Kepek/test_shapes.png");

	if (source.empty()) {
		std::cerr << "Could not open image\n";
		return -1;
	}

	cv::Mat grayScale;
	cvtColor(source, grayScale, cv::COLOR_BGR2GRAY);

	cv::Mat blackandwhite;
	cv::Canny(grayScale, blackandwhite, 0, 50, 5);

	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(blackandwhite.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	std::vector<cv::Point> approx;
	cv::Mat dest = source.clone();

	int counter = 0;

	for (int i = 0; i < contours.size(); ++i) {
		cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true) * 0.02, true);

		if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
			continue;

		double area = cv::contourArea(contours[i]);
		cv::Rect r = cv::boundingRect(contours[i]);
		int radius = r.width / 2;

		std::string label = std::to_string(approx.size());

		//If you want to detect other shapes than circles:
		//the approx.size() is equal to the points of the polygon
		//E.g: 
		//if (approx.size() == 3) {}
		//This will filter only for triangles
 		if (approx.size() > 7 && std::abs(1 - ((double)r.width / r.height)) <= 0.2 && std::abs(1 - (area / (3.141592 * std::pow(radius, 2)))) <= 2) {
			setLabel(dest, "CIRCLE", contours[i]);
			counter++;
		}
	}
	std::cout << "I have found " << counter << " circle(s)" << std::endl;

	cv::namedWindow("Result");
	cv::imshow("Result", dest);

	cv::waitKey(0);

	return 0;
}