#pragma once

#include <map>

#include "Defines.h"

/// <summary>
/// Scene에서 Update 하는 GameObject
/// IComponent를 상속한 Component를 붙혀 사용한다 
/// 231231 이서영
/// </summary>
class GameObject
{

public:
	GameObject();
	virtual ~GameObject();

	void Start();
	void FixedUpdate(float FIXED_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

public:
	ObjectOrder GetObjectType() const { return m_objectType; }

	template<typename T>
	T* GetComponent();

	template<typename T>
	T* CreateComponent();

public:
	const class AllManagers* GetAllManagers() const { return m_allManagers; }
	const class PathManager* GetPathManager() const;
	const class ResourceManager* GetResourceManager() const;
	const class SoundManager* GetSoundManager() const;
	const class TimeManager* GetTimeManager() const;
	const class InputManager* GetInputManager() const;
	const class SceneManager* GetSceneManager() const;
	const class CameraManager* GetCameraManager() const;
	const class CollisionManager* GetCollisionManager() const;
	const class UIManager* GetUIManager() const;


private:
	ObjectOrder m_objectType;
	std::map<ComponentOrder, class Component*> m_components;

	const class AllManagers* m_allManagers;
};

template<typename T>
T* GameObject::GetComponent()
{
	for (auto& iter : m_components)
	{
		T* component = dynamic_cast<T*>(iter.second);
		if (component != nullptr)
		{
			return component;
		}
	}

	return nullptr;
}

template<typename T>
T* GameObject::CreateComponent()
{
	// 이미 생성된 컴포넌트는 생성하지 않음
	if (GetComponent<T>() != nullptr)
	{
		return GetComponent<T>();
	}

	T* TComponent = new T();
	Component* component = dynamic_cast<Component*>(TComponent);

	// dynamic_cast를 했는데 Component가 아닌경우에는 nullptr 이므로 다시 삭제
	if (component == nullptr)
	{
		delete TComponent;
		return nullptr;
	}

	// component와 GameObject 연결
	component->SetGameObject(this);

	// component를 map에 추가
	m_components.insert(std::make_pair(component->GetCallOrder(), component));

	// TComponent를 반환
	return TComponent;
}