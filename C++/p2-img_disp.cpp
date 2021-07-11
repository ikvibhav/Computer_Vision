#include <opencv2/opencv.hpp> 

using namespace cv;
using namespace std;

int main(int argc, char** argv){ 
    // Read the image file 
    Mat image = imread("images/windmill.jpg",IMREAD_COLOR);
    //flags -> IMREAD_GRAYSCALE, IMREAD_UNCHANGED, Default- IMREAD_COLOR 

    //Blank Image
    //Height x Width
    //200, 800 - Number of pixels.
    //Mat image(200, 800, CV_8UC3, Scalar(250,50,30));

    // If image is empty and imshow used, then program crashes. So an extra check is placed.
    if(image.empty()){
       cout << "Image could not be opened" << endl;
       cin.get(); //Wait for kepress
       return -1; 
    }

    String windowname = "Window1";

    // WINDOW_NORMAL - User can resize the window 
    // WINDOW_AUTOSIZE - Vice Versa, Default
    namedWindow(windowname, WINDOW_NORMAL);

    //Resize the Width x Height
    resizeWindow(windowname, 1600, 800);

    imshow(windowname, image);

    waitKey(0); //Waits for a key press forever

    destroyWindow(windowname);

    return 0; 
}