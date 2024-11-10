/*
- 3ä�η� �� �̹����� 1ä��¥�� 3���� �̹����� �и� 
- �ݴ�� ä���� �и��� �̹��� ���� ���� �ϳ��� �̹����� �����

��, 3���� 1ä�� �׷��̽����� �̹����� ������ �� (blue, green, red)�� ǥ���Ǵ�

split �Լ� ���� : split(�Է��̹��� ��ü, ��� �̹��� ���� ��ü)
merge �Լ� ���� : merge(�Է��̹��� ��ü, ��� �̹��� ��ü
    - �и��� channel���� merge
*/


#include <opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("image/pears.png", IMREAD_COLOR);
    if (img.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    resize(img, img, Size(200, 200.0 * img.rows / img.cols));
    imshow("org", img);

    vector<Mat> channel;
    split(img, channel);
    char wname[10]; // â �̸�, ä�κ��� �̸� ���� 

    for (int i = 0; i < img.channels(); i++)
    {
        snprintf(wname, sizeof(wname), "ch%d", i); 
        imshow(wname, channel[i]);
    }

    Mat merged;
    channel[0] = channel[0] / 2;
    channel[1] = channel[1] / 2;

    merge(channel, merged);
    imshow("mrg", merged);

    waitKey(0);
    return 0;
}
