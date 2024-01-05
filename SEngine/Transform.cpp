#include "Transform.h"
#include "MathUtill.h"
#include "Vector4.h"
#include "Vector3.h"

Transform::Transform(const Matrix4x4& inMatrix)
{
	
}

Matrix4x4 Transform::GetMatrix() const
{
	return Matrix4x4(
		Vector4(GetXAxis() * scale.x, false),
		Vector4(GetYAxis() * scale.y, false),
		Vector4(GetZAxis() * scale.z, false),
		Vector4(position, true)
	);
}

void Transform::AddYawRotation(float inYawDegree)
{
	Rotator yawRotator = rotation.ToRotator();
	yawRotator.yaw += inYawDegree;
	yawRotator.Clamp();
	rotation = Quaternion(yawRotator);
}

void Transform::AddPitchRotation(float inPitchDegree)
{
	Rotator pitchRotator = rotation.ToRotator();
	pitchRotator.pitch += inPitchDegree;
	pitchRotator.Clamp();
	rotation = Quaternion(pitchRotator);
}

void Transform::AddRollRotation(float inRollDegree)
{
	Rotator rollRotator = rotation.ToRotator();
	rollRotator.roll += inRollDegree;
	rollRotator.Clamp();
	rotation = Quaternion(rollRotator);
}

Transform Transform::Inverse() const
{
	Vector3 reciprocalScale = Vector3::Zero;

	// 1 / 0 아닌지 체크하기
	if (abs(scale.x - 0.0f) > Math::SMALL_NUMBER)
	{
		reciprocalScale.x = 1.0f / scale.x;
	}
	if (abs(scale.y - 0.0f) > Math::SMALL_NUMBER)
	{
		reciprocalScale.y = 1.0f / scale.y;
	}
	if (abs(scale.z - 0.0f) > Math::SMALL_NUMBER)
	{
		reciprocalScale.z = 1.0f / scale.z;
	}

	Transform result;
	result.scale = reciprocalScale;
	result.rotation = rotation.Inverse();
	result.position = result.scale * (result.rotation * -position);

	return result;
}
