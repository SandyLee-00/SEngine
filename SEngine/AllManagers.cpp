#include "AllManagers.h"

void AllManagers::Initialize()
{

}

void AllManagers::Initialize(PathManager* pathManager, ResourceManager* resourceManager, SoundManager* soundManager, TimeManager* timeManager, InputManager* inputManager, SceneManager* sceneManager, CameraManager* cameraManager, CollisionManager* collisionManager, UIManager* UIManager)
{
	m_pathManager = pathManager;
	m_resourceManager = resourceManager;
	m_soundManager = soundManager;
	
	m_timeManager = timeManager;
	m_inputManager = inputManager;
	m_sceneManager = sceneManager;
	m_cameraManager = cameraManager;

	m_collisionManager = collisionManager;

	m_UIManager = UIManager;
}

void AllManagers::Finalize()
{

}
