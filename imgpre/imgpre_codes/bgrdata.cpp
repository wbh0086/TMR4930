#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat img=imread("/Users/Salmon/Desktop/red.jpg");
    int height=img.rows;
    int width=img.cols;
    ofstream outfile("/Users/Salmon/Desktop/red.txt");
    outfile << "height * width = " << height << " * " << width << endl;
    outfile << "(R, G, B)" <<endl;
    for(int i=0;i<height;i++)
    {
        unsigned char *data=img.data+i*width*img.channels();
        for(int j=0;j<width;j++)
        {
            int b=*(data+j*img.channels());  // opencv读取的是按照BGR的顺序
            int g=*(data+j*img.channels()+1);
            int r=*(data+j*img.channels()+2);
            outfile << "(" << r <<", "<< g <<", "<< b << ")" << endl;  //为方便阅读，将输出顺序改为RGB
        }
        outfile << endl;
    }
    img.release();
    system("pause");
    return 1;
}

//#include "iostream"
//#include <fstream>
//#include<opencv2/opencv.hpp>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    IplImage* img = cvLoadImage("/Users/Salmon/Desktop/red.jpg", -1);
//    if (img == NULL)
//        return 0;
//    CvScalar p;
//    ofstream outfile("/Users/Salmon/Desktop/red.txt");
//    cout << "图像的宽和高分别是：" << img->width << "和" << img->height << endl;
//    for (int i = 0; i < img->height; i++)
//    {
//
//        for (int j = 0; j < img->width; i++)
//        {
//            p = cvGet2D(img, i, j);
//            //注意OpenCV中保存形式为BGR，为方便阅读，在txt中保存为RGB形式
//            outfile << p.val[1] << "," << p.val[0] << "," << p.val[2] << " ";
//        }
//        outfile << endl;
//        //outfile << endl;
//    }
//    return 0;
//}

