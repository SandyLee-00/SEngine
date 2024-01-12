#include "Component.h"

#include "Entity.h"
#include "AllManagers.h"

Component::Component()
	: m_componentType(ComponentOrder::End)
	, m_gameObject(nullptr)
{

}

const class AllManagers* Component::GetAllManagers() const
{
	return m_gameObject->GetAllManagers();
}

const class PathManager* Component::GetPathManager() const
{
	return m_gameObject->GetPathManager();
}

const class ResourceManager* Component::GetResourceManager() const
{
	return m_gameObject->GetResourceManager();
}

const class SoundManager* Component::GetSoundManager() const
{
	return m_gameObject->GetSoundManager();
}

const class TimeManager* Component::GetTimeManager() const
{
	return m_gameObject->GetTimeManager();
}

const class InputManager* Component::GetInputManager() const
{
	return m_gameObject->GetInputManager();
}

const class SceneManager* Component::GetSceneManager() const
{
	return m_gameObject->GetSceneManager();
}

const class CameraManager* Component::GetCameraManager() const
{
	return m_gameObject->GetCameraManager();
}

const class CollisionManager* Component::GetCollisionManager() const
{
	return m_gameObject->GetCollisionManager();
}

const class UIManager* Component::GetUIManager() const
{
	return m_gameObject->GetUIManager();
}
