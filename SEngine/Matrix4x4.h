#pragma once

#include <array>

#include "Vector4.h"

/// <summary>
/// Transform <-> Matrix4x4 변환
/// float 16개 4줄로 4개씩 
/// 
/// TODO: Vector4 4개 -> float 16개로 바꾸기
/// 
/// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Core/Public/Math/Matrix.h
/// https://docs.unity3d.com/ScriptReference/Matrix4x4.html
/// transformation matrix는 임의의 3D transformations(예: 이동, 회전, 스케일, 전단 등)과 homogenous coordinates를 사용한 perspective transformations을 수행할 수 있습니다. 
/// 스크립트에서 행렬을 사용하는 경우는 거의 없으며, 대부분 Vector3, 쿼터니언 및 Transform 클래스의 기능을 사용하는 것이 더 간단합니다.
/// 일반 행렬은 nonstandard camera projection 설정과 같은 특수한 경우에 사용됩니다.
/// 
/// 240103 이서영
/// </summary>
struct Matrix4x4
{
	// Constructors
	Matrix4x4() = default;
	Matrix4x4(const Vector4& inCol0, const Vector4& inCol1, const Vector4& inCol2, const Vector4& inCol3) { cols = { inCol0, inCol1, inCol2, inCol3 }; }

	//Public Methods
	Matrix4x4 Transpose() const;

	// Operators
	const Vector4& operator[](unsigned int inIndex) const;
	Vector4& operator[](unsigned int inIndex);

	Matrix4x4 operator*(const Matrix4x4& inMatrix) const;
	Matrix4x4 operator*(float inScalar) const;

	Vector4 operator*(const Vector4& inVector) const;

	// Static Properties
	static const Matrix4x4 Identity;
	static const Matrix4x4 Zero;
	static constexpr unsigned int colCount = 4;

	// Properties
	std::array<Vector4, colCount> cols = { Vector4::UnitX, Vector4::UnitY, Vector4::UnitZ, Vector4::UnitW };
};

