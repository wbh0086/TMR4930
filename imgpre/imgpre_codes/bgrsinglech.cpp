#include <opencv2/opencv.hpp>
#include<iostream>


using namespace std;
using namespace cv;


int main()
{
    Mat img;
    img = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3.jpg");
    for (int i = 0; i < 3; i++)
    {
        Mat bgr(img.rows, img.cols, CV_8UC3, Scalar(0, 0, 0));
        Mat temp(img.rows, img.cols, CV_8UC1);
        Mat out[] = { bgr };
        int from_to[] = { i,i };
        mixChannels(&img, 1, out, 1, from_to,1);
        //获得其中一个通道的数据进行分析
        imshow("1 channel", bgr);
        waitKey();
    }
}
