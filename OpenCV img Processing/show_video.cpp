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
			capture >> frame; // OpenCV에서 비디오 파일을 읽어서 한 프레임씩 가져오는 역할
			if (frame.empty())
				break;
		}

		imshow("frame", frame);
		int key = waitKey(30);

		if (key == ' ') // 스페이스바를 눌렀을 때
			stop = !stop;
		else if (key == 27) // ESC 키를 눌렀을 때
			break;
	}

	capture.release();
	destroyAllWindows();
	return 0;
}
