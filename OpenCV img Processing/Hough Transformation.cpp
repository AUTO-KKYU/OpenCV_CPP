/*
직선 추출 알고리즘 : 허프 변환

직선 추출 : edge들이 모여서 직선을 형성할 경우 직선의 방정식 또는 시작점과 끝점을 인식하는 것
- x, y 직교 좌표계를 각도와 거리로 점의 위치를 표시하는 ρ, θ 좌표계로 바꾸어 직선을 구성하는 엣지 찾고
- 직선의 식 또는 직선의 시작과 종점을 찾기 

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

// 파라미터 인자들을 바꾸어 가며 테스트 
// n은 0일때 직선이 가장 적고 n이 4일때 직선이 가장 많다 