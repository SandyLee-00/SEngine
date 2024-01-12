#pragma once

#include <map>
#include <vector>

#include "Defines.h"

/// <summary>
/// Scene���� Update �ϴ� Entity
/// IComponent�� ����� Component�� ���� ����Ѵ� 
/// + Parent-Child ���踦 Transform���� ���� -> �� ������ �� Transform �پ��־�� �Ѵ�
/// 
/// https://docs.unity3d.com/Manual/class-TagManager.html
/// 
/// 231231 �̼���
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
	// �̹� ������ ������Ʈ�� �������� ����
	if (GetComponent<T>() != nullptr)
	{
		return GetComponent<T>();
	}

	T* TComponent = new T();
	Component* component = dynamic_cast<Component*>(TComponent);

	// dynamic_cast�� �ߴµ� Component�� �ƴѰ�쿡�� nullptr �̹Ƿ� �ٽ� ����
	if (component == nullptr)
	{
		delete TComponent;
		return nullptr;
	}

	// component�� Entity ����
	component->SetGameObject(this);

	// component�� map�� �߰�
	m_components.insert(std::make_pair(component->GetCallOrder(), component));

	// TComponent�� ��ȯ
	return TComponent;
}