/*
- 3채널로 된 이미지를 1채널짜리 3개의 이미지로 분리 
- 반대로 채널이 분리된 이미지 여러 개를 하나의 이미지로 만들기

즉, 3개의 1채널 그레이스케일 이미지로 나누는 것 (blue, green, red)로 표현되는

split 함수 사용법 : split(입력이미지 객체, 출력 이미지 저장 객체)
merge 함수 사용법 : merge(입력이미지 객체, 출력 이미지 객체
    - 분리된 channel들을 merge
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
    char wname[10]; // 창 이름, 채널별로 이름 구분 

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
