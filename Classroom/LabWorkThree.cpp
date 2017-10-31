#include "LabWorkThree.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>


LabWorkThree::LabWorkThree()
{
}

void LabWorkThree::Run(char * imageName)
{
    IplImage* src = 0;
    IplImage* dst = 0;

    src = cvLoadImage(imageName);
    dst = cvCloneImage(src);

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

LabWorkThree::~LabWorkThree()
{
}
