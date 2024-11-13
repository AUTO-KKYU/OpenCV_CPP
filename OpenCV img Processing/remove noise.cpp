/*
����� �����ϱ� ���� ������ ����� convolution ���� Ȱ�� 
mask, kernel : �ֺ� �ȼ��� ������ �����ϴ� ���� 

������ ���� ���
1. Mean filter (blur) 
2. Gaussian filter (�ָ� �ִ� �ȼ��� ����ġ�� ���� �ϰ� ������ �ִ� �ȼ��� ����ġ�� ������ ��հ� ��� �� ����ġ�� �Ÿ��� ���� �޸� �����ϴ� ���
3. Median filter (medianBlur, �ֺ� �ȼ����� ���� ũ������� sorting�ϰ�, ����� ���� ���ο� �ȼ� ������ ����)
4. bilateral filter (������� �����ϸ鼭 ��輱�� �����ϰ� �����ϴ� ����)
*/

#include <opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("image/lena_noise.png", 0);

	if (img.empty())
	{
		cout << "Write exact path on image" << endl;
		return -1;
	}

	Mat blurred;
	
	for (int i = 5; i < 20; i += 14)
	{
		blur(img, blurred, Size(i, i));
		string title = "mean" + to_string(i);
		imshow(title, blurred);

		GaussianBlur(img, blurred, Size(i, i), 0, 0);
		title = "Gaussian" + to_string(i);
		imshow(title, blurred);

		medianBlur(img, blurred, i);
		title = "median" + to_string(i);
		imshow(title, blurred);

		bilateralFilter(img, blurred, i, i * 2, i / 2);
		title = "bilateral" + to_string(i);
		imshow(title, blurred);
	}
	waitKey(0);
	return 0;
}