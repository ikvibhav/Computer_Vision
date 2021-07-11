#include <opencv2/opencv.hpp> 

using namespace cv;
using namespace std;

int main(int argc, char** argv){ 
    // Open video file to read
    //VideoCapture cap("/home/vibhav/Desktop/personal/Rederijkerstraat 71.MP4");

    // Pass 0 for the argument index to use the default camera connected to your computer
    VideoCapture cap(0);

    if (cap.isOpened() == false)  
    {
     cout << "Cannot open the video file" << endl;
     cin.get();
     return -1;
    }

    double dw = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dh = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    double fps = cap.get(CAP_PROP_FPS); 
    
    cout << "Frame per second: " << fps << endl;
    cout << "Resolution of Video - " << dw << "x" << dh << endl;

    String window_name = "Video1";

    namedWindow(window_name, WINDOW_NORMAL);

    while(cap.isOpened()){
        Mat frame;
        bool succ_flag = cap.read(frame);

        if(succ_flag == false){
            cout << "End of Video" << endl;
            break;
        }

        imshow(window_name,frame);

        //waitKey(10) -> wait for 10ms before any key is pressed
        if(waitKey(10)==27){
            cout << "Escape Key pressed by user. Video Terminated" << endl;
            break;
        }
    }
    return 0; 
}