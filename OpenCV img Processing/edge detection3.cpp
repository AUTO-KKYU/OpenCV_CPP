/*
Canny edge 검출 : Sobel 필터를 기반으로 한 엣지 검출의 가장 개선된 알고리즘 

- blur한 영역의 엣지들을 제거하는 효과
- 이미지의 noise로 인해서 나타난 false positive들을 제거하는 효과 

Canny(src, dst, threshold1, threshold2)

threshold1 : edge가 확실히 아닌 픽셀들을 제외시키는 기준
threshold2 : strong edge를 찾는 문턱치 기준 (threshold 1 > threshold 2)

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
