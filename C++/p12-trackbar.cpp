#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// ------------------------------------------------------------Using While Loop---------------------------------------------------------
/*
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

    //Trackbar for Brightness Control
    int brightness_slider = 50;
    createTrackbar("Brightness",orig_image_window, &brightness_slider, 100);

    //Trackbar for Brightness Control
    // If contrast_slider = 0 initially, then it starts with a blank screen.
    int contrast_slider = 50;
    createTrackbar("Contrast",orig_image_window, &contrast_slider, 100);

    while (true){
        Mat converted_image;
        int brightness_val = brightness_slider-50;
        double contrast_val = contrast_slider/50.0;
        orig_image.convertTo(converted_image, -1, contrast_val, brightness_val);

        //Display the Image
        imshow(orig_image_window, converted_image);

        if (waitKey(10) == 27){
            break;
        }
    }

    return 0;
}
*/

//----------------------------------------------------------Using CallBack function---------------------------------------------------------
Mat orig_image;

void CallBackforBrightness(int brightness_val, void *userdata){
    Mat converted_image;
    //https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/
    int contrast_val = *(static_cast<int*>(userdata));

    orig_image.convertTo(converted_image, -1, contrast_val/50.0, brightness_val-50);

    imshow("Application Window", converted_image);
}

void CallBackforContrast(int contrast_val, void *userdata){
    Mat converted_image;
    //https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/
    int brightness_val = *(static_cast<int*>(userdata));

    orig_image.convertTo(converted_image, -1, contrast_val/50.0, brightness_val-50);

    imshow("Application Window", converted_image);
}

int main(){
    // Read the image file 
    orig_image = imread("images/windmill.jpg");
    if(orig_image.empty()){
       cout << "Image could not be opened" << endl;
       cin.get(); //Wait for kepress
       return -1; 
    }

    //Window Creation
    String orig_image_window ="Application Window";
    namedWindow(orig_image_window, WINDOW_NORMAL);
    resizeWindow(orig_image_window, 1600, 800);

    //Trackbar Control Variables
    int brightness_slider = 50;
    int contrast_slider = 50;

    //Callback Objects
    createTrackbar("Brightness",orig_image_window, &brightness_slider, 100, CallBackforBrightness, &contrast_slider);
    createTrackbar("Contrast",orig_image_window, &contrast_slider, 100, CallBackforContrast, &brightness_slider);

    //Trackbar for Brightness Control
    // If contrast_slider = 0 initially, then it starts with a blank screen.

    imshow(orig_image_window,orig_image);

    waitKey(0);

    return 0; 
}
