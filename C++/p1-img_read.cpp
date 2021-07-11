#include <opencv2/opencv.hpp> 
 
int main(int argc, char** argv) 
{ 
 // Read the image file 
 cv::Mat image = cv::imread("images/windmill.jpg"); 
 return 0; 
}