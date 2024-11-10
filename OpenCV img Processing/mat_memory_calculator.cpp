#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat mat(10, 15, CV_8UC3);
	int ch_depth = mat.elemSize1() * 8;
	cout << "channel depth=" << ch_depth << ", channel #=" << mat.channels() << endl;

	int imagesize = mat.cols * mat.rows * mat.channels() * ch_depth;
	cout << "total size = " << imagesize << "bits" << endl;
}

// Sample로 만든 M(10, 15, CV_8UC3) Mat 객체가 10 x 15 크기이고 8UC3 타입이므로
// 메모리 용량은 10 * 15 * 8 * 3 bit 

/*
출력 결과
channel depth = 8, channel #= 3
total size = 3600 bits
*/