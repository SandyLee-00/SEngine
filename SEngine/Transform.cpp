#include "Transform.h"

#include "MathUtill.h"
#include "GameObject.h"

Transform::Transform(const Matrix4x4& inMatrix)
{
	// ������ ȸ�� ��ĸ� �и�
	Matrix3x3 rotScaleMatrix = inMatrix.ToMatrix3x3();
	position = Vector3(inMatrix[3].x, inMatrix[3].y, inMatrix[3].z);

	// ũ�� ��ĺ��� ���Ѵ�. 
	scale = Vector3::Zero;
	const float squareSumX = rotScaleMatrix[0].SizeSquared();
	const float squareSumY = rotScaleMatrix[1].SizeSquared();
	const float squareSumZ = rotScaleMatrix[2].SizeSquared();

	if (squareSumX > Math::SMALL_NUMBER) { scale.x = sqrtf(squareSumX); }
	if (squareSumY > Math::SMALL_NUMBER) { scale.y = sqrtf(squareSumY); }
	if (squareSumZ > Math::SMALL_NUMBER) { scale.z = sqrtf(squareSumZ); }

	// ũ�� ��Ҹ� ���� ���� ���� ����� ���Ѵ�.
	rotScaleMatrix[0] /= squareSumX;
	rotScaleMatrix[1] /= squareSumY;
	rotScaleMatrix[2] /= squareSumZ;

	// ������� ��ȯ�Ѵ�.
	rotation = Quaternion(rotScaleMatrix);
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
	if (!Math::EqualsInTolerance(scale.x, 0.f)) reciprocalScale.x = 1.f / scale.x;
	if (!Math::EqualsInTolerance(scale.y, 0.f)) reciprocalScale.y = 1.f / scale.y;
	if (!Math::EqualsInTolerance(scale.z, 0.f)) reciprocalScale.z = 1.f / scale.z;

	Transform result;
	result.scale = reciprocalScale;
	result.rotation = rotation.Inverse();
	result.position = result.scale * (result.rotation * -position);

	return result;
}

/// <summary>
/// TODO: index ���� �ٸ� ������� ã��
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
GameObject* Transform::GetChildGameObject(int index)
{
	if (index < 0 || index >= m_children.size())
	{
		return nullptr;
	}
	return m_children[index];
}

void Transform::SetParentGameObject(GameObject* parent)
{
	// parent null�� �����ϱ�
	if (parent == nullptr)
	{
		m_parent = nullptr;
		return;
	}

	// ���� m_parent�� ������ parent�� ������ ��
	if (m_parent != nullptr && m_parent == parent)
	{
		return;
	}

	if (m_parent != nullptr)
	{
		// �ڽ� ����Ʈ�� parent�� �ִ��� Ȯ��
		for (auto child : m_children)
		{
			if (child == parent)
			{
				return;
			}
		}

		// m_parent->RemoveChildGameObject(this);
		m_parent = parent;
	}
}

void Transform::SetChildGameObject(GameObject* child)
{

}
