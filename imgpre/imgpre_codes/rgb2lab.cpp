#include <opencv2/opencv.hpp>
//#include <highgui.h>

using namespace cv;
using namespace std;

int main() {
    
    IplImage *srcImage = cvLoadImage("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim1.jpeg", CV_LOAD_IMAGE_COLOR);
    //IplImage *srcImage = cvLoadImage("/Users/Salmon/Desktop/blue.jpg", CV_LOAD_IMAGE_COLOR);
    // 原图像
    cvNamedWindow("BGR");
    cvShowImage("BGR", srcImage);
    
    // 存储HSV图像
    IplImage *hsv = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_8U, 3);
    
    // 将RGB图像转为HSV图像的函数
    cvCvtColor(srcImage, hsv, CV_BGR2Lab); // 或CV_BGR2HSV_FULL
    
    // HSV图像
    cvNamedWindow("HSV");
    cvShowImage("HSV",hsv);
    
    // 创建3通道
    IplImage* Rimg=cvCreateImage(cvGetSize(hsv),IPL_DEPTH_8U,1);
    IplImage* Gimg=cvCreateImage(cvGetSize(hsv),IPL_DEPTH_8U,1);
    IplImage* Bimg=cvCreateImage(cvGetSize(hsv),IPL_DEPTH_8U,1);
    
    // 分离 H S V
    cvSplit(hsv,Bimg,Gimg,Rimg,0);
    
    // 显示图像
    cvNamedWindow("B");
    cvShowImage("B",Bimg);
    cvNamedWindow("G");
    cvShowImage("G",Gimg);
    cvNamedWindow("R");
    cvShowImage("R",Rimg);
    
    waitKey(0);
    return 0;
}
