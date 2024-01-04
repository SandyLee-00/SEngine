#pragma once

#include "Vector3.h"

/// <summary>
/// Quaternion i = j = k = sqrt(-1) 3가지 축에 대한 회전을 표현
/// float X Y Z W
/// 
/// TODO: Angle / Euler / FromToRotation / LookRotation 구현 필요
/// 
/// https://docs.unity3d.com/ScriptReference/Quaternion.html
/// 쿼터니언은 회전을 표현하는 데 사용됩니다.
/// 크기가 작고 짐벌 락의 영향을 받지 않으며 쉽게 보간할 수 있습니다. 
/// 복소수를 기반으로 하므로 직관적으로 이해하기가 쉽지 않습니다. 
/// 개별 쿼터니언 구성 요소(x,y,z,w)에 액세스하거나 수정하는 경우는 거의 없으며, 
/// 대부분 기존 회전(예: 변환에서)을 가져와서 새로운 회전(예: 두 회전 사이의 부드러운 보간)을 구성하는 데 사용합니다. 
/// 99%의 경우 사용하는 쿼터니언 함수
/// Quaternion.LookRotation, Quaternion.Angle, Quaternion.Euler, Quaternion.Slerp, Quaternion.FromToRotation 및 Quaternion.identity입니다
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
	static float Angle(const Quaternion& inQuaternion1, const Quaternion& inQuaternion2);
	static Quaternion Euler(float x, float y, float z);
	static Quaternion FromToRotation(const Vector3& fromDirectionVector, const Vector3& toDirectionVector);
	static Quaternion LookRotation(const Vector3& forwardVector, const Vector3& upVector = Vector3::Up);
	static Quaternion Slerp(const Quaternion& startQuaternion, const Quaternion& endQuaternion, float alpha);

	// Operators
	Quaternion operator-() const;
};

