# OpenCV C++/Linux Tutorial

## Installation
- Install all OpenCV dependencies, by following:-
    - https://www.youtube.com/watch?v=6pABIQl1ZP0
    - http://www.codebind.com/cpp-tutorial/install-opencv-ubuntu-cpp/
    - http://techawarey.com/programming/install-opencv-c-c-in-ubuntu-18-04-lts-step-by-step-guide/

## Tutorial From 
- https://www.opencv-srf.com/p/introduction.html 

### Notes-
- Compile the code using-
```bash
g++ hello_world.cpp -o hello_world `pkg-config --cflags --libs opencv`
```

## Fundamentals

### DataTypes of Arrays
- A given image can be assumed to be multiple channels of 2D matrices, with each element as a pixel. Eg, CV_8UC3

![Channels_pixels_matrices](image_for_tut/channels_matrices.png)

- Need to be read as first tuple {54,0,34}, second tuple {58,78,185} etc. 
- 1 upto 512 channels possible
- Other examples,
    - Mat img1(3, 5, CV_32F2 ); //Creating a 3 x 5  2-channel array with 32 bit floating point numbers
        - For arrays which consist of more than 4 channels, parentheses should be used to enclose the channel number
    - GrayScale (Black and White) Image -> single channel
    - RGB Image, 3 channels
- Intensity of pixels -
    - Min Value of pixel is 0 (black). As value increases, intensity of pixel also increases.
- Depth of an image
    - Number of bits allocated for each pixel
    - If 8, each pixel take value from 0 to 255 (11111111 in binary)
    - Depth of CV_8UC3 is 24 bits as it is 8 for each of the 3 channels
- Open CV read images in BGR format (blue, green and red)

### Brightness and Contrast Modification of an Image
- New_Image_pixel = Old_Image_pixel*alpha + beta
- beta - If you want to increase/decrease the brightness of an image, you have to add/subtract some positive constant value to each and every pixel in the image
- alpha - To increase/decrease the contrast, multiply each pixel by +ve constant>1 / +ve constant smaller than 1 

- Histogram Equalization - 
    - Image processing to enhance the contrast of an image by equalizing the intensity distribution. It will make a dark image (underexposed) less dark and a bright image (overexposed) less bright. 
    - Eg, In below figure the histogram equalization for the distribution of an image of depth 2 (possible values of {0,1,2,3}) is performed.
    
![histogram_before_equal](image_for_tut/histogram_before_equal.png)

![histogram_after_equal](image_for_tut/histogram_after_equal.png)

### Image Filtering
- Kernel -
    - A matrix with an odd height and odd width
    - 3x3 Normalized Box Filter, Homogeneous Smoothing (blurring):-

    ![3x3_Normalized_box_filter](image_for_tut/3x3_Normalized_box_filter.png)
    
    - 3x3 Normalized Box Filter, Homogeneous Smoothing (blurring):-

    ![3x3_Gaussian_Kernel](image_for_tut/3x3_Gaussian_Kernel.png)

- Smoothing/blurring is an image processing technique to remove imperfections and improve the image.
- Choice of kernel size is important. 
    - If too large, small features of image disappear (image looks blurred)
    - If too small, noise elimination is not possible

### Erode/Dilate an Image
- Erode -
    - Erodes foreground pixels in an image at boundaries.
        - Objects in image become smaller.
    - Each pixel is calculated as the minimum value of neighbourhood pixels defined by the kernel.
    - If the image contains more than one channel, each channel is processed independently.
- Dilate -
    - Opposite of Erosion

## Color Detection
- Object Detection - 
    - HSV color space (Hue, Saturation, Value) is more suitable color space for color based image segmentation.
        - Hue - Represents the color
        - Saturation - Represents amount the color is mixed with white
        - Value - Represents amount the color is mixed with black
    - After threshholding, unnecessary white patches elimated by morphological opening 
        - Done by erosion and then dialation
    - Morphological closing can be achieved by 
        - dialation and then erosion

## Object Tracking -
- Moment
    - A quantitative measure (descriptor) to describe the spatial distribution of set of points.
    - A set of scalars that provide an aggregated measure of a set of vectors.
    - Eg, in mechanics, 
        - If points represent mass, 
            - Zeroth moment - total mass
            - First moment/Total mass - center of mass
            - Second moment - Rotational Intertia
- Image Moment
    - https://en.wikipedia.org/wiki/Image_moment
    - A particular weighted average of the image pixel intensities 
    - Moments are taken on a single channel image (Black and White)
    - Area - M00
    - Centroid (x,y) = {M10/M00, M01/M00}

## Shape Detection
- OpenCV contours
    - Can be used to get a sequence of points of vertices of each white patch
    - 