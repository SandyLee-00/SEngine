#include "Transform.h"
#include "MathUtill.h"

Transform::Transform(const Matrix4x4& inMatrix)
{
	
}

void Transform::SetTransformMatrix(const Matrix4x4& inMatrix)
{

}

Matrix4x4 Transform::GetTransformMatrix() const
{
	return Matrix4x4();
}

void Transform::AddYawRotation(float inYawDegree)
{

}

void Transform::AddPitchRotation(float inPitchDegree)
{

}

void Transform::AddRollRotation(float inRollDegree)
{

}

Transform Transform::Inverse() const
{
	Vector3 reciprocalScale = Vector3::Zero;

	// 1 / 0 아닌지 체크하기
	if (!abs(scale.x - 0.0f) <= Math::SMALL_NUMBER)
	{
		reciprocalScale.x = 1.0f / scale.x;
	}
	if (!abs(scale.y - 0.0f) <= Math::SMALL_NUMBER)
	{
		reciprocalScale.y = 1.0f / scale.y;
	}
	if (!abs(scale.z - 0.0f) <= Math::SMALL_NUMBER)
	{
		reciprocalScale.z = 1.0f / scale.z;
	}


}
