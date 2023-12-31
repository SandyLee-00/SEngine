#include "Scene.h"
#include "GameObject.h"
#include "ObjectType.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Start()
{
	for (int i = 0; i < static_cast<int>(ObjectType::End); ++i)
	{
		for (auto& gameObject : m_gameObjects[i])
		{
			gameObject->Start();
		}
	}
}

void Scene::Update()
{
	for (int i = 0; i < static_cast<int>(ObjectType::End); ++i)
	{
		for (auto& gameObject : m_gameObjects[i])
		{
			gameObject->Update();
		}
	}

}

void Scene::Render()
{
	for (int i = 0; i < static_cast<int>(ObjectType::End); ++i)
	{
		for (auto& gameObject : m_gameObjects[i])
		{
			gameObject->Render();
		}
	}
}

void Scene::AddGameObject(GameObject* _gameObject)
{
	m_gameObjects[static_cast<int>(_gameObject->GetObjectType())].push_back(_gameObject);

	// TODO: Collider 있으면 충돌처리 추가
}
