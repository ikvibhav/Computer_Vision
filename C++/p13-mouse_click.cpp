#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void MouseCallbackFunction(int event, int x, int y, int flags, void *userdata){
     if  ( event == EVENT_LBUTTONDOWN )
     {
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_RBUTTONDOWN )
     {
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if  ( event == EVENT_MBUTTONDOWN )
     {
          cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     }
     else if ( event == EVENT_MOUSEMOVE )
     {
          cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
     }
}

int main(){
    // Read the image file 
    Mat orig_image = imread("images/windmill.jpg");
    if(orig_image.empty()){
       cout << "Image could not be opened" << endl;
       cin.get(); //Wait for kepress
       return -1; 
    }

    //Window Creation
    String orig_image_window ="Application Window";
    namedWindow(orig_image_window, WINDOW_NORMAL);
    resizeWindow(orig_image_window, 1600, 800);

    //set callback function for any mousecallback
    setMouseCallback(orig_image_window, MouseCallbackFunction, NULL);

    imshow(orig_image_window,orig_image);

    waitKey(0);

    return 0; 
}
