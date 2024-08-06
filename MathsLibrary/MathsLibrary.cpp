// MathsLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3.h"
#include "Constants.h"


using namespace Constants;

#define PRECISION(x) abs(x) < FLOAT_PRECISION ? 0 : x

int main()
{
    Vector3 vector { -1, 1, 1 };
    Vector3 vector1 { -4000, -10, -10000000};

    vector.Normalise();
    vector1.Normalise();

    Vector3 vecPerp = vector.CrossProduct(vector1);
    vecPerp.Normalise();

    float dot = vector.DotProduct(vecPerp);
    dot = PRECISION(dot);
    


    if (dot > 0.5f)
    {
        std::cout << dot << ": " << "Back Stabbed";
    }
    else
    {
        std::cout << dot << ": " << "Front Stabbed";
    }

}

