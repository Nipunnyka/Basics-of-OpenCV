#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
    Mat in = imread("dog.jpg", CV_LOAD_IMAGE_COLOR);
    if(in.empty())
       return -1;
    namedWindow("in", CV_WINDOW_AUTOSIZE );
    namedWindow("out", CV_WINDOW_AUTOSIZE);

    Point2f inquad[4];
    Point2f outquad[4];
    Mat delta( 2, 4, CV_32FC1);
    Mat out;
    delta=Mat::zeros(in.rows, in.cols, in.type() );

    inquad[0]=Point2f(-30,-60);
    inquad[1]=Point2f(in.cols+80, -60);
    inquad[2]=Point2f(in.cols+15,in.rows+60);
    inquad[3]=Point2f(-40,  in.rows-5) ;

    outquad[0]= Point2f(0,0);
    outquad[1]=Point2f(in.cols-1, 0);
    outquad[2]=Point2f(in.cols+1, in.rows-1);
    outquad[3]=Point2f(0, in.rows-1);

    delta=getPerspectiveTransform(inquad, outquad);

    warpPerspective(in, out, delta, out.size());


    imshow("in", in);
    imshow("out", out);


    waitKey(0);
    return 0;
}



