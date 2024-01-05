#include "Transform.h"
#include "MathUtill.h"
#include "Vector4.h"
#include "Vector3.h"

Transform::Transform(const Matrix4x4& inMatrix)
{
	// 스케일 회전 행렬만 분리
// 	Matrix3x3 rotScaleMatrix = InMatrix.ToMatrix3x3();
// 	Position = InMatrix[3].ToVector3();
// 
// 	// 크기 행렬부터 구한다. 
// 	scale = Vector3::Zero;
// 	const float squareSumX = rotScaleMatrix[0].SizeSquared();
// 	const float squareSumY = rotScaleMatrix[1].SizeSquared();
// 	const float squareSumZ = rotScaleMatrix[2].SizeSquared();
// 
// 	if (squareSumX > Math::SMALL_NUMBER) { scale.x = sqrtf(squareSumX); }
// 	if (squareSumY > Math::SMALL_NUMBER) { scale.y = sqrtf(squareSumY); }
// 	if (squareSumZ > Math::SMALL_NUMBER) { scale.z = sqrtf(squareSumZ); }
// 
// 	// 크기 요소를 나눠 직교 정방 행렬을 구한다.
// 	rotScaleMatrix[0] /= squareSumX;
// 	rotScaleMatrix[1] /= squareSumY;
// 	rotScaleMatrix[2] /= squareSumZ;
// 
// 	// 사원수로 변환한다.
// 	rotation = Quaternion(rotScaleMatrix);
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
