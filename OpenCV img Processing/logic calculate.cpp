/*

Logic Calculation
bitwise_and(src1, src2, dst, InputArraymask=noArray())
bitwise_xor(src1, src2, dst, InputArraymask=noArray())
bitwise_nor(src1, dst, mask=noArray())

Arithmetic Calculation
Mat + Mat, Mat - Mat
Mat + Scalar, Mat + a
a * Mat, Mat / a

*/

#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat M1 = imread("image/pears.png", 0);
	Mat M2 = imread("image/flower.png", 0);
	Mat M_color = imread("image/apple.png", 1);
	Mat M3;

	if (M1.empty() || M2.empty())
		return -1;

	resize(M1, M1, Size(300, 300));
	resize(M2, M2, Size(300, 300));

	imshow("M1", M1);
	imshow("M2", M2);
	imshow("M_color", M_color);

	M3 = M1 + M2;
	imshow("M1+M2", M3);
	
	M3 = M1 - M2;
	imshow("M1-M2", M3);

	M3 = M2 + 100;
	imshow("M2+100", M3);

	bitwise_or(M1, M2, M3);
	imshow("or", M3);

	bitwise_and(M1, M2, M3);
	imshow("and", M3);

	bitwise_not(M2, M3);
	imshow("not", M3);

	M3 = M1 * 2;
	imshow("M1*2", M3);
	M3 = M1 / 2;
	imshow("M1/2", M3);

	M3 = M_color + Scalar(200, 0, 0);
	imshow("M_color+green", M3);
	M3 = M_color / 2;
	imshow("M_color/2", M3);
	M3 = M_color * 2;
	imshow("M_color*2", M3);
	waitKey(0);
	return 0;
}