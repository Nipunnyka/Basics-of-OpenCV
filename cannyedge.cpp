/*
            CANNY ALGO FOR EDGE DETECTION
-first  derivatives  are  computed  in  x  and  y  and  then  com‐bined into four directional derivatives.
-the points where these directional derivativesare local maxima are then candidates for assembling into edges. 
-The most significant dimension to  the  Canny  algorithm  is  this  phase  in  which  it  assembles  the  individual edge-candidate pixels into contours.
-the function only accepts grayscale images

step 1: Read image
step 2: Convert image to grayscale
step 3: Apply canny algo to this grayscale image
step 4: output the image with edges

*/


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
    Mat rgb = imread("arnold_schwarzenegger.jpg", CV_LOAD_IMAGE_COLOR);
    if(rgb.empty())
       return -1;
    namedWindow("rgb", CV_WINDOW_AUTOSIZE );
    imshow("rgb", rgb);

    Mat gray, cny;

    namedWindow("gray", CV_WINDOW_AUTOSIZE);
    namedWindow("Canny", CV_WINDOW_AUTOSIZE);

    cvtColor(rgb, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);

    Canny(gray, cny, 10,100,3,true);
    imshow("Canny", cny);


    waitKey(0);
    return 0;
}



