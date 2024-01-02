#pragma once
#include <Windows.h>
#include <unordered_map>
#include <vector>

/// <summary>
/// ���� ���� Life Cycle�� �����ϴ� Ŭ����
/// 231231 �̼���
/// </summary>
class GameEngine
{
public:
	GameEngine() = default;
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
	class CameraManager* m_cameraManager;

	// Life Cycle - Physics
	class CollisionManager* m_collisionManager;

	// UI
	class UIManager* m_UIManager;

	// AllManager: ��� �Ŵ����� �����ִ� �Ŵ���
	class AllManagers* m_allManagers;

private:
	// Scene�� Unordered_map�� �־ KeyValue�� ���
	std::vector<class Scene*> m_scenes;
	float m_elapsedPhysicsTime;

private:
	HWND m_hWnd;

};

