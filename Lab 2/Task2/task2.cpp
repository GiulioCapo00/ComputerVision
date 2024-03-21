#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ImageFilters.h"

int main(int argc, char **argv)
{
	// input image
	cv::Mat img = cv::imread("../Images/Lena_corrupted.png");
	if(img.data==NULL) {
		printf("No image found!\n");
		return 1;
	}
	cv::namedWindow("Example 1");
	cv::imshow("Example 1", img);
	cv::waitKey(0);

	// kernel size
	int ksize;
	std::cout << "Insert kernel size: ";
	std::cin >> ksize;
	
	if(ksize%2==0 || ksize<1) {
		std::cout << "Wrong kernel size!";
		return -1;
	}

	cv::Mat maxImg;
	cv::Mat minImg;
	
	min_filter(img, minImg, ksize);
	cv::namedWindow("Min filter");
	cv::imshow("Min filter", minImg);
	cv::waitKey(0);

	max_filter(img, maxImg, ksize);
	cv::namedWindow("Max filter");
	cv::imshow("Max filter", maxImg);
	cv::waitKey(0);

	return 0;
}