// shallow copy 
// Mat 복사 생성자를 이용하여 새로운 Mat 객체를 생성할 경우,
// 기존 객체와 새로운 객체가 이미지 자체를 나타내는 영상 정보 메모리를 서로 공유

#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat M1(200, 300, CV_8UC3, Scalar(255, 0, 0)); // 파란색 이미지
	Mat M2 (M1); // M2 = M1과 동일함

	imshow("M1", M1);
	imshow("M2", M2);

	M1 = Scalar(0, 255, 0);
	imshow("M1_new", M1);
	imshow("M2_new", M2);
	waitKey(0);
	return 0;
}