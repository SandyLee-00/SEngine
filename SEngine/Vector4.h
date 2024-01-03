#pragma once

/// <summary>
/// Vector4: x, y, z, w
/// TODO: FORCEINLINE / constexpr header에 옮겨서 최적화 하기
/// 
/// https://docs.unity3d.com/ScriptReference/Vector4.html
/// 4차원 벡터의 표현
/// 이 구조는 네 개의 구성 요소 벡터(예: 메시 탄젠트, 셰이더의 파라미터)를 표현하기 위해 일부에서 사용됩니다.
/// 그 외 대부분의 경우에는 Vector3가 사용됩니다.
/// 240103 이서영
/// </summary>

struct Vector4
{
	// Constructors
	Vector4() = default;
	Vector4(float inX, float inY, float inZ, float inW) : x(inX), y(inY), z(inZ), w(inW) {}
	Vector4(int inX, int inY, int inZ, int inW) : x(static_cast<float>(inX)), y(static_cast<float>(inY)), z(static_cast<float>(inZ)), w(static_cast<float>(inW)) {}

	// Static MethodsS
	void Normalize();
	Vector4 GetNormalize() const;
	float Dot(const Vector4& inVector) const;

	// Operators
	Vector4 operator+(const Vector4& inVector) const;
	Vector4 operator-(const Vector4& inVector) const;
	Vector4 operator*(float InScalar) const;
	Vector4 operator/(float InScalar) const;

	// Properties
	float x;
	float y;
	float z;
	float w;

	// Static Properties
	static const Vector4 One;
	static const Vector4 Zero;


};

