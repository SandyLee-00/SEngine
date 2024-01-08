#include "Component.h"

#include "GameObject.h"
#include "AllManagers.h"

const class AllManagers* Component::GetAllManagers() const
{
	return m_gameObject->GetAllManagers();
}

const class PathManager* Component::GetPathManager() const
{
	return m_allManagers->GetPathManager();
}

const class ResourceManager* Component::GetResourceManager() const
{
	return m_allManagers->GetResourceManager();
}

const class SoundManager* Component::GetSoundManager() const
{
	return m_allManagers->GetSoundManager();
}

const class TimeManager* Component::GetTimeManager() const
{
	return m_allManagers->GetTimeManager();
}

const class InputManager* Component::GetInputManager() const
{
	return m_allManagers->GetInputManager();
}

const class SceneManager* Component::GetSceneManager() const
{
	return m_allManagers->GetSceneManager();
}

const class CameraManager* Component::GetCameraManager() const
{
	return m_allManagers->GetCameraManager();
}

const class CollisionManager* Component::GetCollisionManager() const
{
	return m_allManagers->GetCollisionManager();
}

const class UIManager* Component::GetUIManager() const
{
	return m_allManagers->GetUIManager();
}
