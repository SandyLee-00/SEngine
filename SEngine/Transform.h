#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

/// <summary>
/// Position + Rotation + Scale�� ���� 3D Transform
/// 4x4 ��ķ� ǥ��
/// 
/// 240103 �̼���
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

