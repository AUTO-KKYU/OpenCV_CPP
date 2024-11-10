// deep copy 

#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat M1(200, 300, CV_8UC3, Scalar(255, 0, 0));
	Mat M2;

	// M2 = M1.clone() 도 동일함!
	M1.copyTo(M2); // M1의 영상정보를 M2에 복사한다
	imshow("M1", M1);
	imshow("M2", M2);
	
	M1 = Scalar(0, 255, 0);
	imshow("M1_new", M1);
	imshow("M2_new", M2);
	waitKey(0);
	return 0;
}