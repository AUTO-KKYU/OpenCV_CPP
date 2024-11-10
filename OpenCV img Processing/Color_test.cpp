#include "opencv.hpp"
using namespace cv;

int main()
{
    // 200x300 ũ���� �̹���, 8��Ʈ 3ä��(BGR)�� ����
    // CV_8UC3 : 8 bit unsigned integer 3 channel (color ����)
    // CV_8UC1 : 8 bit unsigned integer 1 channel (grayscale ����)
    // CV_16S : 16 bit signed integer 1 channel (grayscale ����)
    // CV_32F : 32 bit floating-point number 1 channel (grayscale ����)

    Mat mat1(200, 300, CV_8UC3, Scalar(255, 0, 0));  // BGR���� (255, 0, 0)�� �Ķ���
    Mat mat2(200, 300, CV_8U, 120);

    imshow("Blue Image", mat1);  // ù ��° �̹����� "Blue Image" â�� ǥ��
    imshow("Gray Image", mat2);  // �� ��° �̹����� "Gray Image" â�� ǥ��   
    waitKey(0);
}
