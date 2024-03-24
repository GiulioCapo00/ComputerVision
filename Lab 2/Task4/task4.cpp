#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ImageFilters.h"

int main(int argc, char **argv)
{
	// input image
	cv::Mat img = cv::imread("../Images/Garden_grayscale.jpg", 0);
	if(img.data==NULL) {
		printf("Image not found!\n");
		return 1;
	}
	cv::namedWindow("Corrupted Image");
	cv::imshow("Corrupted Image", img);
	cv::waitKey(0);

	// kernel size
	int ksize;
	std::cout << "Insert an odd and positive kernel size: ";
	std::cin >> ksize;
	
	if(ksize%2==0 || ksize<1) {
		std::cout << "Wrong kernel size!";
		return -1;
	}

	cv::Mat dst;

	
	cv::GaussianBlur( img, dst, cv::Size(ksize,ksize), 0, 0);
	cv::namedWindow("Gaussian filter");
	cv::imshow("Gaussian filter", dst);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}