#include <opencv2/opencv.hpp>
//#include <highgui.h>

using namespace cv;
using namespace std;

int main() {
    
    IplImage *srcImage = cvLoadImage("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim2.jpeg", CV_LOAD_IMAGE_COLOR);
    // 原图像
    cvNamedWindow("RGB");
    cvShowImage("RGB", srcImage);
    
    // 存储YUV图像
    IplImage *yuv = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_8U, 3);
    
    // 将RGB图像转为YUV图像的函数
    cvCvtColor(srcImage, yuv, CV_BGR2YUV); // 或CV_BGR2HSV_FULL
    
    // HSV图像
    cvNamedWindow("YUV");
    cvShowImage("YUV",yuv);
    
    // 创建3通道
    IplImage* Yimg=cvCreateImage(cvGetSize(yuv),IPL_DEPTH_8U,1);
    IplImage* Uimg=cvCreateImage(cvGetSize(yuv),IPL_DEPTH_8U,1);
    IplImage* Vimg=cvCreateImage(cvGetSize(yuv),IPL_DEPTH_8U,1);
    
    // 分离 H S V
    cvSplit(yuv,Yimg,Uimg,Vimg,0);
    
    // 显示图像
    cvNamedWindow("Y");
    cvShowImage("Y",Yimg);
    cvNamedWindow("U");
    cvShowImage("U",Uimg);
    cvNamedWindow("V");
    cvShowImage("V",Vimg);

    
    waitKey(0);
    return 0;
}
