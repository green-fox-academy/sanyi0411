#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

int main(int argc, char** argv)
{
    cv::RNG rng(12345);
    int borderType = cv::BORDER_CONSTANT;

    std::string imgPath = "D:/Kepek/venice.jpg";
    cv::Mat src = cv::imread(imgPath, cv::IMREAD_COLOR);
    cv::Mat dst;

    if (src.empty()) {
        std::cout << " Error opening image\n";
        return -1;
    }

    // Brief how-to for this program
    std::cout << "copyMakeBorder Demo: \n";
    std::cout << "-------------------- \n";
    std::cout << " ** Press 'c' to set the border to a random constant value \n";
    std::cout << " ** Press 'r' to set the border to be replicated \n";
    std::cout << " ** Press 'ESC' to exit the program \n";

    const char* window_name = "copyMakeBorder Demo";
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    int top = (int)(0.05*src.rows); //Width of border in % of the original image
    int bottom = top;
    int left = (int)(0.05*src.cols);
    int right = left;

    while(true) {
        cv::Scalar value(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        copyMakeBorder(src, dst, top, bottom, left, right, borderType, value);
        cv::imshow(window_name, dst);
        char c = (char)cv::waitKey(500);
        if (c == 27) {
            break;
        } else if (c == 'c') {
            borderType = cv::BORDER_CONSTANT;
        } else if (c == 'r') {
            borderType = cv::BORDER_REPLICATE;
        }
    }
    return 0;
}