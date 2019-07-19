#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"

int main(int argc, char* argv[])
{
    cv::Mat image(300, 300, CV_8UC3, cv::Scalar::all(255));
    cv::putText(image, "My Text", cv::Point(100, 100), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2);
    cv::imshow("Result", image);
    cv::waitKey(0);

    return 0;
}