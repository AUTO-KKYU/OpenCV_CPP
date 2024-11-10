#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat M = imread("image/pears.png");
	Mat yuv, hsv, gray;

	cvtColor(M, gray, COLOR_BGR2GRAY);
	cvtColor(M, yuv, COLOR_BGR2YUV);
	cvtColor(M, hsv, COLOR_BGR2HSV);

	vector<Mat> hsv_ch(3);
	vector<Mat> yuv_ch(3);

	// split 함수를 사용하여 hsv와  yuv 이미지의 각 채널을 분리
	split(hsv, hsv_ch);
	split(yuv, yuv_ch);

	imshow("org", M);
	imshow("gray", gray);
	imshow("H", hsv_ch[0]);
	imshow("S", hsv_ch[1]);
	imshow("V", hsv_ch[2]);
	imshow("hsv", hsv);
	imshow("Y", yuv_ch[0]);

	waitKey(0);
	return 0;
}