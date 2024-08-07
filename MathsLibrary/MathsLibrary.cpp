// MathsLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3.h"
#include "Constants.h"
#include "Matrix3.h"

using namespace Constants;

#define PRECISION(x) abs(x) < FLOAT_PRECISION ? 0 : x

int main()
{

  
    Matrix3 mat = MakeIdentity();
    mat[6] = 7;
    mat[7] = 8;

    Matrix3 mat1 = MakeIdentity();
    mat1[0] = 5;
    mat1[4] = 5;

    Matrix3 mat2 = mat * mat1;


    std::cout << mat2.ToString();   

    //Vector3 vector { -1, 1, 1 };
    //Vector3 vector1 { -4000, -10, -10000000};

    //vector.Normalise();
    //vector1.Normalise();

    //Vector3 vecPerp = vector.Cross(vector1);
    //vecPerp.Normalise();

    //float dot = vector.Dot(vecPerp);
    //dot = PRECISION(dot);
    //


    //if (dot > 0.5f)
    //{
    //    std::cout << dot << ": " << "Back Stabbed";
    //}
    //else
    //{
    //    std::cout << dot << ": " << "Front Stabbed";
    //}

}

