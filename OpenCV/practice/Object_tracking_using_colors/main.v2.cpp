#include <iostream>
#include <deque>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char** argv)
{
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cout << "Cannot open the web cam" << std::endl;
        return -1;
    }

    cv::namedWindow("Control", cv::WINDOW_AUTOSIZE);

    int iLowH = 0;
    int iHighH = 33;

    int iLowS = 66;
    int iHighS = 133;

    int iLowV = 200;
    int iHighV = 255;

    cv::createTrackbar("LowH", "Control", &iLowH, 179);
    cv::createTrackbar("HighH", "Control", &iHighH, 179);

    cv::createTrackbar("LowS", "Control", &iLowS, 255);
    cv::createTrackbar("HighS", "Control", &iHighS, 255);

    cv::createTrackbar("LowV", "Control", &iLowV, 255);
    cv::createTrackbar("HighV", "Control", &iHighV, 255);

    cv::Mat imgTmp, frame;
    cap >> imgTmp;
    cv::Mat imgLines = cv::Mat::zeros(imgTmp.size(), CV_8UC3);

    int imgWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int imgHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    std::deque<int> pointsX, pointsY;
    for (int i = 0; i < 33; ++i) {
        pointsX.push_back(imgWidth / 2);
        pointsY.push_back(imgHeight / 2);
    }

    while (true) {
        cap >> frame;

        if (frame.empty()) {
            std::cout << "Video camera is disconnected" << std::endl;
            std::cin.get(); //Wait for any key press
            break;
        }

        cv::Mat imgHSV;
        cvtColor(frame, imgHSV, cv::COLOR_BGR2HSV);

        cv::Mat imgThresholded;
        inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded);

        //morphological opening (removes small objects from the foreground)
        erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
        dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

        //morphological closing (removes small holes from the foreground)
        dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
        erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

        //Calculate the moments of the thresholded image
        cv::Moments oMoments = moments(imgThresholded);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;

        // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
        if (dArea > 10000) {
            //calculate the position of the ball
            int posX = dM10 / dArea;
            int posY = dM01 / dArea;
            pointsX.push_back(posX);
            pointsY.push_back(posY);
            imgLines = cv::Mat::zeros(imgTmp.size(), CV_8UC3);

            for (int i = 0; i < pointsX.size() - 1; ++i) {
                line(imgLines, cv::Point(pointsX[i], pointsY[i]), cv::Point(pointsX[i + 1], pointsY[i + 1]), cv::Scalar(0, 0, 255), 2);
            }

            pointsX.pop_front();
            pointsY.pop_front();
        }

        imshow("Thresholded Image", imgThresholded);

        frame = frame + imgLines;
        imshow("Original", frame);

        if (cv::waitKey(30) == 27) {
            std::cout << "esc key is pressed by user" << std::endl;
            break;
        }
    }
    return 0;
}