#include "Sphere.h"
#include "MathUtill.h"

/// <summary>
/// Vector3 모든 점들 포함하는 최소 크기의 구 만들기
/// </summary>
/// <param name="points"></param>
Sphere::Sphere(const std::vector<Vector3>& points)
{
	size_t cnt = points.size();
	if (cnt == 0)
	{
		return;
	}

	// 모든 점들의 평균 구하기
	Vector3 sum(0.f, 0.f, 0.f);
	for (const auto& v : points)
	{
		sum += v;
	}
	center = sum / (float)cnt;

	// 모든 점들 중 가장 먼 점 찾기
	Vector3 farthestPoint = (*std::max_element(points.begin(), points.end(),
		[&](Vector3 const& lhs, Vector3 const& rhs)
		{
			return (center - lhs).SizeSquared() < (center - rhs).SizeSquared();
		}));

	radius = sqrtf((farthestPoint - center).SizeSquared());
}

bool Sphere::IsInside(const Vector3& point) const
{
	return ((center - point).SizeSquared() <= (radius * radius));
}

bool Sphere::IsIntersect(const Sphere& otherSphere) const
{
	float radiusSum = radius + otherSphere.radius;
	return (center - otherSphere.center).SizeSquared() <= (radiusSum * radiusSum);
}
