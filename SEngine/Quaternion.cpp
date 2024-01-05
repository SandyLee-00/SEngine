#include "Quaternion.h"
#include <cmath>
#include "Rotator.h"
#include "MathUtill.h"
#include "Matrix3x3.h"
#include "Vector3.h"

const Quaternion Quaternion::Identity(0.f, 0.f, 0.f, 1.f);

/// <summary>
/// Euler Angle를 가지고 있는 Rotator를 쿼터니언으로 변환
/// </summary>
/// <param name="inRotator"></param>
Quaternion::Quaternion(const Rotator& inRotator)
{
	float sinPitch = 0.f, sinYaw = 0.f, sinRoll = 0.f;
	float cosPitch = 0.f, cosYaw = 0.f, cosRoll = 0.f;

	sinPitch = sinf(inRotator.pitch * 0.5f);
	sinYaw = sinf(inRotator.yaw * 0.5f);
	sinRoll = sinf(inRotator.roll * 0.5f);

	cosPitch = cosf(inRotator.pitch * 0.5f);
	cosYaw = cosf(inRotator.yaw * 0.5f);
	cosRoll = cosf(inRotator.roll * 0.5f);

	w = sinYaw * sinPitch * sinRoll + cosYaw * cosPitch * cosRoll;
	x = sinYaw * sinRoll * cosPitch + sinPitch * cosRoll * cosYaw;
	y = sinYaw * cosPitch * cosRoll - sinPitch * sinRoll * cosYaw;
	z = -sinYaw * sinPitch * cosRoll + sinRoll * cosYaw * cosPitch;
}

Quaternion::Quaternion(const struct Matrix3x3& inMatrix)
{
	float root = 0.f;
	float trace = inMatrix[0][0] + inMatrix[1][1] + inMatrix[2][2];

	// 각 행 벡터가 단위 벡터인지 확인
	if (!Math::EqualsInTolerance(inMatrix[0].SizeSquared(), 1.f) || !Math::EqualsInTolerance(inMatrix[1].SizeSquared(), 1.f) || !Math::EqualsInTolerance(InMatrix[2].SizeSquared(), 1.f))
	{
		*this = Quaternion::Identity;
	}

	if (trace > 0.f)
	{
		// W 요소를 구하고 나머지 X,Y,Z를 계산zd
		root = sqrtf(trace + 1.f);
		w = 0.5f * root;
		root = 0.5f / root;

		x = (inMatrix[1][2] - inMatrix[2][1]) * root;
		y = (inMatrix[2][0] - inMatrix[0][2]) * root;
		z = (inMatrix[0][1] - inMatrix[1][0]) * root;
	}
	else
	{
		unsigned int i = 0;

		// X,Y,Z 중에서 가장 큰 요소를 파악
		if (inMatrix[1][1] > inMatrix[0][0]) { i = 1; }
		if (inMatrix[2][2] > inMatrix[i][i]) { i = 2; }

		// i, j, k 의 순서 지정s
		static const unsigned int next[3] = { 1, 2, 0 };
		unsigned int j = next[i];
		unsigned int k = next[j];

		// 가장 큰 요소의 값을 구하기
		root = sqrtf(inMatrix[i][i] - inMatrix[j][j] - inMatrix[k][k] + 1.f);

		float* qt[3] = { &x, &y, &z };
		*qt[i] = 0.5f * root;

		root = 0.5f / root;

		// 나머지 두 요소의 값을 구하기
		*qt[j] = (inMatrix[i][j] + inMatrix[j][i]) * root;
		*qt[k] = (inMatrix[i][k] + inMatrix[k][i]) * root;

		// 마지막 W 값 구하기
		w = (inMatrix[j][k] - inMatrix[k][j]) * root;
	}
}

