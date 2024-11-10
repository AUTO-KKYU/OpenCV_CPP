#include <iostream>
#include "opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	cout << "Hello World" << endl;
	Mat mat; // OpenCV에서 이미지를 표현하기 위해 사용하는 클래스 mat이라는 이름의 Mat 객체 선언
	mat = imread("image\\pears.png");

	imshow("img", mat);
	waitKey(0);
}