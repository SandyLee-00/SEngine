#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

/// <summary>
/// Position + Rotation + Scale에 대한 3D Transform
/// 4x4 행렬로 표현
/// 
/// 240103 이서영
/// </summary>

struct Transform
{
	// Properties
	Vector3 position;
	Quaternion rotation;
	Vector3 scale;

	// Constructors
	Transform() = default;
	// Transform(const Matrix4x4& inMatrix);
};

