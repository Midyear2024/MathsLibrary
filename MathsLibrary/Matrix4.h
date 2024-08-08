#pragma once
#include "Vector4.h" 
//Column major 4x4 matrix
struct Matrix4
{
    union {
        struct
        {
            float m1, m2, m3, m4, //xAxis
                  m5, m6, m7, m8, //yAxis
                  m9, m10, m11, m12, //zAxis
                  m13, m14, m15, m16; //translation
        };
        struct {
            Vector4 xAxis;
            Vector4 yAxis;
            Vector4 zAxis;
            Vector4 translation;
        };
        Vector4 axis[4];
        float mm[4][4];
        float m[16];
    };

    Matrix4();
    Matrix4(float m1, float m2, float m3, float m4, 
            float m5, float m6, float m7, float m8,
            float m9, float m10, float m11, float m12,
            float m13, float m14, float m15, float m16);

    void SetScaled(float x, float y, float z);
    void SetRotateX(float radians);
    void Translate(float x, float y, float z);
    Vector4 operator*(const Vector4& v) const;
    Matrix4 operator*(const Matrix4& other) const;
};

// create a static const identity matrix
static const Matrix4 identityM4 = Matrix4(1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1);

