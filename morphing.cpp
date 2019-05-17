/*
                MORPHOLOGY OF AN IMAGE
Given morhphological transformations: erosion, dilation, opening and closing
dilation- deacreases white contect around edges
erosion- increases white content around edges
opening- erosion then dilation
closing- dilaton then erosion

Dilation and Erosion functions require a structuring element.

step 1: read image
step 2: statically input the degree to which youl would the like the erosion or dilation to take place
step 3: determine the structuring element
step 4: input what operation the user wants
step 5: perform that operation as per given instruction

*/


#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char ** argv)
{

    Mat image, dst;
    image=imread("dog.jpg", CV_LOAD_IMAGE_COLOR);

    int er_size = 6;
    Mat ele=getStructuringElement(cv::MORPH_CROSS, cv::Size(2*er_size +1, 2*er_size +1), cv::Point(er_size, er_size));

    cout<<"WHAT DO YOU WWANT?:\n \t1.Erosion\n \t2.Dilation\n \t3.Opening\n \t4.Closing\n ";
    int key;

    cin>>key;
    if(key==1)
        erode(image, dst, ele);

    else if (key==2)
        dilate(image, dst, ele);

    else if (key==3)
   {
        //dilate(erode(image, dst, ele));
        Mat dst2;
        erode(image, dst2, ele);
        dilate(dst2, dst, ele);
    }

    else if (key==4)
    {
       // erode(dilate(image, dst, ele));
        Mat dst2;
        dilate(image, dst2, ele);
        erode(dst2, dst, ele);
       }


    namedWindow("disp", CV_WINDOW_AUTOSIZE);
    imshow("disp", image);

    namedWindow("res", CV_WINDOW_AUTOSIZE);
    imshow("res", dst);

    waitKey(0);

    return 0;

}
