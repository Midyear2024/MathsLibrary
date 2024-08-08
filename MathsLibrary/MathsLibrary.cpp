// MathsLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3.h"
#include "Constants.h"
#include "Matrix3.h"

using namespace Constants;

#define PRECISION(x) abs(x) < FLOAT_PRECISION ? 0 : x
#define PI 3.14159265359

int main()
{

  
    Matrix3 translationMat = MakeIdentity();
    translationMat[6] = 7;
    translationMat[7] = 8;

    Matrix3 scaleMat = MakeScale(4, 4, 1);
    Matrix3 rotationMat = MakeRotateZ(PI * 0.5f);
    Matrix3 transformMat = translationMat * rotationMat * scaleMat;

    std::cout << translationMat.ToString() << "\n" << transformMat.ToString();

}

