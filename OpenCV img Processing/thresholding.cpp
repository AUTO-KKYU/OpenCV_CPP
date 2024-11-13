/*
OpenCV에서는 threshold 함수가 binarization calculation에 주로 사용

Threshold(input img, output img, threshold value, max_val, threshold type)


*/
#include <iostream>
#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("image/lena.jpg", IMREAD_GRAYSCALE);
	Mat dst;

	imshow("org", img);
	threshold(img, dst, 100, 255, THRESH_BINARY);
	imshow("binary", dst);

	threshold(img, dst, 100, 255, THRESH_BINARY_INV);
	imshow("INV", dst);

	threshold(img, dst, 100, 255, THRESH_TRUNC);
	imshow("TRUNC", dst);

	threshold(img, dst, 100, 255, THRESH_TOZERO);
	imshow("TOZERO", dst);

	waitKey(0);
}