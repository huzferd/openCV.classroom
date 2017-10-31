#include <iostream>
#include "LabWorkOne.h"
#include "LabWorkTwo.h"
#include "LabWorkThree.h"
#include "LabWorkFour.h"

using namespace std;

int main(int argc, const char** argv)
{
    int i;
    char * imageName = "image.jpg";
    cout << "Enter lab work number:" << endl;
    cin >> i;
    cout << "Lab work #" << i << endl;

    switch (i)
    {
    case 1:
    {
        LabWorkOne lab1;
        lab1.Run();
        break;
    }
    case 2:
    {
        LabWorkTwo lab2;
        lab2.Run(imageName);
        break;
    }
    case 3:
    {
        LabWorkThree lab3;
        lab3.Run(imageName);
        break;
    }
    case 4:
    {
        LabWorkFour lab4;
        lab4.Run(imageName);
            break;
    }
    default:
        break;
    }

    return 0;
}