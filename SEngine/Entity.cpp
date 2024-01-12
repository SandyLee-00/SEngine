#include "Entity.h"

#include <cassert>

#include "AllManagers.h"
#include "Transform.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::Start()
{

}

void Entity::FixedUpdate(float FIXED_DELTATIME)
{

}

void Entity::Update(float deltaTime)
{
	// ������Ʈ�� ��ȸ�ϸ鼭 ���ĵ� ������ ���� Update�� ȣ���Ѵ�.

}

void Entity::Render(Renderer* renderer)
{

}

const PathManager* Entity::GetPathManager() const
{
	return m_allManagers->GetPathManager();
}

const ResourceManager* Entity::GetResourceManager() const
{
	return m_allManagers->GetResourceManager();
}

const SoundManager* Entity::GetSoundManager() const
{
	return m_allManagers->GetSoundManager();
}

const TimeManager* Entity::GetTimeManager() const
{
	return m_allManagers->GetTimeManager();
}

const InputManager* Entity::GetInputManager() const
{
	return m_allManagers->GetInputManager();
}

const SceneManager* Entity::GetSceneManager() const
{
	return m_allManagers->GetSceneManager();
}

const CameraManager* Entity::GetCameraManager() const
{
	return m_allManagers->GetCameraManager();
}

const CollisionManager* Entity::GetCollisionManager() const
{
	return m_allManagers->GetCollisionManager();
}

const UIManager* Entity::GetUIManager() const
{
	return m_allManagers->GetUIManager();
}

