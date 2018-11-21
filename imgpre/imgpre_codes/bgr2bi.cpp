#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

Mat image, src1, src2;
Mat dst;
int slider = 0;
void showTwoImage(Mat, Mat);
void on_trackbar(int, void*);

int main() {
    Mat img;
    Mat thr;
    img = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3.jpg");
    //img = imread("/Users/Salmon/Desktop/blue.jpg");
    
    Mat threshold;
    inRange(img, Scalar(0, 0, 0), Scalar(180, 180, 180), threshold);
    imwrite("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3_thr.jpg", threshold);
    
    thr = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3_thr.jpg");
    showTwoImage(img, thr);

    //imshow("contrary", image);
    imwrite("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3_cons.jpg", image);
    
    waitKey(0);
    return 0;
}

void showTwoImage(Mat src1, Mat src2)
{
    image.create(Size((src1.size().width + src2.size().width),
                      src1.size().height), CV_8UC3);
    
    Rect rect1(0, 0, src1.cols, src1.rows);
    Rect rect2(src1.cols, 0, src2.cols, src2.rows);
    
    src1.copyTo(image(rect1));
    src2.copyTo(image(rect2));
}
