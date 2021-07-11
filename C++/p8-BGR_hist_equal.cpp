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

    //Equalize histogram
    Mat hist_equal_image;
    cvtColor(image, hist_equal_image, COLOR_BGR2YCrCb);

    //Save Image
    bool fail_flag = imwrite("images/windmill_YCrCB.jpg", hist_equal_image);

    if(fail_flag == false){
        cout << "Image Save Fail" << endl;
    }

    //Split to 3 channels, Y,Cr and Cb
    vector<Mat> vec_channels;
    split(hist_equal_image, vec_channels);

    //Equalise histogram
    equalizeHist(vec_channels[0], vec_channels[0]);

    //Merge 3 channels
    merge(vec_channels, hist_equal_image);

    //Convert back to BGR for display and saving
    cvtColor(hist_equal_image, hist_equal_image, COLOR_YCrCb2BGR);

    //Save Image
    bool fail_flag_2 = imwrite("images/windmill_hist_equal.jpg", hist_equal_image);

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