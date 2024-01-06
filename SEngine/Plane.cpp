#include "Plane.h"

float Plane::Distance(const Vector3& inPoint) const
{
	return normal.Dot(inPoint) + d;
}

bool Plane::IsOutside(const Vector3& inPoint) const
{
	return Distance(inPoint) > 0.0f;
}
