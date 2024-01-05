#pragma once

#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"
#include "Rotator.h"

/// <summary>
/// Position + Rotation + Scale에 대한 3D Transform
/// Transform <-> Matrix4x4 변환
/// Transform GameObject 관리 X Parent-Child 관계 표현 X
/// 
/// TODO: Component로 분리
/// 
/// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Core/Public/Math/TransformCalculus.h
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

