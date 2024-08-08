#pragma once
#include <math.h>
#include "Constants.h"
#include <stdexcept>
struct Vector4
{
    union {
        struct {
            float x, y, z, w;
        };
        struct { float r, g, b, a; };
        float data[4];
        
    };
    Vector4();
    Vector4(float x, float y, float z, float w);

    Vector4& operator+=(const Vector4& other);
    Vector4& operator -= (const Vector4& other);
    Vector4& operator -= (float& scalar);
    float& operator[](const int index);
    float operator[](const int index) const;
    float Magnitude() const;
    void Normalise();
    float Dot(const Vector4& other) const;

};

