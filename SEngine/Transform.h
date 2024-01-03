#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

/// <summary>
/// Position + Rotation + Scale에 대한 3D Transform
/// 4x4 행렬로 표현
/// 
/// https://docs.unity3d.com/ScriptReference/Transform.html
/// object의 위치, 회전 및 배율을 조정합니다.
/// 씬의 모든 오브젝트에는 트랜스폼이 있습니다. 
/// 트랜스폼은 오브젝트의 위치, 회전 및 배율을 저장하고 조작하는 데 사용됩니다. 
/// 모든 트랜스폼은 상위 트랜스폼을 가질 수 있으며, 이를 통해 위치, 회전 및 배율을 계층적으로 적용할 수 있습니다. 
/// 이것이 계층 구조 패널에 표시되는 계층 구조입니다. 
/// 또한 열거자를 지원하므로 이를 사용하여 자식을 반복할 수 있습니다:
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

