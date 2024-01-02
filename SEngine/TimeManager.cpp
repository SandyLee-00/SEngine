#include "TimeManager.h"

TimeManager::TimeManager()
{
	
}

TimeManager::~TimeManager()
{

}

void TimeManager::Initialize()
{
	QueryPerformanceFrequency(&m_frequency); // 프로세서의 카운터 값의 빈도
	QueryPerformanceCounter(&m_prevCount); // 이전 프레임의 카운터 값 
	QueryPerformanceCounter(&m_curentCount);
}

void TimeManager::Finalize()
{

}

void TimeManager::Update()
{
	QueryPerformanceCounter(&m_curentCount);

	m_deltaTime = (m_curentCount.QuadPart - m_prevCount.QuadPart) / (float)m_frequency.QuadPart;

	m_prevCount = m_curentCount;

	++m_frameCount;
	m_elapsedTime += m_deltaTime;
	if (m_elapsedTime >= 1.)
	{
		m_elapsedTime -= 1.;
		m_fps = m_frameCount;
		m_frameCount = 0;
	}
}
