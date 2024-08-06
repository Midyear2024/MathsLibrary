#include "Vector3.h"
#include <iostream>
#include <cmath>

Vector3::Vector3() : Vector3{ 0 }
{
}

Vector3::Vector3(const float x, const float y, const float z) : x{x}, y{y}, z{z}
{
	/*
	std::cout << x << " " << r << " " << data[0] << std::endl;
	std::cout << y << " " << g << " " << data[1] << std::endl;
	std::cout << z << " " << b << " " << data[2] << std::endl;*/


}

Vector3::Vector3(const float value) : x{value}, y{value}, z(value)
{


}

float& Vector3::operator[](int index)
{
	return data[index];
}

const float& Vector3::operator[](int index) const
{
	return data[index];
}

Vector3::operator float* ()
{
	return data;
}

Vector3::operator const float* () const
{
	return data;
}

Vector3 Vector3::operator+(const Vector3 rhs) const
{
	Vector3 sum;
	for (int i = 0; i < 3; ++i) {
		sum[i] = data[i] + rhs[i];
	}
	return sum;
}

Vector3 Vector3::operator-(const Vector3 rhs) const
{
	Vector3 sum;
	for (int i = 0; i < 3; ++i) {
		sum[i] = data[i] - rhs[i];
	}
	return sum;
}

Vector3 Vector3::operator+=(const Vector3 rhs)
{
	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] + rhs[i];
	}
	return *this;
}

Vector3 Vector3::operator-=(const Vector3 rhs)
{
	for (int i = 0; i < 3; ++i) {
		data[i] = data[i] - rhs[i];
	}
	return *this;
}

Vector3 Vector3::operator*(float scale) const
{
	return Vector3(x * scale, y * scale, z * scale);
}

Vector3 Vector3::operator/(float scale) const
{
	if (scale == 0) {
		throw std::runtime_error("Attempted to divide by 0");
	}
	return Vector3(x / scale, y / scale, z / scale);
}

bool Vector3::operator==(const Vector3 rhs) const
{
	return IsEqual(rhs);
}

bool Vector3::operator!=(const Vector3 rhs) const
{
	return !(*this == rhs);
}

bool Vector3::IsEqual(const Vector3 rhs, float precision) const
{
	float xDist = fabsf(x - rhs.x);
	float yDist = fabsf(y - rhs.y);
	float zDist = fabsf(z - rhs.z);

	return  xDist < precision &&
		    yDist < precision &&
		    zDist < precision;
}

float Vector3::Magnitude() const
{
	return sqrtf(MagnitudeSqr());
}

float Vector3::MagnitudeSqr() const
{
	return x * x + y * y + z * z;
}

void Vector3::Normalise()
{
	float m = Magnitude();
	if (m < Constants::FLOAT_PRECISION) {
		throw std::runtime_error("Its a zero!");
	}

	x /= m;
	y /= m;
	z /= m;

}

Vector3 Vector3::Normalised() const
{
	Vector3 copy = *this;
	copy.Normalise();
	return copy;
}

float Vector3::Distance(const Vector3& other) const
{
	return (*this - other).Magnitude();
}

std::string Vector3::ToString() const
{
	return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
}



Vector3 operator*(float lhs, Vector3 rhs)
{
	return rhs * lhs;
}
