#include "Frustum.h"

#include "MathUtill.h"
#include "Plane.h"

BoundCheckResult Frustum::CheckBound(const Vector3& inPoint) const
{
	for (const auto& thisPlane : planes)
	{
		if (thisPlane.IsOutside(inPoint))
		{
			return BoundCheckResult::Outside;
		}
		else if (Math::EqualsInTolerance(thisPlane.Distance(inPoint), 0.f))
		{
			return BoundCheckResult::Intersect;
		}
	}

	return BoundCheckResult::Inside;
}

BoundCheckResult Frustum::CheckBound(const Sphere& inSphere) const
{
	for (const auto& thisPlane : planes)
	{
		if (thisPlane.Distance(inSphere.center) > inSphere.radius)
		{
			return BoundCheckResult::Outside;
		}
		else if (abs(thisPlane.Distance(inSphere.center)) <= inSphere.radius)
		{
			return BoundCheckResult::Intersect;
		}
	}

	return BoundCheckResult::Inside;
}

BoundCheckResult Frustum::CheckBound(const Box& inBox) const
{
	for (const auto& thisPlane : planes)
	{
		Vector3 positivePoint = inBox.min;
		Vector3	negativePoint = inBox.max;

		if (thisPlane.normal.x >= 0.f) 
		{ 
			positivePoint.x = inBox.max.x; 
			negativePoint.x = inBox.min.x; 
		}

		if (thisPlane.normal.y >= 0.f) 
		{ 
			positivePoint.y = inBox.max.y; 
			negativePoint.y = inBox.min.y; 
		}
		if (thisPlane.normal.z >= 0.f) 
		{ 
			positivePoint.z = inBox.max.z; 
			negativePoint.z = inBox.min.z; 
		}

		if (thisPlane.Distance(negativePoint) > 0.f)
		{
			return BoundCheckResult::Outside;
		}
		if (thisPlane.Distance(negativePoint) <= 0.f && thisPlane.Distance(positivePoint) >= 0.f)
		{
			return BoundCheckResult::Intersect;
		}
	}

	return BoundCheckResult::Inside;
}
