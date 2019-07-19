#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"

int main(int argc, char* argv[])
{
    cv::Mat image = cv::imread("D:/Kepek/read_test1.jpg");

    //If you want to resize source Mat so that it fits the pre-created destination Mat:
    cv::Mat givenSize(250,250,CV_8UC3);
    cv::resize(image, givenSize, givenSize.size());

    //If you want to decimate the image by factor of 2 in each direction:
    cv::Mat halved;
    cv::resize(image, halved, cv::Size(), 0.5, 0.5, cv::INTER_CUBIC);
    //cv::INTER_CUBIC generally gives better result, but cv::INTER_LINEAR is faster and still looks OK

    cv::imwrite("D:/Kepek/read_test1(250x250).jpg", givenSize);
    cv::imwrite("D:/Kepek/read_test1(halved).jpg", halved);

    return 0;

}