Rotator Quaternion::ToRotator() const
{
	Rotator result;
	float sinrCosp = 2 * (w * z + x * y);
	float cosrCosp = 1 - 2 * (z * z + x * x);
	result.roll = Math::ToDegree(atan2f(sinrCosp, cosrCosp));

	float pitchTest = w * x - y * z;
	float asinThreshold = 0.4999995f;
	float sinp = 2 * pitchTest;
	if (pitchTest < -asinThreshold)
	{
		result.pitch = -90.f;
	}
	else if (pitchTest > asinThreshold)
	{
		result.pitch = 90.f;
	}
	else
	{
		result.pitch = Math::ToDegree(asinf(sinp));
	}

	float sinyCosp = 2 * (w * y + x * z);
	float cosyCosp = 1.f - 2 * (x * x + y * y);
	result.yaw = Math::ToDegree(atan2f(sinyCosp, cosyCosp));

	return result;
}

/// <summary>
/// 두 회전 a와 b 사이의 각도를 도 단위로 반환합니다.
/// </summary>
/// <param name="inQuaternion1"></param>
/// <param name="inQuaternion2"></param>
/// <returns></returns>
float Quaternion::Angle(const Quaternion& inQuaternion1, const Quaternion& inQuaternion2)
{
	return 0.0f;
}

/// <summary>
/// z축을 중심으로 z도, x축을 중심으로 x도, y축을 중심으로 y도 회전하는 회전을 반환하며, 이 순서대로 적용됩니다.
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <returns></returns>
Quaternion Quaternion::Euler(float x, float y, float z)
{
	return Quaternion();
}

/// <summary>
/// fromDirectionVector에서 toDirectionVector로 회전하는 회전을 생성합니다.
/// </summary>
/// <param name="fromDirectionVector"></param>
/// <param name="toDirectionVector"></param>
/// <returns></returns>
Quaternion Quaternion::FromToRotation(const Vector3& fromDirectionVector, const Vector3& toDirectionVector)
{
	return Quaternion();
}

/// <summary>
/// 지정된 앞쪽 및 위쪽 방향으로 회전을 생성합니다
/// </summary>
/// <param name="forwardVector"></param>
/// <param name="upVector"></param>
/// <returns></returns>
Quaternion Quaternion::LookRotation(const Vector3& forwardVector, const Vector3& upVector /*= Vector3::Up*/)
{
	return Quaternion();
}

/// <summary>
/// 매개변수 alpha는 [0, 1] 범위로 고정되며, 쿼터니언 a와 b 사이를 비율 inRatio로 구형으로 보간합니다.
/// </summary>
/// <param name="startQuaternion"></param>
/// <param name="endQuaternion"></param>
/// <param name="alpha"></param>
/// <returns></returns>
Quaternion Quaternion::Slerp(const Quaternion& startQuaternion, const Quaternion& endQuaternion, float inRatio)
{
	Quaternion q1 = startQuaternion, q2 = endQuaternion;

	// 사원수의 내적 구하기
	float dot = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

	// 내적 값이 0보다 작으면 최단거리를 사용하도록 방향을 전환
	if (dot < 0.0f) {
		q1 = -q1;
		dot = -dot;
	}

	float alpha = 1.f, beta = 0.f;
	// 두 사원수의 사잇각이 작으면 선형 보간으로 수행
	if (dot > 0.9995f)
	{
		alpha = 1.0f - inRatio;
		beta = inRatio;
	}
	else
	{
		const float theta = acosf(dot);
		const float invSin = 1.f / sinf(theta);
		alpha = sinf((1.f - inRatio) * theta) * invSin;
		beta = sinf(inRatio * theta) * invSin;
	}

	Quaternion result;
	result.x = alpha * q1.x + beta * q2.x;
	result.y = alpha * q1.y + beta * q2.y;
	result.z = alpha * q1.z + beta * q2.z;
	result.w = alpha * q1.w + beta * q2.w;

	return result;
}

Quaternion Quaternion::operator-() const
{
	return Quaternion(-x, -y, -z, -w);
}

Vector3 Quaternion::operator*(const Vector3& inVector) const
{
	Vector3 q(x, y, z);
	Vector3 t = q.Cross(inVector) * 2.f;
	
	Vector3 result = inVector + (t * w) + q.Cross(t);
	return result;
}
