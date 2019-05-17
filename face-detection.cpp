/*
            FACE DETECTION USING HAAR CASCADES
 -tree based object detection technique
  At all scales, haar like features form the “raw material” that will be used by the boosted clas‐sifiers.
  They  all  have  the  feature  that  they  can  be  rapidly  computed  from  an  integralimage.
 
    step 1: read image
    step 2: load required xml classifiers
    step 3: define list "faces" of type rect
    step 4: use cascade to detect face like feature in image
    step 5: output image with the detected face encircled

*/

#include <opencv2/objdetect.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat img = imread("arnold_schwarzenegger.jpg", CV_LOAD_IMAGE_COLOR);
    if(img.empty())
       return -1;
    namedWindow("img", CV_WINDOW_AUTOSIZE );

    CascadeClassifier fc_csd;
    fc_csd.load("haarcascade_frontalface_alt.xml");

    vector<Rect> faces;
    fc_csd.detectMultiScale( img, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));

    for(int i=0; i<faces.size(); i++)
    {
                Point center(faces[i].x+faces[i].width*0.5, faces[i].y+faces[i].height*0.5);
                ellipse (img, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255), 4, 8, 0);
    }

    namedWindow("dface", CV_WINDOW_AUTOSIZE);

    imshow("dface", img);

    waitKey(0);
    return 0;
}



