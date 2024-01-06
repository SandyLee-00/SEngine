#pragma once

#include "Vector3.h"

/// <summary>
/// Frustum 만들기 위해 평면을 정의
/// float d: 원점에서 거리 / Vector3 normal: 노말 방향을 가리키는 벡터
/// 
/// 240106 이서영
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

