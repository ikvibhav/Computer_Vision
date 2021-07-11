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
    String windowNameOriginalVideo = "Original Video";
    String windowNameRotatedVideo = "Rotated Video";

    //Create and open windows for above images
    namedWindow(windowNameOriginalVideo, WINDOW_NORMAL);
    namedWindow(windowNameRotatedVideo, WINDOW_NORMAL);

    int Angle_val = 180;
    createTrackbar("Angle", windowNameRotatedVideo, &Angle_val, 360);

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

        //Show frame
        imshow(windowNameOriginalVideo, orig_frame);

        //Returns an Affine Transformation Matrix for 2D rotation
        Mat matrotation_matrix = getRotationMatrix2D(Point(orig_frame.cols/2,orig_frame.rows/2), Angle_val-180, 1);

        //Rotate the image
        Mat rotated_frame;
        warpAffine(orig_frame, rotated_frame, matrotation_matrix, orig_frame.size());

        //Display the rotated frame
        imshow(windowNameRotatedVideo, rotated_frame);

        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}