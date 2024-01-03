#pragma once

/// <summary>
/// Vector2
/// TODO: FORCEINLINE / constexpr header에 옮겨서 최적화 하기
/// 
/// 240103 이서영
/// </summary>

struct Vector2
{
	// Constructors
	Vector2() = default;
	Vector2(float inX, float inY) : x(inX), y(inY) {}
	Vector2(int inX, int inY) : x(static_cast<float>(inX)), y(static_cast<float>(inY)) {}

	// Public Methods
	void Normalize();
	Vector2 GetNormalize() const;

	// Static Methods
	float Dot(const Vector2& inVector) const;

	// Operators
	Vector2 operator+(const Vector2& inVector) const;
	Vector2 operator-(const Vector2& inVector) const;
	Vector2 operator*(float inVector) const;
	Vector2 operator/(float inVector) const;

	// Properties
	float x;
	float y;

	// Static Properties
	static const Vector2 Up;
	static const Vector2 Down;
	static const Vector2 Left;
	static const Vector2 Right;

	static const Vector2 One;
	static const Vector2 Zero;

};

