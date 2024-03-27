#include <iostream>
#include "opencv2/highgui.hpp"
#include "functions.h"



void onMouse(int event, int x, int y, int f, void* userdata) {
	if(event == cv::EVENT_LBUTTONDOWN) {
		cv::Mat img = *((cv::Mat*) userdata);
		
		cv::Vec3b click = img.at<cv::Vec3b>(y,x);
		
		std::cout<<"Blue: "<<(int)click[0]<<std::endl;
		std::cout<<"Green: "<<(int)click[1]<<std::endl;
		std::cout<<"Red: "<<(int)click[2]<<std::endl;
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
