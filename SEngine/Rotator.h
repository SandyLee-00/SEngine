#pragma once
/// <summary>
/// Degree �� yaw, pitch, roll�� z y x�࿡ ���� ȸ���� ��Ÿ���� ����ü
/// 
/// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/
/// https://docs.unity3d.com/ScriptReference/Quaternion.Euler.html
/// 
/// 240104 �̼���
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

