// shallow copy 
// Mat ���� �����ڸ� �̿��Ͽ� ���ο� Mat ��ü�� ������ ���,
// ���� ��ü�� ���ο� ��ü�� �̹��� ��ü�� ��Ÿ���� ���� ���� �޸𸮸� ���� ����

#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat M1(200, 300, CV_8UC3, Scalar(255, 0, 0)); // �Ķ��� �̹���
	Mat M2 (M1); // M2 = M1�� ������

	imshow("M1", M1);
	imshow("M2", M2);

	M1 = Scalar(0, 255, 0);
	imshow("M1_new", M1);
	imshow("M2_new", M2);
	waitKey(0);
	return 0;
}