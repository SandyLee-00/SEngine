#include "Component.h"

#include "Entity.h"
#include "AllManagers.h"

Component::Component()
	: m_componentType(ComponentOrder::End)
	, m_entity(nullptr)
{

}

const class AllManagers* Component::GetAllManagers() const
{
	return m_entity->GetAllManagers();
}

const class PathManager* Component::GetPathManager() const
{
	return m_entity->GetPathManager();
}

const class ResourceManager* Component::GetResourceManager() const
{
	return m_entity->GetResourceManager();
}

const class SoundManager* Component::GetSoundManager() const
{
	return m_entity->GetSoundManager();
}

const class TimeManager* Component::GetTimeManager() const
{
	return m_entity->GetTimeManager();
}

const class InputManager* Component::GetInputManager() const
{
	return m_entity->GetInputManager();
}

const class SceneManager* Component::GetSceneManager() const
{
	return m_entity->GetSceneManager();
}

const class CameraManager* Component::GetCameraManager() const
{
	return m_entity->GetCameraManager();
}

const class CollisionManager* Component::GetCollisionManager() const
{
	return m_entity->GetCollisionManager();
}

const class UIManager* Component::GetUIManager() const
{
	return m_entity->GetUIManager();
}
