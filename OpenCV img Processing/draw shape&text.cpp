/*
선 그리기 : void line(img, pt1, pt2, color, thickness = 1, int lineType = 8, int shift = 0)
직사각형 그리기 1 : void rectangle(img, pt1, pt2, color, thickness = 1, int line-type = 8, int shift = 0)
직사각형 그리기 2 : void rectangle(img, rect, color, thickness = 1. int lineType = 8, int shift = 0)
원 그리기 : void circle(img, center, radius, color, thickness = 1, int lineType = 8, int shift = 0)
문자 그리기 : void putText(img, text, org, fontFace, fontScale, color, thickness = 1, lineType = 8, bool bottomLeftOrigin = False)
*/

#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat src(300, 400, CV_8UC3, Scalar(255, 255, 255));
	Scalar dark_blue(250, 50, 50);
	Scalar orange(50, 150, 250);

	for (int i = 0; i < src.cols; i += 80)
		for (int j = 0; j < src.cols; j += 40)
			rectangle(src, Rect(i, j, 65, 35), orange, -1); // (i, j) = (x, y) 좌표, width : 65, height = 35
			// -1은 사각형을 테두리만 그리는 대신 내부를 색으로 채우는 옵션
	for (int i = 0; i < src.cols; i += 50)
		line(src, Point(i, 10), Point(i + 50, src.rows - 10), dark_blue, 2);

	circle(src, Point(src.cols / 2, src.rows / 2), 50, Scalar(50, 200, 0), 3);
	circle(src, Point(src.cols / 2, src.rows / 2), 45, Scalar(200, 50, 0), 3);
	putText(src, string("many polygons"), Point(10, 30), FONT_HERSHEY_PLAIN, 1.8, Scalar(0, 0, 0), 2);

	imshow("src", src);
	waitKey(0);
}