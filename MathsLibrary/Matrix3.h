#pragma once
#include "Vector3.h"
// Column Major 3x3 Matrix
class Matrix3
{
public:
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

    // mutable access to each element
    float& operator[](int dim);
    // const-qualified access to each element
    const float& operator[](int dim) const;

    Matrix3 operator*(Matrix3 rhs) const;
    Vector3 operator *(Vector3 rhs) const;

    std::string ToString() const;

private:

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

