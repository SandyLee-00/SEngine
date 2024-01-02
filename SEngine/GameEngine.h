#pragma once
#include <Windows.h>

/// <summary>
/// 게임 엔진 Life Cycle을 관리하는 클래스
/// 231231 이서영
/// </summary>
class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void Initialize(HWND hWnd, class Renderer* renderer);
	void Process();
	void Finalize();

private:
	// Renderer
	class Renderer* m_renderer;

	// Resource
	class PathManager* m_pathManager;
	class ResourceManager* m_resourceManager;
	class SoundManager* m_soundManager;

	// Life Cycle - main
	class TimeManager* m_timeManager;
	class InputManager* m_inputManager;
	class SceneManager* m_sceneManager;

	// Life Cycle - Physics
	class CollisionManager* m_collisionManager;

	// UI
	class UIManager* m_UIManager;

private:
	HWND m_hWnd;

};

