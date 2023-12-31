#pragma once

#include <Windows.h>

/// <summary>
/// Update(_deltaTime)���� �� deltaTime ���� ������ִ� Ŭ����
/// 231231 �̼���
/// </summary>
class TimeManager
{
public:
	TimeManager();
	~TimeManager();

public:
	void Initalize();
	void Update();

public:
	float GetDeltaTime() const { return m_deltaTime; }

private:
	LARGE_INTEGER m_curentCount;
	LARGE_INTEGER m_prevCount;
	LARGE_INTEGER m_frequency;

	float m_deltaTime;
	float m_elapsedTime;

	int m_frameCount;
	int m_fps;

};

