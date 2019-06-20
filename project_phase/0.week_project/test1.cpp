#include <iostream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

const int windowColumns = 1000;
const int windowRows = 500;

cv::Mat image(windowRows, windowColumns, CV_8UC3, CV_RGB(255, 255, 255));

double findAngle(int x, int y)
{
	double b = (x - (windowColumns / 2));
	if (b < 0)
		b *= -1;
	double a = (y - (windowRows / 2));
	if (a < 0)
		a *= -1;
	
	//3rd side of the rectangular triangle
	//double c = sqrt((a * a) + (b * b));

	double tg_alpha = (a / b);

	double alpha = atan(tg_alpha) * 57.2957795; //Radian to degree conversion

	if (x < (windowColumns / 2) && y <= (windowRows / 2)) {
		alpha = 90 - alpha;
		alpha += 90;
	}
	if (x < (windowColumns / 2) && y >(windowRows / 2))
		alpha += 180;
	if (x >= (windowColumns / 2) && y > (windowRows / 2)) {
		alpha = 90 - alpha;
		alpha += 270;
	}
	return alpha;
}

void myMouseCallback(int event, int x, int y, int flags, void* userdata)
{
	if (flags & cv::MouseEventFlags::EVENT_FLAG_LBUTTON) {

		image = CV_RGB(255, 255, 255);

		cv::circle(image, { windowColumns / 2, windowRows / 2 }, 5, 0, 2);

		cv::line(image, { windowColumns / 2, windowRows / 2 }, { windowColumns, windowRows / 2 }, CV_RGB(0, 0, 0));

		cv::line(image, { windowColumns / 2, windowRows / 2 }, { x, y }, CV_RGB(0, 0, 0));

		//Double to string conversion:
		std::ostringstream strs;
		strs << findAngle(x, y);
		std::string degree = strs.str();

		cv::putText(image, degree, { x + 20, y + 20 }, cv::FONT_HERSHEY_SIMPLEX, 1, CV_RGB(0, 0, 0), 1, cv::LINE_8, false);
		//cv::rectangle(image, { x,y }, { y, x }, CV_RGB(255, (x*y) % 255, (x + y) % 255));
	}
	cv::imshow("Ablak", image);
}

int main()
{
	cv::circle(image, { windowColumns / 2, windowRows / 2 }, 5, 0, 2);

	cv::line(image, { windowColumns / 2, windowRows / 2 }, { windowColumns, windowRows / 2 }, CV_RGB(0, 0, 0));

	cv::imshow("Ablak", image);
	cv::setMouseCallback("Ablak", myMouseCallback);

	cv::waitKey(0);
}