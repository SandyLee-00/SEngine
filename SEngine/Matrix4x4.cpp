#include <cassert>

#include "Matrix4x4.h"


const Matrix4x4 Matrix4x4::Identity(
	Vector4(1.0f, 0.0f, 0.0f, 0.0f),
	Vector4(0.0f, 1.0f, 0.0f, 0.0f),
	Vector4(0.0f, 0.0f, 1.0f, 0.0f),
	Vector4(0.0f, 0.0f, 0.0f, 1.0f)
);

Matrix4x4 Matrix4x4::Transpose() const
{
	return Matrix4x4(
		Vector4(cols[0].x, cols[1].x, cols[2].x, cols[3].x),
		Vector4(cols[0].y, cols[1].y, cols[2].y, cols[3].y),
		Vector4(cols[0].z, cols[1].z, cols[2].z, cols[3].z),
		Vector4(cols[0].w, cols[1].w, cols[2].w, cols[3].w)
	);
}

Matrix3x3 Matrix4x4::ToMatrix3x3() const
{
	Vector3 col0(cols[0].x, cols[0].y, cols[0].z);
	Vector3 col1(cols[1].x, cols[1].y, cols[1].z);
	Vector3 col2(cols[2].x, cols[2].y, cols[2].z);

	return Matrix3x3(col0, col1, col2);
}

const Vector4& Matrix4x4::operator[](unsigned int inIndex) const
{
	assert(inIndex < colCount);
	return cols[inIndex];
}

Vector4& Matrix4x4::operator[](unsigned int inIndex)
{
	assert(inIndex < colCount);
	return cols[inIndex];
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& inMatrix) const
{
	Matrix4x4 TM = Transpose();
	return Matrix4x4(
		Vector4(TM[0].Dot(inMatrix[0]), TM[1].Dot(inMatrix[0]), TM[2].Dot(inMatrix[0]), TM[3].Dot(inMatrix[0])),
		Vector4(TM[0].Dot(inMatrix[1]), TM[1].Dot(inMatrix[1]), TM[2].Dot(inMatrix[1]), TM[3].Dot(inMatrix[1])),
		Vector4(TM[0].Dot(inMatrix[2]), TM[1].Dot(inMatrix[2]), TM[2].Dot(inMatrix[2]), TM[3].Dot(inMatrix[2])),
		Vector4(TM[0].Dot(inMatrix[3]), TM[1].Dot(inMatrix[3]), TM[2].Dot(inMatrix[3]), TM[3].Dot(inMatrix[3]))
	);
}

Matrix4x4 Matrix4x4::operator*(float inScalar) const
{
	return Matrix4x4(
		cols[0] * inScalar,
		cols[1] * inScalar,
		cols[2] * inScalar,
		cols[3] * inScalar
	);
}

Vector4 Matrix4x4::operator*(const Vector4& inVector) const
{
	Matrix4x4 TM = Transpose();
	return Vector4(
		TM[0].Dot(inVector),
		TM[1].Dot(inVector),
		TM[2].Dot(inVector),
		TM[3].Dot(inVector)
	);
}
