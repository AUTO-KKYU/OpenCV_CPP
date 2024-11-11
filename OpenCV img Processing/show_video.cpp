#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture capture("video/highway.mp4");
	if (!capture.isOpened()) {
		cout << "Error: Unable to open video file" << endl;
		return -1;
	}

	Mat frame;
	bool stop = false;

	while (true)
	{
		if (!stop) {
			capture >> frame; // OpenCV���� ���� ������ �о �� �����Ӿ� �������� ����
			if (frame.empty())
				break;
		}

		imshow("frame", frame);
		int key = waitKey(30);

		if (key == ' ') // �����̽��ٸ� ������ ��
			stop = !stop;
		else if (key == 27) // ESC Ű�� ������ ��
			break;
	}

	capture.release();
	destroyAllWindows();
	return 0;
}
