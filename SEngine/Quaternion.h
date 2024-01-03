#pragma once

#include "Vector3.h"

/// <summary>
/// ȸ���� ǥ���ϴ� Quaternion ����ü
/// float X Y Z W
/// 
/// TODO: �Ẹ�� �ٸ� ������ �ʿ��� ���� �߰��ϱ�
/// 
/// 240103 �̼���
/// </summary>

struct Quaternion
{
	// Static Properties
	static const Quaternion Identity;

	// Properties
	float x;
	float y;
	float z;
	float w;

	// Constructors
	Quaternion() = default;
	Quaternion(float inX, float inY, float inZ, float inW) : x(inX), y(inY), z(inZ), w(inW) {}
	// TODO: �� + ���� / Rotator / Vector3 / Matrix3x3

	// Public Methods

	// Static Methods


};

