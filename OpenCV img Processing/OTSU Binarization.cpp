#include <opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat img1 = imread("image/hexagon_low noise.jpg", 0);
	Mat img2 = imread("image/hexagon_high noise.jpg", 0);
	Mat img1_th1, img2_th2;

	imshow("noise 10", img1);
	imshow("noise 50", img2);

	threshold(img1, img1_th1, 0, 255, THRESH_OTSU);
	threshold(img2, img2_th2, 0, 255, THRESH_OTSU);

	imshow("ostu 10", img1_th1);
	imshow("otsu 50", img2_th2);

	blur(img2, img2, Size(5, 5));
	imshow("noise 50 with blur", img2);

	threshold(img2, img2_th2, 0, 255, THRESH_OTSU);
	imshow("otsu 50 with blur", img2_th2);

	waitKey(0);
	return 0;
}