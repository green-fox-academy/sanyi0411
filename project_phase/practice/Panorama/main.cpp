#include <iostream> 
#include <fstream> 
#include "opencv2/imgcodecs.hpp" 
#include "opencv2/highgui.hpp" 
#include "opencv2/stitching.hpp" 

int main(int argc, char* argv[])
{
	std::vector<cv::Mat> imgs;

	cv::Mat image1 = cv::imread("D:/Kepek/boat1.jpg");
	cv::Mat image2 = cv::imread("D:/Kepek/boat2.jpg");
	cv::Mat image3 = cv::imread("D:/Kepek/boat3.jpg");
	cv::Mat image4 = cv::imread("D:/Kepek/boat4.jpg");
	cv::Mat image5 = cv::imread("D:/Kepek/boat5.jpg");
	cv::Mat image6 = cv::imread("D:/Kepek/boat6.jpg");

	if (image1.empty() || image2.empty() || image3.empty() || image4.empty() || image5.empty() || image6.empty()) {
		std::cout << "Can't read image\n";
		return -1;
	}

	//Also works with only two images
	imgs.push_back(image1);
	imgs.push_back(image2);
	imgs.push_back(image3);
	imgs.push_back(image4);
	imgs.push_back(image5);
	imgs.push_back(image6);

	cv::Mat panorama;

	// Create a Stitcher class object with mode panoroma 
	cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(cv::Stitcher::PANORAMA);

	// Command to stitch all the images present in the image array 
	cv::Stitcher::Status status = stitcher->stitch(imgs, panorama);

	switch (status) {
	case 0:
		cv::namedWindow("Result", cv::WINDOW_NORMAL);
		imshow("Result", panorama);
		//imwrite("result.jpg", panorama);
		cv::waitKey(0);
		break;
	case 1:
		std::cout << "Need more images\n";
		return -1;
		break;
	case 2:
		std::cout << "Homography est fail\n";
		return -1;
		break;
	case 3:
		std::cout << "Camera params adjust fail\n";
		return -1;
		break;
	}
	return 0;
}