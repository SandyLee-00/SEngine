#pragma once

/// <summary>
/// Vector3: x, y, z
/// TODO: FORCEINLINE / constexpr header에 옮겨서 최적화 하기
/// 
/// 240103 이서영
/// </summary>

struct Vector3
{
	// Constructors
	Vector3() = default;
	Vector3(float inX, float inY, float inZ) : x(inX), y(inY), z(inZ) {}
	Vector3(int inX, int inY, int inZ) : x(static_cast<float>(inX)), y(static_cast<float>(inY)), z(static_cast<float>(inZ)) {}

	// Static Methods
	void Normalize();
	Vector3 GetNormalize() const;

	float Dot(const Vector3& inVector) const;
	Vector3 Cross(const Vector3& inVector) const;

	// Operators
	Vector3 operator+(const Vector3& inVector) const;
	Vector3 operator-(const Vector3& inVector) const;
	Vector3 operator*(float InScalar) const;
	Vector3 operator/(float InScalar) const;

	// Properties
	float x;
	float y;
	float z;

	// Static Properties
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Left;
	static const Vector3 Right;

	static const Vector3 One;
	static const Vector3 Zero;

	static const Vector3 Forward;
	static const Vector3 Back;

};

