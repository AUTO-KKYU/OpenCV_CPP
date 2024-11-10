/*
Mat Ŭ������ at() ��� �Լ� : �ϳ��ϳ��� �ȼ� ������ ����
	- 3ä�� �÷� �̹����� �ȼ�
		- at<Vec3b>(row_index, column_index)[channel index]
	- 1ä�� GrayScale �̹��� �ȼ�
		- at(uchar)<row_index, column_index)
		- GrayScale => ���(255), ������(0)
	- Vec3b : �������(BGR)
*/

#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat M(100, 200, CV_8UC3, Scalar(0, 0, 0)); // �÷�, ��� �ȼ��� ���������� �ʱ�ȭ
	Mat M2(100, 200, CV_8UC1, Scalar(0)); // GrayScale, ��� �ȼ��� ���������� �ʱ�ȭ
	
	int half = (M.rows + M.cols) / 2;

	for (int i = 0; i < M.rows; ++i)
	{
		for (int j = 0; j < M.cols; ++j)
		{
			if (i + j < half)
			{
				M.at<Vec3b>(i, j)[0] = 255;
				M.at<Vec3b>(i, j)[1] = 120;
				M.at<Vec3b>(i, j)[2] = 0;
				M2.at<uchar>(i, j) = 255;
			}
			else
			{
				M.at<Vec3b>(i, j) = Vec3b(120, 120, 120);
			}
		}
	}
	imshow("M", M);
	imshow("M2", M2);
	waitKey(0);
}