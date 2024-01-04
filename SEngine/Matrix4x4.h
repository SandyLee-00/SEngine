#pragma once

#include <array>

#include "Vector4.h"

/// <summary>
/// Transform <-> Matrix4x4 ��ȯ
/// float 16�� 4�ٷ� 4���� 
/// 
/// TODO: Vector4 4�� -> float 16���� �ٲٱ�
/// 
/// https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Core/Public/Math/Matrix.h
/// https://docs.unity3d.com/ScriptReference/Matrix4x4.html
/// transformation matrix�� ������ 3D transformations(��: �̵�, ȸ��, ������, ���� ��)�� homogenous coordinates�� ����� perspective transformations�� ������ �� �ֽ��ϴ�. 
/// ��ũ��Ʈ���� ����� ����ϴ� ���� ���� ������, ��κ� Vector3, ���ʹϾ� �� Transform Ŭ������ ����� ����ϴ� ���� �� �����մϴ�.
/// �Ϲ� ����� nonstandard camera projection ������ ���� Ư���� ��쿡 ���˴ϴ�.
/// 
/// 240103 �̼���
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

