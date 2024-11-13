/*
sobel filter

- 3 x 3 Ŀ���� ����� �Ʒ� �ڵ�� ���� �����Ͽ� �밢�� ������ ��������� ���Ʒ� �� �¿��� ����� �� ū ����ġ �ο�
- ���� ������ ������ ���� �� ���� 
- Sobel(img, dst, ddepth, dx, dy, ksize = 3)

*/

#include <opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
    Mat img = imread("image/house.jpeg", IMREAD_GRAYSCALE);
    if (img.empty())
    {
        std::cerr << "Image not found!" << std::endl;
        return -1;
    }

    Mat dst_h, dst_v;

    Sobel(img, dst_h, CV_16S, 1, 0);
    Sobel(img, dst_v, CV_16S, 0, 1);

    Mat edges(dst_h.rows, dst_h.cols, CV_8UC1);
    for (int j = 0; j < dst_h.rows; j++)
    {
        for (int i = 0; i < dst_h.cols; i++)
        {
            short int grad_mag = abs(dst_h.at<short>(j, i)) + abs(dst_v.at<short>(j, i));

            if (grad_mag > 100)
                edges.at<uchar>(j, i) = 255;
            else
                edges.at<uchar>(j, i) = 0;
        }
    }

    imshow("edges", edges);

    convertScaleAbs(dst_h, dst_h);
    convertScaleAbs(dst_v, dst_v);

    imshow("horizontal derivative", dst_h);
    imshow("vertical derivative", dst_v);
    waitKey(0);

    return 0;
}
