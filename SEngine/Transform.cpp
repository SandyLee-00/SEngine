#include "Transform.h"

#include <cassert>
#include "MathUtill.h"
#include "GameObject.h"

Transform::Transform(const Matrix4x4& inMatrix)
{
	// ������ ȸ�� ��ĸ� �и�
	Matrix3x3 rotScaleMatrix = inMatrix.ToMatrix3x3();
	m_position = Vector3(inMatrix[3].x, inMatrix[3].y, inMatrix[3].z);

	// ũ�� ��ĺ��� ���Ѵ�. 
	m_scale = Vector3::Zero;
	const float squareSumX = rotScaleMatrix[0].SizeSquared();
	const float squareSumY = rotScaleMatrix[1].SizeSquared();
	const float squareSumZ = rotScaleMatrix[2].SizeSquared();

	if (squareSumX > Math::SMALL_NUMBER) { m_scale.x = sqrtf(squareSumX); }
	if (squareSumY > Math::SMALL_NUMBER) { m_scale.y = sqrtf(squareSumY); }
	if (squareSumZ > Math::SMALL_NUMBER) { m_scale.z = sqrtf(squareSumZ); }

	// ũ�� ��Ҹ� ���� ���� ���� ����� ���Ѵ�.
	rotScaleMatrix[0] /= squareSumX;
	rotScaleMatrix[1] /= squareSumY;
	rotScaleMatrix[2] /= squareSumZ;

	// ������� ��ȯ�Ѵ�.
	m_rotation = Quaternion(rotScaleMatrix);
}

Matrix4x4 Transform::GetMatrix() const
{
	return Matrix4x4(
		Vector4(GetXAxis() * m_scale.x, false),
		Vector4(GetYAxis() * m_scale.y, false),
		Vector4(GetZAxis() * m_scale.z, false),
		Vector4(m_position, true)
	);
}

void Transform::AddYawRotation(float inYawDegree)
{
	Rotator yawRotator = m_rotation.ToRotator();
	yawRotator.yaw += inYawDegree;
	yawRotator.Clamp();
	m_rotation = Quaternion(yawRotator);
}

void Transform::AddPitchRotation(float inPitchDegree)
{
	Rotator pitchRotator = m_rotation.ToRotator();
	pitchRotator.pitch += inPitchDegree;
	pitchRotator.Clamp();
	m_rotation = Quaternion(pitchRotator);
}

void Transform::AddRollRotation(float inRollDegree)
{
	Rotator rollRotator = m_rotation.ToRotator();
	rollRotator.roll += inRollDegree;
	rollRotator.Clamp();
	m_rotation = Quaternion(rollRotator);
}

void Transform::Rotate(float inYawDegree, float inPitchDegree, float inRollDegree)
{
	AddYawRotation(inYawDegree);
	AddPitchRotation(inPitchDegree);
	AddRollRotation(inRollDegree);
}

Transform Transform::Inverse() const
{
	Vector3 reciprocalScale = Vector3::Zero;
	if (!Math::EqualsInTolerance(m_scale.x, 0.f)) reciprocalScale.x = 1.f / m_scale.x;
	if (!Math::EqualsInTolerance(m_scale.y, 0.f)) reciprocalScale.y = 1.f / m_scale.y;
	if (!Math::EqualsInTolerance(m_scale.z, 0.f)) reciprocalScale.z = 1.f / m_scale.z;

	Transform result;
	result.m_scale = reciprocalScale;
	result.m_rotation = m_rotation.Inverse();
	result.m_position = result.m_scale * (result.m_rotation * -m_position);

	return result;
}

Transform* Transform::GetChild(int index) const
{
	if (index < 0 || index >= m_children.size())
	{
		assert(index >= 0 && index < m_children.size() && "Transform* Transform::GetChild(int index) const / if(index < 0 || index >= children.size())");
		return nullptr;
	}
	return m_children[index];
}

std::vector<Transform*>& Transform::GetChildren()
{
	return m_children;
}

Transform* Transform::GetParent() const
{
	return m_parent;
}

void Transform::SetParent(Transform* inParent)
{
	// # �θ� ���� ��� : �θ� �߰��ϰ� �θ��� �ڽ����� �߰�
	if (this->m_parent == nullptr)
	{
		this->m_parent = inParent;
		inParent->m_children.push_back(this);
	}

	// # �θ� ���� ��� : ���� �θ��� �ڽ� ��Ͽ��� �����ϰ� �θ� �߰��ϰ� �θ��� �ڽ����� �߰�
	else if (this->m_parent != nullptr)
	{
		// ���� �θ��� �ڽ� ��Ͽ��� ����
		for (auto iter = this->m_parent->m_children.begin(); iter != this->m_parent->m_children.end(); ++iter)
		{
			if (*iter == this)
			{
				this->m_parent->m_children.erase(iter);
				break;
			}
		}

		// �θ� �߰��ϰ� �θ��� �ڽ����� �߰�
		this->m_parent = inParent;
		inParent->m_children.push_back(this);
	}
}

void Transform::SetChild(Transform* inChild)
{
	m_children.push_back(inChild);
}

bool Transform::IsChildOf(const Transform* inParent) const
{
	// �θ� ã�Ƽ� �θ� �ִ��� Ȯ��
	Transform* thisTransform = GetParent();

	// while�� ���� �ö󰡸鼭 �θ� �ִ��� Ȯ��
	while (thisTransform != nullptr)
	{
		// # ���� �θ� ���� ���
		if (thisTransform->GetParent() == nullptr)
		{
			return false;
		}

		// # ���� �θ� inParent�� ���� ���
		else if (thisTransform == inParent)
		{
			return true;
		}

		thisTransform = thisTransform->m_parent;
	}

	return false;
}

