#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

/*
We assume here that the noise introduced by digitization has been removed by a previous preprocessing stage.
We also assume that the text has been isolated: no images, horizontal or vertical separators, etc.

Tutorial: http://felix.abecassis.me/2011/09/opencv-detect-skew-angle/
*/

double compute_skew(cv::Mat input)
{
    cv::Mat grayscale;
    cvtColor(input, grayscale, cv::COLOR_BGR2GRAY);
    cv::Size size = grayscale.size();
    cv::bitwise_not(grayscale, grayscale);
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(grayscale, lines, 1, CV_PI / 180, 100, size.width / 2.f, 20);
    cv::Mat disp_lines(size, CV_8UC1, cv::Scalar(0, 0, 0));
    double angle = 0.;
    unsigned nb_lines = lines.size();
    for (unsigned i = 0; i < nb_lines; ++i) {
        cv::line(disp_lines, cv::Point(lines[i][0], lines[i][1]),
                 cv::Point(lines[i][2], lines[i][3]), cv::Scalar(255, 0, 0));
        angle += atan2((double)lines[i][3] - lines[i][1],
            (double)lines[i][2] - lines[i][0]);
    }
    angle /= nb_lines; // mean angle, in radians.

    std::cout << "Angle: " << angle * 180 / CV_PI << std::endl;

    /*
    cv::imshow(filename, disp_lines);
    cv::waitKey(0);
    cv::destroyWindow(filename);
    */

    //Here we change radians to degrees
    return (angle * 180 / CV_PI);
}

/*The second parameter is the rotation angle in degrees(!)*/
void deskew(cv::Mat img, double angle)
{
    cvtColor(img, img, cv::COLOR_BGR2GRAY);
    cv::bitwise_not(img, img);

    std::vector<cv::Point> points;
    cv::Mat_<uchar>::iterator it = img.begin<uchar>();
    cv::Mat_<uchar>::iterator end = img.end<uchar>();
    for (; it != end; ++it)
        if (*it)
            points.push_back(it.pos());

    cv::RotatedRect box = cv::minAreaRect(cv::Mat(points));
    cv::Mat rot_mat = cv::getRotationMatrix2D(box.center, angle, 1);

    cv::Mat rotated;
    cv::warpAffine(img, rotated, rot_mat, img.size(), cv::INTER_CUBIC);
    cv::Size box_size = box.size;
    if (box.angle < -45.)
        std::swap(box_size.width, box_size.height);
    cv::Mat cropped;
    cv::getRectSubPix(rotated, box_size, box.center, cropped);
    cv::imshow("Original", img);
    cv::imshow("Rotated", rotated);
    cv::imshow("Cropped", cropped);
    cv::waitKey(0);
}

int main(int argc, char* argv[])
{
    cv::Mat pic = cv::imread("D:/Kepek/lorem_ipsum.jpg");
    deskew(pic, compute_skew(pic));

    return 0;
}