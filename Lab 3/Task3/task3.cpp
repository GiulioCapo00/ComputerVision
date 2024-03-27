#include <iostream>
#include "opencv2/opencv.hpp"
#include "functions.h"

void onMouse(int event, int x, int y, int f, void* userdata) {
	if(event == cv::EVENT_LBUTTONDOWN) {
		cv::Mat img = *((cv::Mat*) userdata);
        int b_tot=0;
        int g_tot=0;
        int r_tot=0;
        int count=0;
		for (int i=-4; i<=4; i++){
            for (int j=-4; j<=4; j++){
                b_tot+=img.at<cv::Vec3b>(y+j,x+i)[0];
                g_tot+=img.at<cv::Vec3b>(y+j,x+i)[1];
                r_tot+=img.at<cv::Vec3b>(y+j,x+i)[2];
                std::cout<<count<<std::endl;
                count+=1;
            }
        }
		cv::Vec3b click = img.at<cv::Vec3b>(y,x);
		
		std::cout<<"Blue mean: "<<b_tot/81<<std::endl;
		std::cout<<"Green mean: "<<g_tot/81<<std::endl;
		std::cout<<"Red mean: "<<r_tot/81<<std::endl;
		std::cout<<std::endl;
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


    cv::namedWindow("Task 2"); // Create a window    
    cv::imshow("Task 2", image); // Show our image inside the created window.
    cv::setMouseCallback("Task 2", onMouse, &image); // Wait for any keystroke in the window

    cv::waitKey(0);
    cv::destroyWindow("Task 2"); //destroy the created window

    return 0;
}
