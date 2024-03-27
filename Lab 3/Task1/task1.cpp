#include <iostream>
#include "opencv2/opencv.hpp"
#include "functions.h"



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

    cv::namedWindow("Task 1"); // Create a window    
    cv::imshow("Task 1", image); // Show our image inside the created window.
    cv::waitKey(0); // Wait for any keystroke in the window

    cv::destroyWindow("Task 1"); //destroy the created window

    return 0;
}
