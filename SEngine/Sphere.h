#pragma once

#include <vector>
#include "Vector3.h"

/// <summary>
/// 3D에서 구 표현
/// 구-구 충돌
/// V3 center / float radius
/// 
/// TODO: CalculateBounds 할 때 쓰기 위해서 v3 점들 여러개 넣어서 구 만들기
/// 
/// 240105 이서영
/// </summary>
struct Sphere
{
	// Constructors
	Sphere() = default;
	Sphere(const std::vector<Vector3>& points);

	// Public Methods
	bool IsInside(const Vector3& point) const;
	bool IsIntersect(const Sphere& other) const;

	// Properties
	Vector3 center;
	float radius;
};

