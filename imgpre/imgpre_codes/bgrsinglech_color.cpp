#include <opencv2/opencv.hpp>
#include<iostream>


using namespace std;
using namespace cv;


int main()
{
    Mat image=imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim1.jpeg");
    vector<Mat> sbgr;
    split(image,sbgr);   //split to sbgr[0],sbgr[1] ,sbgr[2]
    vector<Mat> mbgr(3);
    Mat bk1(image.size(),CV_8UC1,Scalar(0));
    //Mat bk2(image.size(),CV_8UC1,Scalar(255));
    
    //显示彩色的B分量
    Mat imageB(image.size(),CV_8UC3);
    mbgr[0]= sbgr[0];
    mbgr[1]= bk1;
    mbgr[2]= bk1;
    merge(mbgr,imageB);
    imshow("imageB",imageB);
    
    //显示彩色的G分量
    Mat imageG(image.size(),CV_8UC3);
    mbgr[0]= bk1;
    mbgr[1]= sbgr[1];
    mbgr[2]= bk1;
    merge(mbgr,imageG);
    imshow("imageG",imageG);
    
    //显示彩色的R分量
    Mat imageR(image.size(),CV_8UC3);
    mbgr[0]= bk1;
    mbgr[1]= bk1;
    mbgr[2]= sbgr[2];
    merge(mbgr,imageR);
    imshow("imageR",imageR);
    
    imwrite("imageR.jpg",imageR);
    imwrite("imageG.jpg",imageG);
    imwrite("imageB.jpg",imageB);

        waitKey();
}

