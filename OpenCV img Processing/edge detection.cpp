/*
Edge detection 
- ������ �ȼ��� ���� ���� ���̰� ��������� �ް��� ���ϴ� ������ ȭ�� ã�� ���� 
- �ȼ��� �̺а��� ��ȭ�� �̿��Ͽ� ���� ã�� 

- grayscale���� �ַ� ��� edge ���
- horizontal �������� �̺а��� ���ϴ� Ŀ���� ����ϸ� img���� ���μ��� ����
- vertical �������� �̺а��� ���ϴ� Ŀ���� ����ϸ� img���� ���μ��� ����
*/

#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("image/house.jpeg", IMREAD_GRAYSCALE);
	Mat dst;

	Mat kernel_horiz = (Mat_<float>(3, 3) << -1, 0, 1, -1, 0, 1, -1, 0, 1) / 3.0; // x ������ �̺а� ���ϴ� Ŀ��
	Mat kernel_vert = (Mat_<float>(3, 3) << -1, -1, -1, 0, 0, 0, 1, 1, 1) / 3.0; // y������ �̺а� ���ϴ� Ŀ��

	imshow("input", img);

	filter2D(img, dst, CV_16SC1, kernel_horiz);
	convertScaleAbs(dst, dst);
	imshow("horizontal derivative", dst);

	filter2D(img, dst, CV_16SC1, kernel_vert);
	convertScaleAbs(dst, dst);
	imshow("vertical derivative", dst);

	waitKey(0);

}