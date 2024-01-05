#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"
#include "Rotator.h"

/// <summary>
/// Position + Rotation + Scale�� ���� 3D Transform
/// Transform <-> Matrix4x4 ��ȯ
/// Transform GameObject ���� X Parent-Child ���� ǥ�� X
/// 
/// TODO: Component�� �и�
/// 
/// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Core/Public/Math/TransformCalculus.h
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
	Transform(const Vector3 inPosition) : position(inPosition) {}
	Transform(const Vector3& inPosition, const Quaternion& inRotation, const Vector3& inScale) : position(inPosition), rotation(inRotation), scale(inScale) {}
	Transform(const Matrix4x4& inMatrix);

	// Public Methods
	void SetPosition(const Vector3& inPosition) { position = inPosition; }
	void SetRotation(const Rotator& inRotator) { rotation = Quaternion(inRotator); }
	void SetRotation(const Quaternion& inRotation) { rotation = inRotation; }
	void SetScale(const Vector3& inScale) { scale = inScale; }

	Vector3 GetPosition() const { return position; }
	Quaternion GetRotation() const { return rotation; }
	Vector3 GetScale() const { return scale; }
	Matrix4x4 GetMatrix() const;

	Vector3 GetXAxis() const { return rotation * Vector3::UnitX; }
	Vector3 GetYAxis() const { return rotation * Vector3::UnitY; }
	Vector3 GetZAxis() const { return rotation * Vector3::UnitZ; }

	void AddPosition(const Vector3& inPosition) { position += inPosition; }
	void AddYawRotation(float inYawDegree);
	void AddPitchRotation(float inPitchDegree);
	void AddRollRotation(float inRollDegree);

	Transform Inverse() const;


	// Operators

	// Properties
	Vector3 position;
	Quaternion rotation;
	Vector3 scale;
};

