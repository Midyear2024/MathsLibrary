#include "Vector4.h"

Vector4::Vector4()
{
    x, y, z, w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4& Vector4::operator+=(const Vector4& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

Vector4& Vector4::operator-=(const Vector4& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

Vector4& Vector4::operator -= (float& scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

float& Vector4::operator[](int index)
{
    return data[index];
}

float Vector4::operator[](const int index) const
{
    return data[index];
}

float Vector4::Magnitude() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

void Vector4::Normalise() {
    const float mag = sqrt(x * x + y * y + z * z + w * w);

    if (mag < Constants::FLOAT_PRECISION) {
        throw std::runtime_error("Its a zero!");
    }


    x /= mag;
    y /= mag;
    z /= mag;
    w /= mag;
}

float Vector4::Dot(const Vector4& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}
