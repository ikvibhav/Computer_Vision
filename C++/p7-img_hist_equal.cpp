#include <opencv2/opencv.hpp> 

using namespace cv;
using namespace std;

int main(int argc, char** argv) 
{ 
    // Read the image file 
    Mat image = imread("images/windmill.jpg");
    if(image.empty()){
       cout << "Image could not be opened" << endl;
       cin.get(); //Wait for kepress
       return -1; 
    }

    //Change color image to grayscale
    cvtColor(image,image,COLOR_BGR2GRAY);

    //Equalize histogram
    Mat hist_equal_image;
    equalizeHist(image, hist_equal_image);

    //Save Image
    bool fail_flag = imwrite("images/windmill_hist_equal_image.jpg", hist_equal_image);
    bool fail_flag_2 = imwrite("images/windmill_single_channel_image.jpg", image);

    if(fail_flag == false){
        cout << "Image Save Fail" << endl;
    }

    //Window Names
    String orig_image_window ="Original Image";
    String hist_equal_image_window ="Histogram Equalized Image";

    namedWindow(orig_image_window, WINDOW_NORMAL);
    resizeWindow(orig_image_window, 1600, 800);

    namedWindow(hist_equal_image_window, WINDOW_NORMAL);
    resizeWindow(hist_equal_image_window, 1600, 800);

    imshow(orig_image_window, image);
    imshow(hist_equal_image_window, hist_equal_image);

    waitKey(0);

    destroyAllWindows();
    return 0; 
}