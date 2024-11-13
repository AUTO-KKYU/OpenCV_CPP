/*
Edge detection 
- 인접한 픽셀들 간의 값의 차이가 상대적으로 급격히 변하는 지점의 화소 찾아 연결 
- 픽셀의 미분값의 변화를 이용하여 엣지 찾기 

- grayscale에서 주로 사용 edge 기법
- horizontal 방향으로 미분값을 구하는 커널을 사용하면 img에서 세로선을 검출
- vertical 방향으로 미분값을 구하는 커널을 사용하면 img에서 가로선을 검출
*/

#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("image/house.jpeg", IMREAD_GRAYSCALE);
	Mat dst;

	Mat kernel_horiz = (Mat_<float>(3, 3) << -1, 0, 1, -1, 0, 1, -1, 0, 1) / 3.0; // x 방향의 미분값 구하는 커널
	Mat kernel_vert = (Mat_<float>(3, 3) << -1, -1, -1, 0, 0, 0, 1, 1, 1) / 3.0; // y방향의 미분값 구하는 커널

	imshow("input", img);

	filter2D(img, dst, CV_16SC1, kernel_horiz);
	convertScaleAbs(dst, dst);
	imshow("horizontal derivative", dst);

	filter2D(img, dst, CV_16SC1, kernel_vert);
	convertScaleAbs(dst, dst);
	imshow("vertical derivative", dst);

	waitKey(0);

}