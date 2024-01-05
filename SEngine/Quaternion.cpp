#include "Quaternion.h"
#include <cmath>
#include "Rotator.h"
#include "MathUtill.h"
#include "Matrix3x3.h"
#include "Vector3.h"

const Quaternion Quaternion::Identity(0.f, 0.f, 0.f, 1.f);

/// <summary>
/// Euler Angle�� ������ �ִ� Rotator�� ���ʹϾ����� ��ȯ
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

	// �� �� ���Ͱ� ���� �������� Ȯ��
	if (!Math::EqualsInTolerance(inMatrix[0].SizeSquared(), 1.f) || !Math::EqualsInTolerance(inMatrix[1].SizeSquared(), 1.f) || !Math::EqualsInTolerance(InMatrix[2].SizeSquared(), 1.f))
	{
		*this = Quaternion::Identity;
	}

	if (trace > 0.f)
	{
		// W ��Ҹ� ���ϰ� ������ X,Y,Z�� ���zd
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

		// X,Y,Z �߿��� ���� ū ��Ҹ� �ľ�
		if (inMatrix[1][1] > inMatrix[0][0]) { i = 1; }
		if (inMatrix[2][2] > inMatrix[i][i]) { i = 2; }

		// i, j, k �� ���� ����s
		static const unsigned int next[3] = { 1, 2, 0 };
		unsigned int j = next[i];
		unsigned int k = next[j];

		// ���� ū ����� ���� ���ϱ�
		root = sqrtf(inMatrix[i][i] - inMatrix[j][j] - inMatrix[k][k] + 1.f);

		float* qt[3] = { &x, &y, &z };
		*qt[i] = 0.5f * root;

		root = 0.5f / root;

		// ������ �� ����� ���� ���ϱ�
		*qt[j] = (inMatrix[i][j] + inMatrix[j][i]) * root;
		*qt[k] = (inMatrix[i][k] + inMatrix[k][i]) * root;

		// ������ W �� ���ϱ�
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
/// �� ȸ�� a�� b ������ ������ �� ������ ��ȯ�մϴ�.
/// </summary>
/// <param name="inQuaternion1"></param>
/// <param name="inQuaternion2"></param>
/// <returns></returns>
float Quaternion::Angle(const Quaternion& inQuaternion1, const Quaternion& inQuaternion2)
{
	return 0.0f;
}

/// <summary>
/// z���� �߽����� z��, x���� �߽����� x��, y���� �߽����� y�� ȸ���ϴ� ȸ���� ��ȯ�ϸ�, �� ������� ����˴ϴ�.
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
/// fromDirectionVector���� toDirectionVector�� ȸ���ϴ� ȸ���� �����մϴ�.
/// </summary>
/// <param name="fromDirectionVector"></param>
/// <param name="toDirectionVector"></param>
/// <returns></returns>
Quaternion Quaternion::FromToRotation(const Vector3& fromDirectionVector, const Vector3& toDirectionVector)
{
	return Quaternion();
}

/// <summary>
/// ������ ���� �� ���� �������� ȸ���� �����մϴ�
/// </summary>
/// <param name="forwardVector"></param>
/// <param name="upVector"></param>
/// <returns></returns>
Quaternion Quaternion::LookRotation(const Vector3& forwardVector, const Vector3& upVector /*= Vector3::Up*/)
{
	return Quaternion();
}

/// <summary>
/// �Ű����� alpha�� [0, 1] ������ �����Ǹ�, ���ʹϾ� a�� b ���̸� ���� inRatio�� �������� �����մϴ�.
/// </summary>
/// <param name="startQuaternion"></param>
/// <param name="endQuaternion"></param>
/// <param name="alpha"></param>
/// <returns></returns>
Quaternion Quaternion::Slerp(const Quaternion& startQuaternion, const Quaternion& endQuaternion, float inRatio)
{
	Quaternion q1 = startQuaternion, q2 = endQuaternion;

	// ������� ���� ���ϱ�
	float dot = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

	// ���� ���� 0���� ������ �ִܰŸ��� ����ϵ��� ������ ��ȯ
	if (dot < 0.0f) {
		q1 = -q1;
		dot = -dot;
	}

	float alpha = 1.f, beta = 0.f;
	// �� ������� ���հ��� ������ ���� �������� ����
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
