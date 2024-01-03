#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

/// <summary>
/// Position + Rotation + Scale�� ���� 3D Transform
/// 4x4 ��ķ� ǥ��
/// 
/// https://docs.unity3d.com/ScriptReference/Transform.html
/// object�� ��ġ, ȸ�� �� ������ �����մϴ�.
/// ���� ��� ������Ʈ���� Ʈ�������� �ֽ��ϴ�. 
/// Ʈ�������� ������Ʈ�� ��ġ, ȸ�� �� ������ �����ϰ� �����ϴ� �� ���˴ϴ�. 
/// ��� Ʈ�������� ���� Ʈ�������� ���� �� ������, �̸� ���� ��ġ, ȸ�� �� ������ ���������� ������ �� �ֽ��ϴ�. 
/// �̰��� ���� ���� �гο� ǥ�õǴ� ���� �����Դϴ�. 
/// ���� �����ڸ� �����ϹǷ� �̸� ����Ͽ� �ڽ��� �ݺ��� �� �ֽ��ϴ�:
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

