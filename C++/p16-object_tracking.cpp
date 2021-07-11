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

    int low_H = 12;
    int high_H = 166;

    int low_S = 47;
    int high_S = 203;

    int low_V = 181;
    int high_V = 255;

    //Trackbar in control window
    cvCreateTrackbar("LowH", controlwindow, &low_H, 179);
    cvCreateTrackbar("HighH", controlwindow, &low_H, 179);

    cvCreateTrackbar("LowS", controlwindow, &low_S, 255);
    cvCreateTrackbar("HighS", controlwindow, &high_S, 255);

    cvCreateTrackbar("LowV", controlwindow, &low_V, 255);
    cvCreateTrackbar("HighV", controlwindow, &high_V, 255);

    int last_X = -1;
    int last_Y = -1;

    //A black image for the image lines
    Mat img_temp;
    cap.read(img_temp);
    Mat img_lines = Mat::zeros(img_temp.size(), CV_8UC3);

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

        //Calculate image moments of the threshold image
        Moments image_moments = moments(imgThreshold);

        double region_area = image_moments.m00;

        //Only track if the region_area is > 10000 pixels
        if(region_area > 10000){
            double region_centx = image_moments.m10/region_area;
            double region_centy = image_moments.m01/region_area;
            if(last_X>=0 && last_Y>=0 && region_centx>=0 and region_centy>=0){
                line(img_lines, Point(region_centx, region_centy), Point(last_X, last_Y), Scalar(0,0,255),2);
            }
            last_X = region_centx;
            last_Y = region_centy;
        }
        //Threshhold Image
        imshow(windowNameThresholdVideo, imgThreshold);

        orig_frame = orig_frame + img_lines;
        imshow(windowNameOriginalVideo, orig_frame);

        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }
    
    return 0;
}