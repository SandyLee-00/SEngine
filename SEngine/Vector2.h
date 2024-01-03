#pragma once

/// <summary>
/// Vector2: x, y
/// TODO: FORCEINLINE / constexpr header에 옮겨서 최적화 하기
/// 
/// https://docs.unity3d.com/ScriptReference/Vector2.html
/// 2D 벡터와 점의 표현
///  2D 위치 및 벡터(예: 메시의 텍스처 좌표 또는 머티리얼의 텍스처 오프셋)를 표현하기 위해 일부에서 사용됩니다. 
/// 그 외 대부분의 경우에는 Vector3가 사용됩니다.
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
	Vector2 operator*(float InScalar) const;
	Vector2 operator/(float InScalar) const;

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

