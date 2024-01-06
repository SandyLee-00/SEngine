#pragma once

#include <array>

#include "Vector3.h"
#include "Plane.h"

enum class BoundCheckResult : unsigned int
{
	Outside = 0,
	Intersect,
	Inside
};

/// <summary>
/// Perspective camera���� ���Ǵ� Frustum
/// Plane 6���� �����Ǿ� ������, ������ Plane�� Normal�� D���� ������ �ִ�.
/// 
/// 240106 �̼���
/// </summary>
struct Frustum
{
	// Constructors
	Frustum() = default;

	// Public Methods
	

	// Properties
	std::array<Plane, 6> Planes;
};

