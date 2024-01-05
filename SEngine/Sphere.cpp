#include "Sphere.h"
#include "MathUtill.h"

/// <summary>
/// Vector3 ��� ���� �����ϴ� �ּ� ũ���� �� �����
/// </summary>
/// <param name="points"></param>
Sphere::Sphere(const std::vector<Vector3>& points)
{
	size_t cnt = points.size();
	if (cnt == 0)
	{
		return;
	}

	// ��� ������ ��� ���ϱ�
	Vector3 sum(0.f, 0.f, 0.f);
	for (const auto& v : points)
	{
		sum += v;
	}
	center = sum / (float)cnt;

	// ��� ���� �� ���� �� �� ã��
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
