/*
Canny edge ���� : Sobel ���͸� ������� �� ���� ������ ���� ������ �˰��� 

- blur�� ������ �������� �����ϴ� ȿ��
- �̹����� noise�� ���ؼ� ��Ÿ�� false positive���� �����ϴ� ȿ�� 

Canny(src, dst, threshold1, threshold2)

threshold1 : edge�� Ȯ���� �ƴ� �ȼ����� ���ܽ�Ű�� ����
threshold2 : strong edge�� ã�� ����ġ ���� (threshold 1 > threshold 2)

*/

#include <opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("image/highway.jpeg", IMREAD_GRAYSCALE);
	Mat dst;

	Canny(img, dst, 100, 200);
	imshow("100 200", dst);

	Canny(img, dst, 50, 200);
	imshow("50 200", dst);

	Canny(img, dst, 50, 100);
	imshow("50 100", dst);
	waitKey(0);
}
