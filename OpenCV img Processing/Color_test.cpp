#include "opencv.hpp"
using namespace cv;

int main()
{
    // 200x300 크기의 이미지, 8비트 3채널(BGR)로 생성
    // CV_8UC3 : 8 bit unsigned integer 3 channel (color 영상)
    // CV_8UC1 : 8 bit unsigned integer 1 channel (grayscale 영상)
    // CV_16S : 16 bit signed integer 1 channel (grayscale 영상)
    // CV_32F : 32 bit floating-point number 1 channel (grayscale 영상)

    Mat mat1(200, 300, CV_8UC3, Scalar(255, 0, 0));  // BGR에서 (255, 0, 0)은 파란색
    Mat mat2(200, 300, CV_8U, 120);

    imshow("Blue Image", mat1);  // 첫 번째 이미지를 "Blue Image" 창에 표시
    imshow("Gray Image", mat2);  // 두 번째 이미지를 "Gray Image" 창에 표시   
    waitKey(0);
}
