#pragma once

#include <map>
#include <vector>

#include "Defines.h"

/// <summary>
/// Scene에서 Update 하는 Entity
/// IComponent를 상속한 Component를 붙혀 사용한다 
/// + Parent-Child 관계를 Transform에서 관리 -> 꼭 생성할 때 Transform 붙어있어야 한다
/// 
/// https://docs.unity3d.com/Manual/class-TagManager.html
/// 
/// 231231 이서영
/// </summary>
class Entity
{

public:
	Entity();
	virtual ~Entity();

	// LifeCycle
	void Start();
	void FixedUpdate(float FIXED_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

public:
	// Componet 
	Layers GetObjectLayer() const { return m_objectLayer; }

	template<typename T>
	T* GetComponent();

	template<typename T>
	T* CreateComponent();

public:
	// Manager
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

public:
	// Tag
// 	Tags GetTag() const { return m_tag; }
// 	void SetTag(Tags tag) { m_tag = tag; }

private:
	Layers m_objectLayer;
	std::map<ComponentOrder, class Component*> m_components;

	const class AllManagers* m_allManagers;

/*	Tags m_tag;*/
};

template <typename T>
T* Entity::GetComponent()
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

template <typename T>
T* Entity::CreateComponent()
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

	// component와 Entity 연결
	component->SetGameObject(this);

	// component를 map에 추가
	m_components.insert(std::make_pair(component->GetCallOrder(), component));

	// TComponent를 반환
	return TComponent;
}