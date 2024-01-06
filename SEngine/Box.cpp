#include "Box.h"

/// <summary>
/// Vector3 모든 점들 포함하는 최소 크기의 박스 만들기
/// </summary>
/// <param name="points"></param
Box::Box(const std::vector<Vector3>& points)
{
	for (const auto& point : points)
	{
		min.x = std::min(min.x, point.x);
		min.y = std::min(min.y, point.y);
		min.z = std::min(min.z, point.z);

		max.x = std::max(max.x, point.x);
		max.y = std::max(max.y, point.y);
		max.z = std::max(max.z, point.z);
	}
}

bool Box::IsInside(const Vector3& inPoint) const
{
	return (inPoint.x >= min.x && inPoint.x <= max.x) &&
		(inPoint.y >= min.y && inPoint.y <= max.y) &&
		(inPoint.z >= min.z && inPoint.z <= max.z);
}

bool Box::IsIntersect(const Box& otherBox) const
{
	if ((min.x > otherBox.max.x) || (otherBox.min.x > max.x))
	{
		return false;
	}

	if ((min.y > otherBox.max.y) || (otherBox.min.y > max.y))
	{
		return false;
	}

	if ((min.z > otherBox.max.z) || (otherBox.min.z > max.z))
	{
		return false;
	}

	return true;
}
