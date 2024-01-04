#pragma once
/// <summary>
/// Degree 값 yaw, pitch, roll로 z y x축에 대한 회전을 나타내는 구조체
/// 
/// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/
/// https://docs.unity3d.com/ScriptReference/Quaternion.Euler.html
/// 
/// 240104 이서영
/// </summary>
struct Rotator
{
	// Constructors
	Rotator() = default;
	Rotator(float inYaw, float inPitch, float inRoll) : yaw(inYaw), pitch(inPitch), roll(inRoll) {}

	// Public Methods
	void Clamp();
	float GetClampedAngleValue(float inAngle);

	static const Rotator Identity;

	// Properties
	float yaw;
	float roll;
	float pitch;
};

