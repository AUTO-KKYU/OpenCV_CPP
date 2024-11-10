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

// Sample�� ���� M(10, 15, CV_8UC3) Mat ��ü�� 10 x 15 ũ���̰� 8UC3 Ÿ���̹Ƿ�
// �޸� �뷮�� 10 * 15 * 8 * 3 bit 

/*
��� ���
channel depth = 8, channel #= 3
total size = 3600 bits
*/