#include "Matrix3.h"

Matrix3::Matrix3()
{
	m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.0f;
}

Matrix3::Matrix3(float v1, float v2, float v3, float v4, float v5, float v6, float v7, float v8, float v9)
{
// |   X    |   Y    |   Z   |
    m1 = v1; m4 = v4; m7 = v7;
    m2 = v2; m5 = v5; m8 = v8;
    m3 = v3; m6 = v6; m9 = v9;
}

Matrix3 Matrix3::Transposed() const
{
    return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
}

Vector3 Matrix3::GetRow(int i) const
{
    Vector3 vec;
    switch (i)
    {
        case 0:
            vec = Vector3(m1, m4, m7);
            break;
        case 1:
            vec = Vector3(m2, m5, m8);
            break;
        case 2:
            vec = Vector3(m3, m6, m9);
            break;
    }
    return vec;
}

void Matrix3::RotateX(float radians)
{
}

void Matrix3::RotateY(float radians)
{
}

void Matrix3::RotateZ(float radians)
{
    auto mat = MakeRotateZ(radians);
    Set(*this * mat);
}

void Matrix3::Set(const Matrix3& mat)
{
    for (int i = 0; i < 9; i++)
        m[i] = mat[i];
}

float& Matrix3::operator[](int dim)
{
	return m[dim];
}

const float& Matrix3::operator[](int dim) const
{
	return m[dim];
}

Matrix3 Matrix3::operator*(Matrix3 rhs) const
{
    // stores the return value
    Matrix3 result;
    // iterate through first matrix
    for (int i = 0; i < 3; ++i)
    {
        // current row from first matrix
        Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

        // iterate through second matrix
        for (int j = 0; j < 3; ++j)
        {
            // dot each row with each column and assign to result matrix
            // result is calculated row-by-row
            result.mm[j][i] = row.Dot(rhs.axis[j]);
        }
    }

    return result;
}

Vector3 Matrix3::operator*(Vector3 rhs) const
{
    return Vector3(
        Vector3(m1,m4,m7).Dot(rhs),
        Vector3(m2,m5,m8).Dot(rhs),
        Vector3(m3,m6,m9).Dot(rhs)
    );
}

std::string Matrix3::ToString() const
{
    //make header
    std::string str = ("| xAxis  | | yAxis  | | zAxis  |\n|--------| |--------| |--------| \n");


    for (int i = 0; i < 3; i++)
    {
        Vector3 row = GetRow(i);
        for (int j = 0; j < 3; j++)
        {
            str += "|" + std::to_string(row[j]) + "| ";
        }
        str += "\n";
    }
    return str;
}
