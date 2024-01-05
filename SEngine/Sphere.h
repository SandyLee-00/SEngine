#pragma once

#include <vector>
#include "Vector3.h"

/// <summary>
/// 3D���� �� ǥ��
/// ��-�� �浹
/// V3 center / float radius
/// 
/// TODO: CalculateBounds �� �� ���� ���ؼ� v3 ���� ������ �־ �� �����
/// 
/// 240105 �̼���
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

