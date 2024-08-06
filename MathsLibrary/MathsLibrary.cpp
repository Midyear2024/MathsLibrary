// MathsLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector3.h"

int main()
{
    Vector3 vector { 2, 4, 6 };
    Vector3 vector1 { 4, 6, 8};


 /*   std::cout << vector.Magnitude() << " " << vector.MagnitudeSqr() << std::endl;
    std::cout << vector1.Magnitude() << " " << vector1.MagnitudeSqr() << std::endl;
    std::cout << vector.Distance(vector1) << std::endl;
    std::cout << vector1.Distance(vector) << std::endl;*/

    vector.Normalise();
    std::cout << vector.ToString() << " ";
    vector.Normalise();
    std::cout << vector.ToString() << std::endl;
   
    std::cout << vector1.ToString() << " ";
    Vector3 vector3 = vector1.Normalised();
    std::cout << vector3.ToString() << " "  << vector1.ToString() << std::endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
