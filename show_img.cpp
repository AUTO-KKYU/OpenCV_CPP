#include <iostream>
#include "opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	cout << "Hello World" << endl;
	Mat mat; // OpenCV���� �̹����� ǥ���ϱ� ���� ����ϴ� Ŭ���� mat�̶�� �̸��� Mat ��ü ����
	mat = imread("image\\pears.png");

	imshow("img", mat);
	waitKey(0);
}