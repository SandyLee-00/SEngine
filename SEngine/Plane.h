#pragma once

#include "Vector3.h"

/// <summary>
/// Frustum ����� ���� ����� ����
/// float d: �������� �Ÿ� / Vector3 normal: �븻 ������ ����Ű�� ����
/// 
/// 240106 �̼���
/// </summary>
struct Plane
{
	// Constructors
	Plane() = default;

	// Public Methods
	float Distance(const Vector3& inPoint) const;
	bool IsOutside(const Vector3& inPoint) const;

	// Properties
	Vector3 normal;
	float d;
};

