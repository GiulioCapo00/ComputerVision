

#include "ImageFilters.h"
#include <iostream>

void max_filter(cv::Mat& src, cv::Mat& out, int ksize) {
	int radius = ksize/2; 
	out = src.clone();
	
	for(int i=0; i<src.rows; i++) {
		for(int j=0; j<src.cols; j++) {
			int max = src.at<uchar>(i,j);
			for(int a=-radius; a<=radius; a++) {
				for(int b=-radius; b<=radius; b++) {
					if(i+a>0 && j+b>0 && i+a<src.rows && j+b<src.cols){
						if(src.at<uchar>(i+a,j+b) > max) {
							max = src.at<uchar>(i+a,j+b);
						}
					}
				}
			}
			out.at<uchar>(i, j) = max;
		}
	}
}

void min_filter(cv::Mat& src, cv::Mat& out, int ksize) {
	int radius = ksize/2; 
	out = src.clone();
	
	for(int i=0; i<src.rows; i++) {
		for(int j=0; j<src.cols; j++) {
			int min = src.at<uchar>(i,j);
			for(int a=-radius; a<=radius; a++) {
				for(int b=-radius; b<=radius; b++) {
					if(i+a>0 && j+b>0 && i+a<src.rows && j+b<src.cols){
						if(src.at<uchar>(i+a,j+b) < min) {
							min = src.at<uchar>(i+a,j+b);
						}
					}
				}
			}
			out.at<uchar>(i, j) = min;
		}
	}
}

void median_filter(cv::Mat& src, cv::Mat& out, int ksize) {
	int radius = ksize/2; 
	out = src.clone();
	for(int i=0; i<src.rows; i++) {
		for(int j=0; j<src.cols; j++) {
			std::vector<int> neighborhood;
			int size=0;
			for(int a=-radius; a<=radius; a++) {
				for(int b=-radius; b<=radius; b++) {
					if(i+a>0 && j+b>0 && i+a<src.rows && j+b<src.cols){
						neighborhood.push_back(src.at<uchar>(i+a,j+b));
						size++;
					}
				}
			}
			sort(neighborhood.begin(), neighborhood.end());
			out.at<uchar>(i, j) = neighborhood[(size)/2];
		}
	}
}




