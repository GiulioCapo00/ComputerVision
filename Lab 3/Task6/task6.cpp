#include <iostream>
#include "opencv2/opencv.hpp"
#include "functions.h"

void onMouse(int event, int x, int y, int f, void* userdata) {
	if(event == cv::EVENT_LBUTTONDOWN) {
		cv::Mat img = *((cv::Mat*) userdata);
        int b_tot=0;
        int g_tot=0;
        int r_tot=0;
		for (int i=-4; i<=4; i++){
            for (int j=-4; j<=4; j++){
                b_tot+=img.at<cv::Vec3b>(y+j,x+i)[0]/81;
                g_tot+=img.at<cv::Vec3b>(y+j,x+i)[1]/81;
                r_tot+=img.at<cv::Vec3b>(y+j,x+i)[2]/81;
            }
        }
		cv::Vec3b click = img.at<cv::Vec3b>(y,x);
		
		std::cout<<"Blue mean: "<<b_tot<<std::endl;
		std::cout<<"Green mean: "<<g_tot<<std::endl;
		std::cout<<"Red mean: "<<r_tot<<std::endl;
		std::cout<<std::endl;

        cv::Mat img_mask = cv::Mat::zeros(cv::Size(img.cols,img.rows), CV_8UC1);
        uchar T = 80;
        for(int i=0; i<img.rows; i++) {
            for(int j=0; j<img.cols; j++) {
                cv::Vec3b vec = img.at<cv::Vec3b>(i,j);
				
                if(std::abs(vec[0]-b_tot)<T && std::abs(vec[1]-g_tot)<T && std::abs(vec[2]-r_tot)<T)
                    img_mask.at<uchar>(i,j)=255;
                else
                    img_mask.at<uchar>(i,j)=0;
            }
        }

        cv::Mat dst_img = cv::Mat::zeros(cv::Size(img.cols,img.rows), CV_8UC3);
        for(int i=0; i<img.rows; i++) {
            for(int j=0; j<img.cols; j++) {
                if(img_mask.at<uchar>(i,j)==255){
                    dst_img.at<cv::Vec3b>(i,j)= cv::Vec3b(92, 37, 201);
                }
                else{
                    dst_img.at<cv::Vec3b>(i,j)=img.at<cv::Vec3b>(i,j);
                }

            }
        }

        cv::imshow("Destination", dst_img);
        cv::waitKey(0);
	}
}

int main(int argc, char** argv)
{  
    // Read the image file
    cv::Mat image = cv::imread("../Images/robocup.jpg");

    // Check for failure
    if (image.empty()) 
    {
    std::cout << "Could not open or find the image" << std::endl;
    std::cin.get(); //wait for any key press
    return -1;
    }

    cv::namedWindow("Task 5"); // Create a window    
    cv::imshow("Task 5", image); // Show our image inside the created window.
    cv::setMouseCallback("Task 5", onMouse, &image); // Wait for any keystroke in the window

    cv::waitKey(0);
    cv::destroyWindow("Task 5"); //destroy the created window

    return 0;
}

