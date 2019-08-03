#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

/*More about OpenCV's Command Line Parser here: https://docs.opencv.org/3.4/d0/d2e/classcv_1_1CommandLineParser.html */

int main(int argc, char** argv)
{
    std::string keys =
        "{image          |             | image  source path   }"
        "{message        | Hello World | message to print on console  }"
        "{number         |           1 | number of times the message will be printed  }";

    cv::CommandLineParser parser(argc, argv, keys);


    /*Print message*/
    std::string message = parser.get<std::string>("message");
    if (!parser.check()) {
        parser.printErrors();
        throw std::runtime_error("Error parsing command line arguments");
    }

    int number = parser.get<int>("number");
    if (!parser.check()) {
        parser.printErrors();
        throw std::runtime_error("Error parsing command line arguments");
    }

    for (int i = 0; i < number; ++i) {
        std::cout << message << std::endl;
    }


    /*Open image*/
    std::string imagePath = parser.get<std::string>("image");

    if (!parser.check()) {
        parser.printErrors();
        throw std::runtime_error("Error parsing command line arguments");
    }

    cv::Mat image = cv::imread(imagePath);
    while (cv::waitKey(30) == -1) {
        cv::imshow("Image", image);
    }

    return 0;
}