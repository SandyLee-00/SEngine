#pragma once

#include "Vector3.h"

/// <summary>
/// 회전을 표현하는 Quaternion 구조체
/// float X Y Z W
/// 
/// TODO: 써보고 다른 곳에서 필요한 내용 추가하기
/// 
/// 240103 이서영
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
	// TODO: 축 + 각도 / Rotator / Vector3 / Matrix3x3

	// Public Methods

	// Static Methods


};

