#pragma once
#include <array>

#include "Vector3.h"

/// <summary>
/// Matrix4x4 -> Matrix3x3 변환 Rotation + Scale 만 남기기
/// 
/// 굳이 필요할까...?  
/// 
/// 240105 이서영
/// </summary>
struct Matrix3x3
{
	// Constructors
	Matrix3x3() = default;
	Matrix3x3(const Vector3& inCol0, const Vector3& inCol1, const Vector3& inCol2) { cols = { inCol0, inCol1, inCol2 }; }

	//Public Methods
	Matrix3x3 Transpose() const;

	// Operators
	const Vector3& operator[](unsigned int inIndex) const;
	Vector3& operator[](unsigned int inIndex);

	Matrix3x3 operator*(const Matrix3x3& inMatrix) const;
	Matrix3x3 operator*(float inScalar) const;

	Vector3 operator*(const Vector3& inVector) const;

	// Static Properties
	static const Matrix3x3 Identity;
	static const Matrix3x3 Zero;
	static constexpr unsigned int colCount = 3;

	// Properties
	std::array<Vector3, colCount> cols = { Vector3::UnitX, Vector3::UnitY, Vector3::UnitZ};
};

