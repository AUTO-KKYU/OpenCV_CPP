// resize() ȣ�� ����
// 1. �̹����� width x height�� ��ȯ : resize(src, dst, Size(width, height))
// 2. �̹����� (���� * fx) x (���� * fy)�� ��ȯ : resize(src, dst, Size(), fx, fy)

#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat M = imread("image/pears.png");
	if (M.empty())
		return -1;

	resize(M, M, Size(350, 350));
	imshow("M before sub", M);

	Mat sub1(M, Rect(30, 50, 200, 200));
	Mat sub2(M, Rect(150, 150, 200, 200));
	imshow("sub1", sub1);
	imshow("sub2", sub2);

	sub1 = sub1 + Scalar(0, 120, 0); // G ä�ΰ� 120 ����

	imshow("sub1+", sub1);
	imshow("sub2+", sub2);
	imshow("M after sub", M);
	waitKey(0);
	return 0;
}