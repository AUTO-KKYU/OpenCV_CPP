/*
���� ���� �˰��� : ���� ��ȯ

���� ���� : edge���� �𿩼� ������ ������ ��� ������ ������ �Ǵ� �������� ������ �ν��ϴ� ��
- x, y ���� ��ǥ�踦 ������ �Ÿ��� ���� ��ġ�� ǥ���ϴ� ��, �� ��ǥ��� �ٲپ� ������ �����ϴ� ���� ã��
- ������ �� �Ǵ� ������ ���۰� ������ ã�� 

HoughLinesP(edge, lines, rho, theta, thresh, min_length, max_gap)
*/
#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat gray = imread("image/house.jpeg", 0);
	Mat color, edge;
	vector<Vec4i>lines;

	imshow("org", gray);

	cvtColor(gray, color, COLOR_GRAY2BGR);
	Canny(gray, edge, 100, 200);
	imshow("edge", edge);

	int thresh[] = { 3, 5, 5, 5, 10 };
	int min_length[] = { 3, 5, 10, 5, 10 };
	int max_gap[] = { 0, 1, 1, 15, 15 };

	for (int n = 0; n < 5; n++)
	{
		Mat img(color);
		HoughLinesP(edge, lines, 1, CV_PI / 180, thresh[n], min_length[n], max_gap[n]);

		for (int i = 0; i < lines.size(); i++)
		{
			line(img, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 1);
			string title = "lines " + to_string(n);
			imshow(title, img);
		}
	}
	waitKey(0);

}

// �Ķ���� ���ڵ��� �ٲپ� ���� �׽�Ʈ 
// n�� 0�϶� ������ ���� ���� n�� 4�϶� ������ ���� ���� 