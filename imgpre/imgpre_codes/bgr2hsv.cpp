#include <opencv2/opencv.hpp>
//#include <highgui.h>

using namespace cv;
using namespace std;

int main() {
    
    IplImage *srcImage = cvLoadImage("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3.jpg", CV_LOAD_IMAGE_COLOR);
    // 原图像
    cvNamedWindow("RGB");
    cvShowImage("RGB", srcImage);
    
    // 存储HSV图像
    IplImage *hsv = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_8U, 3);
    
    // 将RGB图像转为HSV图像的函数
    cvCvtColor(srcImage, hsv, CV_BGR2HSV_FULL); // 或CV_BGR2HSV_FULL
    
    // HSV图像
    cvNamedWindow("HSV");
    cvShowImage("HSV",hsv);
    
    // 创建3通道
    IplImage* Himg=cvCreateImage(cvGetSize(hsv),IPL_DEPTH_8U,1);
    IplImage* Simg=cvCreateImage(cvGetSize(hsv),IPL_DEPTH_8U,1);
    IplImage* Vimg=cvCreateImage(cvGetSize(hsv),IPL_DEPTH_8U,1);
    
    // 分离 H S V
    cvSplit(hsv,Himg,Simg,Vimg,0);
    
    // 显示图像
    cvNamedWindow("H");
    cvShowImage("H",Himg);
    cvNamedWindow("S");
    cvShowImage("S",Simg);
    cvNamedWindow("V");
    cvShowImage("V",Vimg);
    
    waitKey(0);
    return 0;
}
