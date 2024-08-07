#pragma once
#include "Constants.h"
#include <string>

struct Vector3 {

private:
	union {
		struct{ float x, y, z; }; //12 bytes (3 floats, 4bytes each)
		struct{ float r, g, b; }; //12 bytes (3 floats, 4bytes each)
		float data[3];            //12 bytes (3 floats, 4bytes each)
	};
	

public:
	Vector3();
	Vector3(const float x, const float y, const float z);
	Vector3(const float value);

	float& operator[](int index);
	const float& operator[](int index) const;

	operator float* ();
	operator const float* () const;

	Vector3 operator+(const Vector3 rhs) const;
	Vector3 operator-(const Vector3 rhs) const;
	Vector3 operator+=(const Vector3 rhs);
	Vector3 operator-=(const Vector3 rhs);

	Vector3 operator*(float scale) const;
	Vector3 operator/(float scale) const;

	bool operator ==(const Vector3 rhs) const;
	bool operator != (const Vector3 rhs) const;
	bool IsEqual(const Vector3 rhs, float precision = Constants::FLOAT_PRECISION) const;


	float Magnitude() const;
	float MagnitudeSqr() const;
	void Normalise();
	Vector3 Normalised() const;

	float Dot(const Vector3& other);
	Vector3 Cross(const Vector3& other) const;

	float Distance(const Vector3& other) const;

	std::string ToString() const;

};

Vector3 operator*(float lhs, Vector3 rhs);

float DotProduct(const Vector3& vec1, const Vector3& vec2);