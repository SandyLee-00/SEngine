#pragma once
#include "IManager.h"
#include "PathManager.h"
#include "ResourceManager.h"
#include "SoundManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "CollisionManager.h"
#include "UIManager.h"

/// <summary>
/// AllManagers에서 Get_Manager()로 전체 매니저를 가져올 수 있다 
/// 240102 이서영
/// </summary>

class AllManagers : public IManager
{
public:
	AllManagers() = default;
	~AllManagers() {};

	void Initialize() override;
	void Initialize(PathManager* pathManager, ResourceManager* resourceManager, SoundManager* soundManager, TimeManager* timeManager, InputManager* inputManager, SceneManager* sceneManager, CameraManager* cameraManager, CollisionManager* collisionManager, UIManager* UIManager);
	void Finalize() override;
	
	const PathManager* GetPathManager() const { return m_pathManager; }
	const ResourceManager* GetResourceManager() const { return m_resourceManager; }
	const SoundManager* GetSoundManager() const { return m_soundManager; }
	const TimeManager* GetTimeManager() const { return m_timeManager; }
	const InputManager* GetInputManager() const { return m_inputManager; }
	const SceneManager* GetSceneManager() const { return m_sceneManager; }
	const CameraManager* GetCameraManager() const { return m_cameraManager; }
	const CollisionManager* GetCollisionManager() const { return m_collisionManager; }
	const UIManager* GetUIManager() const { return m_UIManager; }

private:
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
};

