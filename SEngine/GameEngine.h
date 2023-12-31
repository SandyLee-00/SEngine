#pragma once

/// <summary>
/// 게임 엔진 Life Cycle을 관리하는 클래스
/// 231231 이서영
/// </summary>
class GameEngine
{
public:
	GameEngine();
	~GameEngine();

private:
	class TimeManager* m_timeManager;
};

