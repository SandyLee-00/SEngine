#include "Vector4.h"

#include <cassert>

#include "MathUtill.h"

const Vector4 Vector4::Zero(0.f, 0.f, 0.f, 0.f);
const Vector4 Vector4::One(1.f, 1.f, 1.f, 1.f);

const Vector4 Vector4::UnitX(1.f, 0.f, 0.f, 0.f);
const Vector4 Vector4::UnitY(0.f, 1.f, 0.f, 0.f);
const Vector4 Vector4::UnitZ(0.f, 0.f, 1.f, 0.f);
const Vector4 Vector4::UnitW(0.f, 0.f, 0.f, 1.f);

void Vector4::Normalize()
{
	*this = GetNormalize();
}

Vector4 Vector4::GetNormalize() const
{
	float squareSum = x * x + y * y + z * z + w * w;
	if (squareSum == 1.f)
	{
		return *this;
	}
	else if (squareSum == 0.f)
	{
		return Vector4::Zero;
	}

	float invLength = Math::InvSqrt(squareSum);
	return Vector4(x * invLength, y * invLength, z * invLength, w * invLength);
}

float Vector4::Dot(const Vector4& inVector) const
{
	return x * inVector.x + y * inVector.y + z * inVector.z + w * inVector.w;
}

Vector4 Vector4::operator+(const Vector4& inVector) const
{
	return Vector4(x + inVector.x, y + inVector.y, z + inVector.z, w + inVector.w);
}

Vector4 Vector4::operator-(const Vector4& inVector) const
{
	return Vector4(x - inVector.x, y - inVector.y, z - inVector.z, w - inVector.w);
}

Vector4 Vector4::operator-() const
{
	return Vector4(-x, -y, -z, -w);
}

Vector4 Vector4::operator*(float InScalar) const
{
	return Vector4(x * InScalar, y * InScalar, z * InScalar, w * InScalar);
}

Vector4 Vector4::operator/(float InScalar) const
{
	return Vector4(x / InScalar, y / InScalar, z / InScalar, w / InScalar);
}

float Vector4::operator[](unsigned char inIndex) const
{
	if (inIndex == 0)
	{
		return x;
	}
	else if (inIndex == 1)
	{
		return y;
	}
	else if (inIndex == 2)
	{
		return z;
	}
	else if (inIndex == 3)
	{
		return w;
	}
	else
	{
		assert(false && "Vector4 inIndex != 0, 1, 2, 3");
		return 0.f;
	}
}

float& Vector4::operator[](unsigned char inIndex)
{
	if (inIndex == 0)
	{
		return x;
	}
	else if (inIndex == 1)
	{
		return y;
	}
	else if (inIndex == 2)
	{
		return z;
	}
	else if (inIndex == 3)
	{
		return w;
	}
	else
	{
		assert(false && "Vector4 inIndex != 0, 1, 2, 3");
		return x;
	}
}
