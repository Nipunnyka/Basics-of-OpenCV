#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdlib.h>


using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat img = imread("arnold_schwarzenegger.jpg", CV_LOAD_IMAGE_COLOR);             //load the image
    if(img.empty())
    {   //d::cout<<"image not found"; return -1;
    return -1;
    }

    Mat imgblur;
    GaussianBlur(img, imgblur, cv::Size(5,5),   0);                     //applying gaussain filter

    namedWindow("arnold_schwarzenegger", CV_WINDOW_AUTOSIZE );          //window for orig img
    imshow("arnold_schwarzenegger", img);                               //show orig img
    namedWindow("blurred arnold", CV_WINDOW_AUTOSIZE);                  //window for blurred img
    imshow(" blurred arnold", imgblur);                                 //show blurred img

     waitKey(0);

    destroyAllWindows();

    return 0;

}



