/*
컬러 입력 이미지에서 주황색 성분이 강한 부분만 검출하는 이진화 수행

inRange(src, lowerb, upperb, dst)

*/

#include <opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    Mat img_hsv, orange_mask;
    Mat img_bgr = imread("image/bird.png", 1);

    Size size(400, 400);
    resize(img_bgr, img_bgr, size);

    if (img_bgr.empty())
    {
        cout << "이미지를 불러올 수 없습니다!" << endl;
        return -1;
    }

    cvtColor(img_bgr, img_hsv, COLOR_BGR2HSV);
    inRange(img_hsv, Scalar(10, 100, 100), Scalar(25, 255, 255), orange_mask); // 주황색 범위임 

    imshow("Original Image", img_bgr);
    imshow("Orange Mask", orange_mask);

    waitKey(0);
    return 0;
}
