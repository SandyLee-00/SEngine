#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"

/// <summary>
/// Position + Rotation + Scale에 대한 3D Transform
/// Transform <-> Matrix4x4 변환
/// Transform GameObject 관리 X Parent-Child 관계 표현 X
/// 
/// TODO: Component로 분리
/// 
/// https://docs.unity3d.com/ScriptReference/Transform.html
/// object의 위치, 회전 및 배율을 저장, 조정합니다.
/// 씬의 모든 오브젝트에는 트랜스폼이 있습니다. 
/// 
/// 240103 이서영
/// </summary>
struct Transform
{
	// Constructors
	Transform() = default;
	Transform(const Vector3& inPosition, const Quaternion& inRotation, const Vector3& inScale) : position(inPosition), rotation(inRotation), scale(inScale) {}
	Transform(const Matrix4x4& inMatrix);

	// Public Methods
	void SetPosition(const Vector3& inPosition) { position = inPosition; }
	void SetRotation(const Quaternion& inRotation) { rotation = inRotation; }
	void SetScale(const Vector3& inScale) { scale = inScale; }
	void SetTransformMatrix(const Matrix4x4& inMatrix);

	Vector3 GetPosition() const { return position; }
	Quaternion GetRotation() const { return rotation; }
	Vector3 GetScale() const { return scale; }
	Matrix4x4 GetTransformMatrix() const;

	void AddPosition(const Vector3& inPosition) { position += inPosition; }



	// Operators

	// Properties
	Vector3 position;
	Quaternion rotation;
	Vector3 scale;
};

