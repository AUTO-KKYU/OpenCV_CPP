/*
노이즈를 제거하기 위한 필터의 설계는 convolution 연산 활용 
mask, kernel : 주변 픽셀의 범위를 정의하는 수단 

노이즈 제거 방법
1. Mean filter (blur) 
2. Gaussian filter (멀리 있는 픽셀의 가중치는 낮게 하고 가까이 있는 픽셀의 가중치를 높여서 평균값 계산 시 가중치를 거리에 따라 달리 조정하는 방식
3. Median filter (medianBlur, 주변 픽셀들의 값을 크기순으로 sorting하고, 가운게 값을 새로운 픽셀 값으로 선정)
4. bilateral filter (노이즈는 제거하면서 경계선은 선명하게 유지하는 필터)
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