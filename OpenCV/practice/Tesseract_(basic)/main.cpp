#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    std::string outText;
    //std::string imPath = "D:/Kepek/OpenCV/1.jpg";
    std::string imPath = "D:/Kepek/read_test.png";

    // Create Tesseract object
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

    // Initialize tesseract to use English (eng) and the LSTM OCR engine. 
    ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

    // Set Page segmentation mode to PSM_AUTO (3)
    ocr->SetPageSegMode(tesseract::PSM_AUTO);

    // Open input image using OpenCV
    cv::Mat im = cv::imread(imPath, cv::IMREAD_COLOR);

    // Set image data
    ocr->SetImage(im.data, im.cols, im.rows, 3, im.step);

    // Run Tesseract OCR on image
    outText = std::string(ocr->GetUTF8Text());

    // print recognized text
    std::cout << outText << std::endl; // Destroy used object and release memory ocr->End();

    return EXIT_SUCCESS;
}