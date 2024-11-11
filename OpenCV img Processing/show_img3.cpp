#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat M1 = imread("image/pears.png", 0);
	Mat M3;

	imshow("M1", M1);
	flip(M1, M3, 0); // Vertical flip
	imshow("0", M3);
	flip(M1, M3, 1);// Horizontal flip
	imshow("1", M3);
	waitKey(0);

}