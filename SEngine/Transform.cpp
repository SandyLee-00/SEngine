#include "Transform.h"

#include <cassert>
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

void Transform::Rotate(float inYawDegree, float inPitchDegree, float inRollDegree)
{
	AddYawRotation(inYawDegree);
	AddPitchRotation(inPitchDegree);
	AddRollRotation(inRollDegree);
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

Transform* Transform::GetChild(int index) const
{
	if (index < 0 || index >= children.size())
	{
		assert(index >= 0 && index < children.size() && "Transform* Transform::GetChild(int index) const / if(index < 0 || index >= children.size())");
		return nullptr;
	}
	return children[index];
}

std::vector<Transform*>& Transform::GetChildren()
{
	return children;
}

Transform* Transform::GetParent() const
{
	return parent;
}

void Transform::SetParent(Transform* inParent)
{
	// # �θ� ���� ��� : �θ� �߰��ϰ� �θ��� �ڽ����� �߰�
	if (this->parent == nullptr)
	{
		this->parent = inParent;
		inParent->children.push_back(this);
	}

	// # �θ� ���� ��� : ���� �θ��� �ڽ� ��Ͽ��� �����ϰ� �θ� �߰��ϰ� �θ��� �ڽ����� �߰�
	else if (this->parent != nullptr)
	{
		// ���� �θ��� �ڽ� ��Ͽ��� ����
		for (auto iter = this->parent->children.begin(); iter != this->parent->children.end(); ++iter)
		{
			if (*iter == this)
			{
				this->parent->children.erase(iter);
				break;
			}
		}

		// �θ� �߰��ϰ� �θ��� �ڽ����� �߰�
		this->parent = inParent;
		inParent->children.push_back(this);
	}
}

void Transform::SetChild(Transform* inChild)
{
	children.push_back(inChild);
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

		thisTransform = thisTransform->parent;
	}

	return false;
}

