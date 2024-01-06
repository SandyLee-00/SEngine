#pragma once

#include <array>

#include "Vector3.h"
#include "Plane.h"
#include "Sphere.h"
#include "Box.h"

enum class BoundCheckResult : unsigned int
{
	Outside = 0,
	Intersect,
	Inside
};

/// <summary>
/// Perspective camera에서 사용되는 Frustum
/// Plane 6개로 구성되어 있으며, 각각의 Plane은 Normal과 D값을 가지고 있다.
/// 
/// 240106 이서영
/// </summary>
struct Frustum
{
	// Constructors
	Frustum() = default;

	// Public Methods
	BoundCheckResult CheckBound(const Vector3& inPoint) const;
	BoundCheckResult CheckBound(const Sphere& inSphere) const;
	BoundCheckResult CheckBound(const Box& inBox) const;

	// Properties
	std::array<Plane, 6> planes;
};

