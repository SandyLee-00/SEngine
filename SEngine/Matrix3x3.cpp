#include <cassert>
#include "Matrix3x3.h"
#include "Vector3.h"

const Matrix3x3 Matrix3x3::Identity(
	Vector3(1.0f, 0.0f, 0.0f),
	Vector3(0.0f, 1.0f, 0.0f),
	Vector3(0.0f, 0.0f, 1.0f)
);

Matrix3x3 Matrix3x3::Transpose() const
{
	return Matrix3x3(
		Vector3(cols[0].x, cols[1].x, cols[2].x),
		Vector3(cols[0].y, cols[1].y, cols[2].y),
		Vector3(cols[0].z, cols[1].z, cols[2].z)
	);
}

const Vector3& Matrix3x3::operator[](unsigned int inIndex) const
{
	assert(inIndex < colCount);
	return cols[inIndex];
}

Vector3& Matrix3x3::operator[](unsigned int inIndex)
{
	assert(inIndex < colCount);
	return cols[inIndex];
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& inMatrix) const
{
	Matrix3x3 TransposedM = Transpose();
	return Matrix3x3(
		Vector3(TransposedM[0].Dot(inMatrix[0]), TransposedM[1].Dot(inMatrix[0]), TransposedM[2].Dot(inMatrix[0])),
		Vector3(TransposedM[0].Dot(inMatrix[1]), TransposedM[1].Dot(inMatrix[1]), TransposedM[2].Dot(inMatrix[1])),
		Vector3(TransposedM[0].Dot(inMatrix[2]), TransposedM[1].Dot(inMatrix[2]), TransposedM[2].Dot(inMatrix[2]))
	);
}

Matrix3x3 Matrix3x3::operator*(float inScalar) const
{
	return Matrix3x3(
		cols[0] * inScalar,
		cols[1] * inScalar,
		cols[2] * inScalar
	);
}

Vector3 Matrix3x3::operator*(const Vector3& inVector) const
{
	Matrix3x3 TransposedM = Transpose();
	return Vector3(
		TransposedM[0].Dot(inVector),
		TransposedM[1].Dot(inVector),
		TransposedM[2].Dot(inVector)
	);
}
