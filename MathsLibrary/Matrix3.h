#pragma once
#include "Vector3.h"
// Column Major 3x3 Matrix
struct Matrix3
{
	union
	{
		struct
		{
			float m1, m2, m3, m4, m5, m6, m7, m8, m9;
		};
		float m[9];
		float mm[3][3];
		Vector3 axis[3];
	};
	
	Matrix3();
    Matrix3(float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9);
    Matrix3 Transposed() const;
    Vector3 GetRow(int i) const;
    void RotateX(float radians);
    void RotateY(float radians);
    void RotateZ(float radians);
    void Set(const Matrix3& mat);

    // mutable access to each element
    float& operator[](int dim);
    // const-qualified access to each element
    const float& operator[](int dim) const;

    Matrix3 operator*(Matrix3 rhs) const;
    Vector3 operator *(Vector3 rhs) const;

    std::string ToString() const;

};

static Matrix3 MakeIdentity()
{
    Matrix3 identity;
	//xAxis
    identity.m1 = 1;
    identity.m2 = 0;
    identity.m3 = 0;

	//yAxis
    identity.m4 = 0;
    identity.m5 = 1;
    identity.m6 = 0;

	//zAxis
    identity.m7 = 0;
    identity.m8 = 0;
    identity.m9 = 1;

    return identity;
}


//Param: r is radians
static Matrix3 MakeRotateX(float r)
{
    return Matrix3(1, 0, 0, //xAxis
                   0, cosf(r), -sinf(r), //yAxis
                   0, sinf(r), cosf(r)); //zAxis
}
//Param: r is radians
static Matrix3 MakeRotateY(float r)
{
    return Matrix3(cosf(r), 0, sinf(r), //xAxis
                   0, 1, 0, //yAxis
                   -sinf(r), 0 ,cosf(r)); //zAxis
}
//Param: r is radians
static Matrix3 MakeRotateZ(float r)
{
    return Matrix3(cosf(r), -sinf(r), 0, //xAxis
                   sinf(r), cosf(r), 0, //yAxis
                   0, 0, 1); //zAxis
}

static Matrix3 MakeEuler(float pitch, float yaw, float roll)
{
    Matrix3 x = MakeRotateX(pitch);
    Matrix3 y = MakeRotateY(yaw);
    Matrix3 z = MakeRotateZ(roll);

    return (z * y * x);
}

static Matrix3 MakeScale(float xScale, float yScale, float zScale)
{
    return Matrix3(xScale, 0, 0,
                   0, yScale, 0,
                   0, 0, zScale);
}
static Matrix3 MakeScale(Vector3 scale)
{
    return MakeScale(scale.x, scale.y, scale.z);
}