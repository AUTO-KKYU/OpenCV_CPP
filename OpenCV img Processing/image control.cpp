/*
Mat 클래스의 at() 멤버 함수 : 하나하나의 픽셀 데이터 접근
	- 3채널 컬러 이미지의 픽셀
		- at<Vec3b>(row_index, column_index)[channel index]
	- 1채널 GrayScale 이미지 픽셀
		- at(uchar)<row_index, column_index)
		- GrayScale => 흰색(255), 검은색(0)
	- Vec3b : 색상순서(BGR)
*/

#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat M(100, 200, CV_8UC3, Scalar(0, 0, 0)); // 컬러, 모든 픽셀을 검은색으로 초기화
	Mat M2(100, 200, CV_8UC1, Scalar(0)); // GrayScale, 모든 픽셀을 검은색으로 초기화
	
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