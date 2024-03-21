#include <iostream>
#include "opencv2/opencv.hpp"
#include "functions.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{  
    // Read the image file
    Mat image = cv::imread("../Images/Garden.jpg");

    // Check for failure
    if (image.empty()) 
    {
    cout << "Could not open or find the image" << endl;
    cin.get(); //wait for any key press
    return -1;
    }

    String windowName = "Task 1"; //Name of the window
    namedWindow(windowName); // Create a window    
    imshow(windowName, image); // Show our image inside the created window.
    waitKey(0); // Wait for any keystroke in the window

    Mat gray_image;
    cv::cvtColor(image,gray_image,COLOR_BGR2GRAY);
    cv::imwrite("../Images/Garden_grayscale.jpg", gray_image);

    destroyWindow(windowName); //destroy the created window

    return 0;
}
