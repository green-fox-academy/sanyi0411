#include <iostream>
#include <vector>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

std::vector<cv::Rect> detectLetters(cv::Mat img)
{
    std::vector<cv::Rect> boundRect;
    cv::Mat img_gray, img_sobel, img_threshold, element;
    cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    cv::Sobel(img_gray, img_sobel, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT); //Change these values to tune the recognition
    //cv::imshow("Sobel", img_sobel);
    cv::threshold(img_sobel, img_threshold, 0, 255, cv::THRESH_OTSU + cv::THRESH_BINARY);
    //cv::imshow("Threshold", img_threshold);
    element = getStructuringElement(cv::MORPH_RECT, cv::Size(17, 3));
    cv::morphologyEx(img_threshold, img_threshold, cv::MORPH_CLOSE, element);
    //cv::imshow("Closed", img_threshold);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(img_threshold, contours, 0, 1);
    std::vector<std::vector<cv::Point>> contours_poly(contours.size());
    for (int i = 0; i < contours.size(); i++) {
        if (contours[i].size() > 100) {
            cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
            cv::Rect appRect(boundingRect(cv::Mat(contours_poly[i])));
            if (appRect.width > appRect.height)
                boundRect.push_back(appRect);
        }
    }
    return boundRect;
}
int main(int argc, char** argv)
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
            std::vector<cv::Rect> letterBBoxes1 = detectLetters(frame);
            for (int i = 0; i < letterBBoxes1.size(); i++) {
                cv::rectangle(frame, letterBBoxes1[i], cv::Scalar(0, 255, 0), 3, 8, 0);
            }
            cv::imshow("Text detection", frame);

            if (cv::waitKey(10) == 27) {
                std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
                break;
            }
        }
    }
    return 0;
}