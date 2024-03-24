#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ImageFilters.h"

int main(int argc, char **argv)
{
    // Read the image file
    cv::Mat image = cv::imread("../Images/Garden.jpg");

    // Check for failure
    if (image.empty()) 
    {
    std::cout << "Could not open or find the image" << std::endl;
    std::cin.get(); //wait for any key press
    return -1;
    }

    cv::namedWindow("Task 5"); // Create a window    
    cv::Mat gray_image;
    cv::cvtColor(image,gray_image,cv::COLOR_BGR2GRAY);
	cv::imshow("Task 5", gray_image); // Show our image inside the created window.
	cv::imwrite("../Images/Garden_grayscale.jpg", gray_image);

	cv::Mat equalized_img;
    cv::equalizeHist(gray_image, equalized_img);

    cv::namedWindow("Equalized image");
    cv::imshow("Equalized image", equalized_img);
    cv::imwrite("../Images/Equalized_img.jpg", equalized_img);

    
    int hSize = 256;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    cv::Mat hist;
    cv::calcHist( &equalized_img, 1, 0, cv::Mat(), hist, 1, &hSize, &histRange, true, false);
    int hist_w = 1024, hist_h = 400;
    int bin_w = cvRound( (double) hist_w/hSize );
    cv::Mat histImage( hist_h, hist_w, CV_8UC1, cv::Scalar(0) );
    normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
    for( int i = 1; i < hSize; i++ )
    {
        cv::line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ),
              cv::Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
              cv::Scalar(255), 2, 8, 0  );
    }

    cv::namedWindow("Histogram");
    cv::imshow("Histogram", histImage );
    cv::waitKey();
	cv::destroyWindow("Task 5"); 

	return 0;
}