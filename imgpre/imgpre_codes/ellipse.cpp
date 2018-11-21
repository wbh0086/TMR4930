#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;

int main( )
{
    Mat oriImage = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3.jpg");
    const char* filename = "/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim8_contour.jpg";
    Mat src_image = imread(filename, 0);
    if( src_image.empty() )
    {
        cout << "Couldn't open image!" << filename;
        return 0;
    }
    
    imshow("原图", src_image);
    
    //轮廓
    vector<vector<Point>> contours;
    
//    //使用canny检测出边缘
//    Mat edge_image;
//    Canny(src_image,edge_image,30,70);
//    imshow("canny边缘",edge_image);
    
    //边缘追踪，没有存储边缘的组织结构
    findContours(src_image, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    //Mat cimage = Mat::zeros(src_image.size(), CV_8UC3);
    
    for(size_t i = 0; i < contours.size(); i++)
    {
        //拟合的点至少为100
        size_t count = contours[i].size();
        if( count < 100 )
            continue;
        
        //椭圆拟合
        RotatedRect box = fitEllipse(contours[i]);
        
        //如果长宽比大于30，则排除，不做拟合
        if( MAX(box.size.width, box.size.height) > MIN(box.size.width, box.size.height)*30 )
            continue;
        
        //画出追踪出的轮廓
        drawContours(oriImage, contours, (int)i, Scalar(255,0,255), 1, 8);
        
        //画出拟合的椭圆
        ellipse(oriImage, box, Scalar(0,0,255), 1, CV_AA);
        //椭圆圆心
        Point p(box.center.x,box.center.y);
        circle(oriImage, p, 3, Scalar(0, 255, 255),3);
        //长轴端点1
        Point p_long_pos(box.center.x+box.size.height/2*sin(box.angle*CV_PI/180),box.center.y-box.size.height/2*cos(box.angle*CV_PI/180));
        circle(oriImage, p_long_pos, 2, Scalar(0, 255, 0), 3);
        //长轴端点2
        Point p_long_neg(box.center.x-box.size.height/2*sin(box.angle*CV_PI/180),box.center.y+box.size.height/2*cos(box.angle*CV_PI/180));
        circle(oriImage, p_long_neg, 2, Scalar(0, 255, 0), 3);
        //短轴端点1
        Point p_short_pos(box.center.x-box.size.width/2*cos(box.angle*CV_PI/180), box.center.y-box.size.width/2*sin(box.angle*CV_PI/180));
        circle(oriImage, p_short_pos, 2, Scalar(0, 255, 0), 3);
        //短轴端点2
        Point p_short_neg(box.center.x+box.size.width/2*cos(box.angle*CV_PI/180), box.center.y+box.size.width/2*sin(box.angle*CV_PI/180));
        circle(oriImage, p_short_neg, 2, Scalar(0, 255, 0), 3);
        //长轴及短轴
        line(oriImage, p_long_pos, p_long_neg ,Scalar(255, 255, 0), 1, CV_AA);//longitudinal axis
        line(oriImage, p_short_pos, p_short_neg, Scalar(255, 255, 0), 1, CV_AA);//latitudinal axis
        //追踪矩形框
        Point p_mer_lb(p_long_neg.x-box.size.width/2*cos(box.angle*CV_PI/180), p_long_neg.y+box.size.width/2*sin(box.angle*CV_PI/180));
        Point p_mer_ru(p_long_pos.x+box.size.width/2*cos(box.angle*CV_PI/180), p_long_pos.y-box.size.width/2*sin(box.angle*CV_PI/180));
        Point p_mer_rb(p_short_neg.x-box.size.height/2*cos(box.angle*CV_PI/180), p_short_neg.y+box.size.height/2*sin(box.angle*CV_PI/180));
        Point p_mer_lu(p_short_pos.x+box.size.height/2*cos(box.angle*CV_PI/180), p_short_pos.y-box.size.height/2*sin(box.angle*CV_PI/180));
//        vector<Point> p_er(4);
//        p_er[0] = p_long_neg;
//        p_er[1] = p_long_pos;
//        p_er[2] = p_short_neg;
//        p_er[3] = p_short_pos;
        rectangle(oriImage, p_mer_lb, p_mer_ru, Scalar(255,255,0));
    }
    imshow("拟合结果", oriImage);
    imwrite("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3_contour_ellipse.jpg", oriImage);
    
    waitKey();
    return 0;
}
