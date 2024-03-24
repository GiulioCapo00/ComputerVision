#ifndef CV

#define CV
#include <iostream>
#include <opencv2/highgui.hpp>
void max_filter(cv::Mat& src, cv::Mat& dst, int ksize);
void min_filter(cv::Mat& src, cv::Mat& dst, int ksize);
void median_filter(cv::Mat& src, cv::Mat& dst, int ksize);
//bool truefun();
#endif 
