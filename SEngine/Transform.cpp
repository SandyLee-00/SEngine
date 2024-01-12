#include "Transform.h"

#include <cassert>
#include "MathUtill.h"
#include "GameObject.h"

Transform::Transform(const Matrix4x4& inMatrix)
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
	// # 부모가 없을 경우 : 부모를 추가하고 부모의 자식으로 추가
	if (this->parent == nullptr)
	{
		this->parent = inParent;
		inParent->children.push_back(this);
	}

	// # 부모가 있을 경우 : 기존 부모의 자식 목록에서 제거하고 부모를 추가하고 부모의 자식으로 추가
	else if (this->parent != nullptr)
	{
		// 기존 부모의 자식 목록에서 제거
		for (auto iter = this->parent->children.begin(); iter != this->parent->children.end(); ++iter)
		{
			if (*iter == this)
			{
				this->parent->children.erase(iter);
				break;
			}
		}

		// 부모를 추가하고 부모의 자식으로 추가
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
	// 부모를 찾아서 부모가 있는지 확인
	Transform* thisTransform = GetParent();

	// while로 위로 올라가면서 부모가 있는지 확인
	while (thisTransform != nullptr)
	{
		// # 위에 부모가 없을 경우
		if (thisTransform->GetParent() == nullptr)
		{
			return false;
		}

		// # 위에 부모가 inParent와 같을 경우
		else if (thisTransform == inParent)
		{
			return true;
		}

		thisTransform = thisTransform->parent;
	}

	return false;
}

