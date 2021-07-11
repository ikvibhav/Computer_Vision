#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
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
    const char* controlwindow = "Control Window";
    String windowNameOriginalVideo = "Original Video";
    String windowNameThresholdVideo = "Threshold Video";

    //Create and open windows
    namedWindow(controlwindow, CV_WINDOW_AUTOSIZE);
    namedWindow(windowNameOriginalVideo, WINDOW_NORMAL);
    namedWindow(windowNameThresholdVideo, WINDOW_NORMAL);

    /* 
    For Yellow Color Detection-
    low_H = 12, High_H = 166
    low_S = 47, High_S = 203
    low_V = 181, High_V = 255 
    */

    int low_H =0;
    int high_H =179;

    int low_S =0;
    int high_S =255;

    int low_V =0;
    int high_V =255;

    //Trackbar in control window
    cvCreateTrackbar("LowH", controlwindow, &low_H, 179);
    cvCreateTrackbar("HighH", controlwindow, &low_H, 179);

    cvCreateTrackbar("LowS", controlwindow, &low_S, 255);
    cvCreateTrackbar("HighS", controlwindow, &high_S, 255);

    cvCreateTrackbar("LowV", controlwindow, &low_V, 255);
    cvCreateTrackbar("HighV", controlwindow, &high_V, 255);

    while (true)
    {
        Mat orig_frame;
        bool bSuccess = cap.read(orig_frame); // read a new frame from video 

         //Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat HSV_frame;
        cvtColor(orig_frame,HSV_frame,COLOR_BGR2HSV);

        Mat imgThreshold;
        //Threshold image
        inRange(HSV_frame, Scalar(low_H,low_S,low_V), Scalar(high_H,high_S,high_V),imgThreshold);

        //remove small objects from foreground
        erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
        dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));

        //Fill small holes in foreground
        dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
        erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));

        imshow(windowNameOriginalVideo, orig_frame);
        imshow(windowNameThresholdVideo, imgThreshold);

        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}