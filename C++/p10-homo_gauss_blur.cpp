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

    //3x3 kernel blur
    Mat image_3x3_kernel_blur;
    blur(orig_image, image_3x3_kernel_blur, Size(3,3));

    //5x5 kernel blur
    Mat image_5x5_kernel_blur;
    blur(orig_image, image_5x5_kernel_blur, Size(12,12));

    //3x3 Gaussian blur
    Mat image_3x3_kernel_gauss_blur;
    GaussianBlur(orig_image, image_3x3_kernel_gauss_blur, Size(3,3),0);

    //5x5 Gaussian blur
    Mat image_5x5_kernel_gauss_blur;
    GaussianBlur(orig_image, image_5x5_kernel_gauss_blur, Size(5,5),0);

    //Window Names
    String orig_window = "orig_image";
    String window_3x3_kernel_blur = "image_3x3_kernel_blur";
    String window_5x5_kernel_blur = "image_5x5_kernel_blur";
    String window_3x3_kernel_gauss_blur = "image_3x3_kernel_gauss_blur";
    String window_5x5_kernel_gauss_blur = "image_5x5_kernel_gauss_blur";

    //Display Windows
    namedWindow(orig_window, WINDOW_NORMAL);
    resizeWindow(orig_window, 800, 400);

    namedWindow(window_3x3_kernel_blur, WINDOW_NORMAL);
    resizeWindow(window_3x3_kernel_blur,  800, 400);

    namedWindow(window_5x5_kernel_blur, WINDOW_NORMAL);
    resizeWindow(window_5x5_kernel_blur,  800, 400);

    namedWindow(window_3x3_kernel_gauss_blur, WINDOW_NORMAL);
    resizeWindow(window_3x3_kernel_gauss_blur,  800, 400);

    namedWindow(window_5x5_kernel_gauss_blur, WINDOW_NORMAL);
    resizeWindow(window_5x5_kernel_gauss_blur,  800, 400);

    imshow(orig_window, orig_image);
    imshow(window_3x3_kernel_blur, image_3x3_kernel_blur);
    imshow(window_5x5_kernel_blur, image_5x5_kernel_blur);
    imshow(window_3x3_kernel_gauss_blur, image_3x3_kernel_gauss_blur);
    imshow(window_5x5_kernel_gauss_blur, image_5x5_kernel_gauss_blur);

    waitKey(0);

    destroyAllWindows();
    return 0; 


}