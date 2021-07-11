#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    Mat image = imread("images/windmill.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    // Converts using the fomula - pixel_value_of_output_image(x, y) = pixel_value_of_input_image(x, y) * alpha + beta;
    // convertTo( OutputArray m, int return type, double alpha=1, double beta=0 )
    Mat imageBrighnessHigh50;
    image.convertTo(imageBrighnessHigh50, -1, 1, 50); //increase the brightness by 50

    Mat imageBrighnessHigh100;
    image.convertTo(imageBrighnessHigh100, -1, 1, 100); //increase the brightness by 100

    Mat imageBrighnessLow50;
    image.convertTo(imageBrighnessLow50, -1, 1, -50); //decrease the brightness by 50

    Mat imageBrighnessLow100;
    image.convertTo(imageBrighnessLow100, -1, 1, -100); //decrease the brightness by 100

    //Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameBrightnessHigh50 = "Brightness Increased by 50";
    String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
    String windowNameBrightnessLow50 = "Brightness Decreased by 50";
    String windowNameBrightnessLow100 = "Brightness Decreased by 100";

    //Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    //Resize the Width x Height
    resizeWindow(windowNameOriginalImage, 1600, 800);
    resizeWindow(windowNameBrightnessHigh50, 1600, 800);
    resizeWindow(windowNameWithBrightnessHigh100, 1600, 800);
    resizeWindow(windowNameBrightnessLow50, 1600, 800);
    resizeWindow(windowNameBrightnessLow100, 1600, 800);

    //Show above images inside the created windows.
    imshow(windowNameOriginalImage, image);
    imshow(windowNameBrightnessHigh50, imageBrighnessHigh50);
    imshow(windowNameWithBrightnessHigh100, imageBrighnessHigh100);
    imshow(windowNameBrightnessLow50, imageBrighnessLow50);
    imshow(windowNameBrightnessLow100, imageBrighnessLow100);

    waitKey(0); // Wait for any key stroke

    destroyAllWindows(); //destroy all open windows

    return 0;
}   