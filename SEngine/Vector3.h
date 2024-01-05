#pragma once

/// <summary>
/// Vector3: x, y, z
/// TODO: FORCEINLINE / constexpr header에 옮겨서 최적화 하기
/// 
/// https://docs.unity3d.com/ScriptReference/Vector3.html
/// 3D 벡터 및 포인트 표현, 계산
/// Unity 전체에서 3D 위치와 방향을 전달하는 데 사용됩니다. 일반적인 벡터 연산을 수행하는 함수도 포함되어 있습니다.
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
	Vector3 SizeSquared() const;

	float Dot(const Vector3& inVector) const;
	Vector3 Cross(const Vector3& inVector) const;

	// Operators
	Vector3 operator-() const;

	Vector3 operator+(const Vector3& inVector) const;
	Vector3 operator-(const Vector3& inVector) const;
	Vector3 operator*(const Vector3& inVector) const;

	Vector3 operator*(float InScalar) const;
	Vector3 operator/(float InScalar) const;

	Vector3& operator+=(const Vector3& inVector);
	Vector3& operator-=(const Vector3& inVector);
	Vector3& operator*=(float InScalar);
	Vector3& operator/=(float InScalar);

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

	static const Vector3 UnitX;
	static const Vector3 UnitY;
	static const Vector3 UnitZ;

};

