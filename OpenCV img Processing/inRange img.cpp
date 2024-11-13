/*
�÷� �Է� �̹������� ��Ȳ�� ������ ���� �κи� �����ϴ� ����ȭ ����

inRange(src, lowerb, upperb, dst)

*/

#include <opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    Mat img_hsv, orange_mask;
    Mat img_bgr = imread("image/bird.png", 1);

    Size size(400, 400);
    resize(img_bgr, img_bgr, size);

    if (img_bgr.empty())
    {
        cout << "�̹����� �ҷ��� �� �����ϴ�!" << endl;
        return -1;
    }

    cvtColor(img_bgr, img_hsv, COLOR_BGR2HSV);
    inRange(img_hsv, Scalar(10, 100, 100), Scalar(25, 255, 255), orange_mask); // ��Ȳ�� ������ 

    imshow("Original Image", img_bgr);
    imshow("Orange Mask", orange_mask);

    waitKey(0);
    return 0;
}
