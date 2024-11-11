#include <opencv.hpp>
using namespace cv;

int main()
{
	Mat M;

	M = imread("image/pears.png", 1); // 1 : color, 0 : grayscale
	M += Scalar(0, 0, 100);

	if (M.empty())
		return -1;

	imshow("pears", M);
	imwrite("image/pears_pink.png", M);
	waitKey(0);
}