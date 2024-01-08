#include "TransformMath.h"
#include "MathUtill.h"
#include "Vector4.h"
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Matrix3x3.h"
#include "Quaternion.h"

TransformMath::TransformMath(const Matrix4x4& inMatrix)
{
	// 스케일 회전 행렬만 분리
	Matrix3x3 rotScaleMatrix = inMatrix.ToMatrix3x3();
	position = Vector3(inMatrix[3].x, inMatrix[3].y, inMatrix[3].z);

	// 크기 행렬부터 구한다. 
	scale = Vector3::Zero;
	const float squareSumX = rotScaleMatrix[0].SizeSquared();
	const float squareSumY = rotScaleMatrix[1].SizeSquared();
	const float squareSumZ = rotScaleMatrix[2].SizeSquared();

	if (squareSumX > Math::SMALL_NUMBER) { scale.x = sqrtf(squareSumX); }
	if (squareSumY > Math::SMALL_NUMBER) { scale.y = sqrtf(squareSumY); }
	if (squareSumZ > Math::SMALL_NUMBER) { scale.z = sqrtf(squareSumZ); }

	// 크기 요소를 나눠 직교 정방 행렬을 구한다.
	rotScaleMatrix[0] /= squareSumX;
	rotScaleMatrix[1] /= squareSumY;
	rotScaleMatrix[2] /= squareSumZ;

	// 사원수로 변환한다.
	rotation = Quaternion(rotScaleMatrix);
}

Matrix4x4 TransformMath::GetMatrix() const
{
	return Matrix4x4(
		Vector4(GetXAxis() * scale.x, false),
		Vector4(GetYAxis() * scale.y, false),
		Vector4(GetZAxis() * scale.z, false),
		Vector4(position, true)
	);
}

void TransformMath::AddYawRotation(float inYawDegree)
{
	Rotator yawRotator = rotation.ToRotator();
	yawRotator.yaw += inYawDegree;
	yawRotator.Clamp();
	rotation = Quaternion(yawRotator);
}

void TransformMath::AddPitchRotation(float inPitchDegree)
{
	Rotator pitchRotator = rotation.ToRotator();
	pitchRotator.pitch += inPitchDegree;
	pitchRotator.Clamp();
	rotation = Quaternion(pitchRotator);
}

void TransformMath::AddRollRotation(float inRollDegree)
{
	Rotator rollRotator = rotation.ToRotator();
	rollRotator.roll += inRollDegree;
	rollRotator.Clamp();
	rotation = Quaternion(rollRotator);
}

TransformMath TransformMath::Inverse() const
{
	Vector3 reciprocalScale = Vector3::Zero;
	if (!Math::EqualsInTolerance(scale.x, 0.f)) reciprocalScale.x = 1.f / scale.x;
	if (!Math::EqualsInTolerance(scale.y, 0.f)) reciprocalScale.y = 1.f / scale.y;
	if (!Math::EqualsInTolerance(scale.z, 0.f)) reciprocalScale.z = 1.f / scale.z;

	TransformMath result;
	result.scale = reciprocalScale;
	result.rotation = rotation.Inverse();
	result.position = result.scale * (result.rotation * -position);

	return result;
}
