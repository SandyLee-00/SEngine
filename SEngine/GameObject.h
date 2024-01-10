#pragma once

#include <map>
#include <vector>

#include "Defines.h"

/// <summary>
/// Scene���� Update �ϴ� GameObject
/// IComponent�� ����� Component�� ���� ����Ѵ� 
/// + Parent-Child ���踦 Transform���� ���� -> �� ������ �� Transform �پ��־�� �Ѵ�
/// + Object�� ID�� �ʿ��ϴ� Children �߿��� ã�� �� ���
/// 
/// 231231 �̼���
/// </summary>
class GameObject
{

public:
	GameObject();
	virtual ~GameObject();

	// LifeCycle
	void Start();
	void FixedUpdate(float FIXED_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

public:
	// Componet 
	ObjectOrder GetObjectType() const { return m_objectType; }

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
	// Parent-Child
	GameObject* GetParentGameObject();
	GameObject* GetChildGameObject(int index);
	std::vector<GameObject*>& GetChildrenGameObjects();

	void SetParentGameObject(GameObject* parent);
	void SetChildGameObject(GameObject* child);

private:
	ObjectOrder m_objectType;
	std::map<ComponentOrder, class Component*> m_components;

	const class AllManagers* m_allManagers;
};

template <typename T>
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

template <typename T>
T* GameObject::CreateComponent()
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

	// component�� GameObject ����
	component->SetGameObject(this);

	// component�� map�� �߰�
	m_components.insert(std::make_pair(component->GetCallOrder(), component));

	// TComponent�� ��ȯ
	return TComponent;
}