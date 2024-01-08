#include "GameObject.h"

#include "AllManagers.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Start()
{

}

void GameObject::FixedUpdate(float FIXED_DELTATIME)
{

}

void GameObject::Update(float deltaTime)
{
	// ������Ʈ�� ��ȸ�ϸ鼭 ���ĵ� ������ ���� Update�� ȣ���Ѵ�.

}

void GameObject::Render(Renderer* renderer)
{

}

const PathManager* GameObject::GetPathManager() const
{
	return m_allManagers->GetPathManager();
}

const ResourceManager* GameObject::GetResourceManager() const
{
	return m_allManagers->GetResourceManager();
}

const SoundManager* GameObject::GetSoundManager() const
{
	return m_allManagers->GetSoundManager();
}

const TimeManager* GameObject::GetTimeManager() const
{
	return m_allManagers->GetTimeManager();
}

const InputManager* GameObject::GetInputManager() const
{
	return m_allManagers->GetInputManager();
}

const SceneManager* GameObject::GetSceneManager() const
{
	return m_allManagers->GetSceneManager();
}

const CameraManager* GameObject::GetCameraManager() const
{
	return m_allManagers->GetCameraManager();
}

const CollisionManager* GameObject::GetCollisionManager() const
{
	return m_allManagers->GetCollisionManager();
}

const UIManager* GameObject::GetUIManager() const
{
	return m_allManagers->GetUIManager();
}

