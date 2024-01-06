#pragma once

#include <vector>
#include "Vector3.h"

/// <summary>
/// 3D���� �ڽ� ǥ��
/// �ڽ�-�ڽ� �浹
/// 
/// 240105 �̼���
/// </summary>
struct Box
{
	// Constructors
	Box() = default;
	Box(const std::vector<Vector3>& points);

	// Public Methods
	bool IsInside(const Vector3& inPoint) const;
	bool IsIntersect(const Box& otherBox) const;

	// Properties
	Vector3 min;
	Vector3 max;
};

