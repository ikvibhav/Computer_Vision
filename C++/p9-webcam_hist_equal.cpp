#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    //open the video file for reading
    VideoCapture cap(0);

    // if not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    //Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNamehistequalImage = "Histogram Equal Image";

    //Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNamehistequalImage, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 

         //Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        //Equalize histogram
        Mat hist_equal_image;
        cvtColor(frame, hist_equal_image, COLOR_BGR2YCrCb);

        //Split to 3 channels, Y,Cr and Cb
        vector<Mat> vec_channels;
        split(hist_equal_image, vec_channels);

        //Equalise histogram
        equalizeHist(vec_channels[0], vec_channels[0]);

        //Merge 3 channels
        merge(vec_channels, hist_equal_image);

        //Convert back to BGR for display and saving
        cvtColor(hist_equal_image, hist_equal_image, COLOR_YCrCb2BGR);

        //Show above images inside the created windows.
        imshow(windowNameOriginalImage, frame);
        imshow(windowNamehistequalImage, hist_equal_image);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}