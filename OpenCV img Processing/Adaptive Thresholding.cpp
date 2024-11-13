/*
Adaptive thresholding : 픽셀별로 개별적으로 계산해서 특성에 맞게 적응적으로 threshold 값을 정하는 이진화 방법

adaptiveThreshold(src, dst, max_value, adaptive_threshold_type, threshold_type, ksize, C)
*/

#include <iostream>
#include <opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("image/rice.png", 0);
	Size size(400, 400);
	resize(img, img, size);

	Mat img_th;

	if (img.empty())
	{
		cout << "img is empty, write correct path on code" << endl;
		return -1;
	}

	imshow("org", img);

	threshold(img, img_th, 100, 255, THRESH_BINARY);
	imshow("thresh th=100", img_th);

	threshold(img, img_th, 0, 255, THRESH_OTSU);
	imshow("otsu", img_th);

	adaptiveThreshold(img, img_th, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 19, 0);
	imshow("adaptive K=19", img_th);

	adaptiveThreshold(img, img_th, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 49, 0);
	imshow("adaptive K=49", img_th);

	adaptiveThreshold(img, img_th, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 199, 0);
	imshow("adaptive K=199", img_th);

	waitKey(0);
	return 0;
}