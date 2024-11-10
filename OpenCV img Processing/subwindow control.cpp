// resize() 호출 형식
// 1. 이미지를 width x height로 변환 : resize(src, dst, Size(width, height))
// 2. 이미지를 (가로 * fx) x (세로 * fy)로 변환 : resize(src, dst, Size(), fx, fy)

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

	sub1 = sub1 + Scalar(0, 120, 0); // G 채널값 120 증가

	imshow("sub1+", sub1);
	imshow("sub2+", sub2);
	imshow("M after sub", M);
	waitKey(0);
	return 0;
}