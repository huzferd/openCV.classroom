#include "LabWorkTwo.h"
#include <cv.h>
#include <highgui.h>

using namespace cv;

LabWorkTwo::LabWorkTwo()
{
}

int LabWorkTwo::Calc(int x, int r1, int s1, int r2, int s2)
{
    float result;
    if (0 <= x && x <= r1) {
        result = s1 / r1 * x;
    }
    else if (r1 < x && x <= r2) {
        result = ((s2 - s1) / (r2 - r1)) * (x - r1) + s1;
    }
    else if (r2 < x && x <= 255) {
        result = ((255 - s2) / (255 - r2)) * (x - r2) + s2;
    }

    return (int)result;
}

void LabWorkTwo::Run(char* imageName)
{
    IplImage* src = 0;
    IplImage* dst = 0;

    src = cvLoadImage(imageName);
    dst = cvCloneImage(src);

    int r1 = 70, s1 = 0, r2 = 140, s2 = 255;

    int nchannels = src->nChannels;
    int step = src->widthStep;

    uchar *data = (uchar*)src->imageData;

    for (int i = 0; i < src->height; i++) {
        for (int j = 0; j < src->width; j++) {
            int r = data[i*src->widthStep + j* src->nChannels + 0];
            data[i*src->widthStep + j* src->nChannels + 0] = Calc(r, r1, s1, r2, s2);

            int g = data[i*src->widthStep + j* src->nChannels + 1];
            data[i*src->widthStep + j* src->nChannels + 1] = Calc(g, r1, s1, r2, s2);

            int b = data[i*src->widthStep + j* src->nChannels + 2];
            data[i*src->widthStep + j* src->nChannels + 2] = Calc(b, r1, s1, r2, s2);
        }
    }

    cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
    cvShowImage("original", dst);

    cvNamedWindow("new", CV_WINDOW_AUTOSIZE);
    cvShowImage("new", src);

    cvWaitKey(0);

    cvReleaseImage(&src);
    cvReleaseImage(&dst);

    cvDestroyWindow("original");
    cvDestroyWindow("new");

}

LabWorkTwo::~LabWorkTwo()
{
}
