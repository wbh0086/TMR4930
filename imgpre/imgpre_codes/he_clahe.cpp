#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
    Mat src = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3.jpg");
    Mat dst;
    vector<Mat> planes;
    cvtColor(src, src, CV_BGR2HSV); //==
    split(src,planes);
    
    Ptr<CLAHE> clahe = createCLAHE();
    clahe->setClipLimit(4);
    clahe->apply(planes[0],planes[0]);
    clahe->apply(planes[1],planes[1]);
    clahe->apply(planes[2],planes[2]);
    merge(planes,  dst);
    
    imshow("H", planes[0]);
    imshow("S", planes[1]);
    imshow("V", planes[2]);
    imshow("src",src);
    imshow("dst",dst);
    imwrite("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim1_clahe2.jpeg",dst);
    waitKey();
    return 0;
}
