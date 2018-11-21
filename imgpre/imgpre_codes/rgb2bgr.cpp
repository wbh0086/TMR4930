#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main() {
    
    IplImage *srcImage = cvLoadImage("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim1.jpeg", CV_LOAD_IMAGE_COLOR);
    //IplImage *srcImage = cvLoadImage("/Users/Salmon/Desktop/blue.jpg", CV_LOAD_IMAGE_COLOR);
    // 原图像
    cvNamedWindow("BGR");
    cvShowImage("BGR", srcImage);
    
    // 创建3通道
    IplImage* Rimg=cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U,1);
    IplImage* Gimg=cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U,1);
    IplImage* Bimg=cvCreateImage(cvGetSize(srcImage),IPL_DEPTH_8U,1);
    
    // 分离 R G B 单通道灰度图
    cvSplit(srcImage,Bimg,Gimg,Rimg,0);
    
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
