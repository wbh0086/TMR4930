#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main( int, char** argv )
{
    Mat src, dst;

    const char* source_window = "Source image";
    const char* equalized_window = "Equalized Image";

    // Load image
    src = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3.jpg");

    if( !src.data )
    { cout<<"Usage: ./Histogram_Demo <path_to_image>"<<endl;
        return -1;
    }

    // Convert to grayscale
    cvtColor( src, src, CV_BGR2GRAY );

    // Apply Histogram Equalization
    equalizeHist( src, dst );

    // Display results
    namedWindow( source_window, CV_WINDOW_AUTOSIZE );
    namedWindow( equalized_window, CV_WINDOW_AUTOSIZE );

    imshow( source_window, src );
    imshow( equalized_window, dst );
    imwrite("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3_V_bfhe.jpg", src);
    imwrite("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim3_V_he.jpg", dst);

    // Wait until user exits the program
    waitKey(0);
    return 0;
}

//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <stdio.h>
//
//using namespace cv;
//using namespace std;
//
//int main( int, char** argv )
//{
//    Mat src, dst;
//
//    const char* source_window = "Source image";
//    const char* equalized_window = "Equalized Image";
//
//    // Load image
//    src = imread("/Users/Salmon/Desktop/MasterThesis/Materials/sc_web/tim_V.jpg");
//
//    if( !src.data )
//    { cout<<"Usage: ./Histogram_Demo <path_to_image>"<<endl;
//        return -1;
//    }
//
//    // Convert to HSV
//    cvtColor( src, src, CV_BGR2HSV );
//
//    vector<Mat> hsv_channels(3);
//    split(src, hsv_channels);
//
//    // Apply Histogram Equalization
//    equalizeHist( hsv_channels[2], hsv_channels[2] );
//    merge( hsv_channels, dst);
//
//    cvtColor( dst, dst, CV_HSV2BGR);
//
//    // Display results
//    namedWindow( source_window, CV_WINDOW_AUTOSIZE );
//    namedWindow( equalized_window, CV_WINDOW_AUTOSIZE );
//
//    imshow( source_window, src );
//    imshow( equalized_window, dst );
//
//    // Wait until user exits the program
//    waitKey(0);
//    return 0;
//}

