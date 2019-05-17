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



