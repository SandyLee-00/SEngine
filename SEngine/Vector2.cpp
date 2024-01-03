#include "Vector2.h"
#include "MathUtill.h"

const Vector2 Vector2::Up(0.0f, 1.0f);
const Vector2 Vector2::Down(0.0f, -1.0f);
const Vector2 Vector2::Left(-1.0f, 0.0f);
const Vector2 Vector2::Right(1.0f, 0.0f);

const Vector2 Vector2::Zero(0.0f, 0.0f);
const Vector2 Vector2::One(1.0f, 1.0f);

void Vector2::Normalize()
{
	*this = GetNormalize();
}

Vector2 Vector2::GetNormalize() const
{
	float squareSum = x * x + y * y;
	if (squareSum == 1.f)
	{
		return *this;
	}
	else if (squareSum == 0.f)
	{
		return Vector2::Zero;
	}

	float invLength = Math::InvSqrt(squareSum);
	return Vector2(x, y) * invLength;
}

float Vector2::Dot(const Vector2& inVector) const
{
	return x * inVector.x + y * inVector.y;
}

Vector2 Vector2::operator+(const Vector2& inVector) const
{
	return Vector2(x + inVector.x, y + inVector.y);
}

Vector2 Vector2::operator-(const Vector2& inVector) const
{
	return Vector2(x - inVector.x, y - inVector.y);
}

Vector2 Vector2::operator*(float InScalar) const
{
	return Vector2(x * InScalar, y * InScalar);
}

Vector2 Vector2::operator/(float InScalar) const
{
	return Vector2(x / InScalar, y / InScalar);
}
