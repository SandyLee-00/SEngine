#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

/// <summary>
/// Position + Rotation + Scale�� ���� 3D Transform
/// Transform <-> Matrix4x4 ��ȯ
/// Transform GameObject ���� X Parent-Child ���� ǥ�� X
/// 
/// TODO: Component�� �и�
/// 
/// https://docs.unity3d.com/ScriptReference/Transform.html
/// object�� ��ġ, ȸ�� �� ������ ����, �����մϴ�.
/// ���� ��� ������Ʈ���� Ʈ�������� �ֽ��ϴ�. 
/// 
/// 240103 �̼���
/// </summary>
struct Transform
{
	// Constructors
	Transform() = default;
	Transform(const Vector3& inPosition, const Quaternion& inRotation, const Vector3& inScale) : position(inPosition), rotation(inRotation), scale(inScale) {}
	Transform(const Matrix4x4& inMatrix);

	// Public Methods
	void SetPosition(const Vector3& inPosition) { position = inPosition; }
	// void SetRotation(const Rotator& inRotator) { rotation = Quaternion(inRotator); })
	void SetRotation(const Quaternion& inRotation) { rotation = inRotation; }
	void SetScale(const Vector3& inScale) { scale = inScale; }
	void SetTransformMatrix(const Matrix4x4& inMatrix);

	Vector3 GetPosition() const { return position; }
	Quaternion GetRotation() const { return rotation; }
	Vector3 GetScale() const { return scale; }
	Matrix4x4 GetTransformMatrix() const;

	void AddPosition(const Vector3& inPosition) { position += inPosition; }
	void AddYawRotation(float inYawDegree);
	void AddPitchRotation(float inPitchDegree);
	void AddRollRotation(float inRollDegree);


	// Operators

	// Properties
	Vector3 position;
	Quaternion rotation;
	Vector3 scale;
};

