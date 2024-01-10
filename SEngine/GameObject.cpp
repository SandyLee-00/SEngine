#include "GameObject.h"

#include <cassert>

#include "AllManagers.h"
#include "Transform.h"

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
	// 컴포넌트를 순회하면서 정렬된 순서에 따라서 Update를 호출한다.

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

GameObject* GameObject::GetParentGameObject()
{
	Transform* thisTransform = GetComponent<Transform>();
	if (thisTransform == nullptr)
	{
		assert(thisTransform && "GameObject* GameObject::GetParent() const / if(thisTransform == nullptr)");
		return nullptr;
	}
	return thisTransform->GetParentGameObject();

}

GameObject* GameObject::GetChildGameObject(int index)
{
	Transform* thisTransform = GetComponent<Transform>();
	if (thisTransform == nullptr)
	{
		assert(thisTransform && "GameObject* GameObject::GetChildGameObject(int index) const / if(thisTransform == nullptr)");
		return nullptr;
	}
	return thisTransform->GetChildGameObject(index);
}

std::vector<GameObject*>& GameObject::GetChildrenGameObjects()
{
	Transform* thisTransform = GetComponent<Transform>();
if (thisTransform == nullptr)
	{
		assert(thisTransform && "std::vector<GameObject*>& GameObject::GetChildrenGameObjects() const / if(thisTransform == nullptr)");
		return thisTransform->GetChildrenGameObjects();
	}
}

void GameObject::SetParentGameObject(GameObject* parent)
{
	Transform* thisTransform = GetComponent<Transform>();
	if (thisTransform == nullptr)
	{
		assert(thisTransform && "void GameObject::SetParentGameObject(GameObject* parent) / if(thisTransform == nullptr)");
		return;
	}
	thisTransform->SetParentGameObject(parent);
}

void GameObject::SetChildGameObject(GameObject* child)
{
	Transform* thisTransform = GetComponent<Transform>();
	if (thisTransform == nullptr)
	{
		assert(thisTransform && "void GameObject::SetChildGameObject(GameObject* child) / if(thisTransform == nullptr)");
		return;
	}
	thisTransform->SetChildGameObject(child);
}

