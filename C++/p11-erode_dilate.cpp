#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){

    // Read the image file 
    Mat orig_image = imread("images/windmill.jpg");
    if(orig_image.empty()){
       cout << "Image could not be opened" << endl;
       cin.get(); //Wait for kepress
       return -1; 
    }

    //3x3 kernel erode
    Mat image_3x3_kernel_erode;
    erode(orig_image, image_3x3_kernel_erode, getStructuringElement(MORPH_RECT, Size(3, 3)));

    //5x5 kernel erode
    Mat image_5x5_kernel_erode;
    erode(orig_image, image_5x5_kernel_erode, getStructuringElement(MORPH_RECT, Size(5, 5)));

    //3x3 kernel dilate
    Mat image_3x3_kernel_dilate;
    dilate(orig_image, image_3x3_kernel_dilate, getStructuringElement(MORPH_RECT, Size(3, 3)));

    //5x5 kernel dilate
    Mat image_5x5_kernel_dilate;
    dilate(orig_image, image_5x5_kernel_dilate, getStructuringElement(MORPH_RECT, Size(5, 5)));

    //Window Names
    String orig_window = "orig_image";
    String window_3x3_kernel_erode = "image_3x3_kernel_erode";
    String window_5x5_kernel_erode = "image_5x5_kernel_erode";
    String window_3x3_kernel_dilate = "image_3x3_kernel_dilate";
    String window_5x5_kernel_dilate = "image_5x5_kernel_dilate";

    //Display Windows
    namedWindow(orig_window, WINDOW_NORMAL);
    resizeWindow(orig_window, 800, 400);

    namedWindow(window_3x3_kernel_erode, WINDOW_NORMAL);
    resizeWindow(window_3x3_kernel_erode,  800, 400);

    namedWindow(window_5x5_kernel_erode, WINDOW_NORMAL);
    resizeWindow(window_5x5_kernel_erode,  800, 400);

    namedWindow(window_3x3_kernel_dilate, WINDOW_NORMAL);
    resizeWindow(window_3x3_kernel_dilate,  800, 400);

    namedWindow(window_5x5_kernel_dilate, WINDOW_NORMAL);
    resizeWindow(window_5x5_kernel_dilate,  800, 400);

    imshow(orig_window, orig_image);
    imshow(window_3x3_kernel_erode, image_3x3_kernel_erode);
    imshow(window_5x5_kernel_erode, image_5x5_kernel_erode);
    imshow(window_3x3_kernel_dilate, image_3x3_kernel_dilate);
    imshow(window_5x5_kernel_dilate, image_5x5_kernel_dilate);

    waitKey(0);

    destroyAllWindows();
    return 0; 


}