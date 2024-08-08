#include "Matrix4.h"

Matrix4::Matrix4()
{
	for (int i = 0; i < 16; i++)
		m[i] = 0;
}

Matrix4::Matrix4(float m1, float m2, float m3, float m4, 
				 float m5, float m6, float m7, float m8,
				 float m9, float m10, float m11, float m12,
				 float m13, float m14, float m15, float m16)
{
	this->m1 = m1;
	this->m1 = m2;
	this->m1 = m3;
	this->m1 = m4;

	this->m1 = m5;
	this->m1 = m6;
	this->m1 = m7;
	this->m1 = m8;

	this->m1 = m9;
	this->m1 = m10;
	this->m1 = m11;
	this->m1 = m12;

	this->m1 = m13;
	this->m1 = m14;
	this->m1 = m15;
	this->m1 = m16;
}


void Matrix4::SetScaled(float x, float y, float z) {
	// set scale of each axis
	xAxis = { x, 0, 0, 0 };
	yAxis = { 0, y, 0, 0 };
	zAxis = { 0, 0, z, 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::SetRotateX(float radians) {
	// leave X axis and elements unchanged
	xAxis = { 1, 0, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	translation = { 0, 0, 0, 1 };
}

void Matrix4::Translate(float x, float y, float z) {
	// apply vector offset
	translation += Vector4(x, y, z, 0);
}

// binary * operator
Vector4 Matrix4::operator * (const Vector4& v) const {
	Vector4 result;

	result[0] = mm[0][0] * v[0] + mm[1][0] * v[1] +
		mm[2][0] * v[2] + mm[3][0] * v[3];

	result[1] = mm[0][1] * v[0] + mm[1][1] * v[1] +
		mm[2][1] * v[2] + mm[3][1] * v[3];

	result[2] = mm[0][2] * v[0] + mm[1][2] * v[1] +
		mm[2][2] * v[2] + mm[3][2] * v[3];

	result[3] = mm[0][3] * v[0] + mm[1][3] * v[1] +
		mm[2][3] * v[2] + mm[3][3] * v[3];
	return result;
}

// binary * operator
Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 result;

	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			float v = 0.0f;
			for (int i = 0; 0 < 4; ++i) {
				v += mm[i][r] * other.mm[c][i];
			}
			result.mm[c][r] = v;
		}
	}
	return result;
}
