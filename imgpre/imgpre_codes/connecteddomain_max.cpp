#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace cv;
using namespace std;

vector<vector<Point> > contours;   //轮廓数组
vector<Point2d>  centers;    //轮廓质心坐标
vector<vector<Point> >::iterator itr;  //轮廓迭代器
vector<Point2d>::iterator  itrc;    //质心坐标迭代器
vector<vector<Point> > con;    //当前轮廓


int main()
{
    double area;
    double minarea = 100;
    double maxarea = 0;
    Moments mom; // 轮廓矩
    Mat image,gray,edge,dst;
    namedWindow("origin");
    namedWindow("connected_region");
    
    image = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3_thr.jpg");
    cvtColor(image, gray, COLOR_BGR2GRAY);
    blur(gray, edge, Size(3,3));   //模糊去噪
    threshold(edge,edge,200,255,THRESH_BINARY);   //二值化处理
    
    //寻找轮廓
    findContours( edge, contours,
                 CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE );
    itr = contours.begin();     //使用迭代器去除噪声轮廓
    while(itr!=contours.end())
    {
        area = contourArea(*itr);
        if(area<minarea)
        {
            itr = contours.erase(itr);  //itr一旦erase，需要重新赋值
        }
        else
        {
            itr++;
        }
        if (area>maxarea)
        {
            maxarea = area;
        }
    }
    dst = Mat::zeros(image.rows,image.cols,CV_8UC3);
    
    //绘制连通区域轮廓，计算质心坐标
    Point2d center;
    itr = contours.begin();
    while(itr!=contours.end())
    {
        area = contourArea(*itr);
        con.push_back(*itr);
        if(area==maxarea)
            drawContours(dst,con,-1,Scalar(255,255,255),2);  //最大面积白色绘制
//        else
//            drawContours(dst,con,-1,Scalar(255,0,0),2);   //其它面积蓝色绘制
        con.pop_back();
        
        //计算质心
        mom = moments(*itr);
        center.x = (int)(mom.m10/mom.m00);
        center.y = (int)(mom.m01/mom.m00);
        centers.push_back(center);
        
        itr++;
    }
    imshow("origin",image);
    imshow("connected_region",dst);
    imwrite("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim8_contour.jpg", dst);
    waitKey(0);
    
    //漫水填充连通区域
    Point2d seed;
    int new_scalar = 0;
    int loDiff = 8, upDiff = 8;
    int connectivity = 4;
    
    itrc = centers.begin();
    while(itrc!=centers.end())
    {
        seed = *itrc;
        floodFill(image,seed,Scalar::all(new_scalar),NULL,
                  Scalar::all(loDiff),Scalar::all(upDiff),connectivity);
        itrc++;
    }
    
    waitKey(0);
    return 0 ;
}
