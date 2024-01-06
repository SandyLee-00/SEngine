#pragma once

#include "Vector2.h"
#include "Vector3.h"

/// <summary>
/// Vector4: x, y, z, w
/// TODO: FORCEINLINE / constexpr header�� �Űܼ� ����ȭ �ϱ�
/// 
/// https://docs.unity3d.com/ScriptReference/Vector4.html
/// 4���� ������ ǥ��
/// �� ������ �� ���� ���� ��� ����(��: �޽� ź��Ʈ, ���̴��� �Ķ����)�� ǥ���ϱ� ���� �Ϻο��� ���˴ϴ�.
/// �� �� ��κ��� ��쿡�� Vector3�� ���˴ϴ�.
/// 
/// 240103 �̼���
/// </summary>

struct Vector4
{
	// Constructors
	Vector4() = default;
	Vector4(float inX, float inY, float inZ, float inW) : x(inX), y(inY), z(inZ), w(inW) {}
	Vector4(int inX, int inY, int inZ, int inW) : x(static_cast<float>(inX)), y(static_cast<float>(inY)), z(static_cast<float>(inZ)), w(static_cast<float>(inW)) {}

	Vector4(const Vector2& inVector, bool isPoint = true) : x(inVector.x), y(inVector.y), z(0.f), w(isPoint ? 1.0f : 0.0f) {}
	Vector4(const Vector3& inVector, bool isPoint = true) : x(inVector.x), y(inVector.y), z(inVector.z), w(isPoint ? 1.0f : 0.0f) {}

	// Static Methods
	void Normalize();
	Vector4 GetNormalize() const;
	float Dot(const Vector4& inVector) const;

	// Operators
	Vector4 operator-() const;

	Vector4 operator+(const Vector4& inVector) const;
	Vector4 operator-(const Vector4& inVector) const;
	Vector4 operator*(float InScalar) const;
	Vector4 operator/(float InScalar) const;

	float operator[](unsigned char inIndex) const;
	float& operator[](unsigned char inIndex);

	// Properties
	float x;
	float y;
	float z;
	float w;

	// Static Properties
	static const Vector4 One;
	static const Vector4 Zero;

	static const Vector4 UnitX;
	static const Vector4 UnitY;
	static const Vector4 UnitZ;
	static const Vector4 UnitW;

};

