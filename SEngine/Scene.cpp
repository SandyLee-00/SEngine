#include "Scene.h"
#include "GameObject.h"
#include "ObjectType.h"
#include "Renderer.h"

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

void Scene::FixedUpdate(float FIXED_DELTATIME)
{
	for(int i = 0; i < static_cast<int>(ObjectType::End); ++i)
	{
		for (auto& gameObject : m_gameObjects[i])
		{
			gameObject->FixedUpdate(FIXED_DELTATIME);
		}
	}
}

void Scene::Update(float deltaTime)
{
	for (int i = 0; i < static_cast<int>(ObjectType::End); ++i)
	{
		for (auto& gameObject : m_gameObjects[i])
		{
			gameObject->Update(deltaTime);
		}
	}
}

void Scene::Render(class Renderer* renderer)
{
	for (int i = 0; i < static_cast<int>(ObjectType::End); ++i)
	{
		for (auto& gameObject : m_gameObjects[i])
		{
			gameObject->Render(renderer);
		}
	}
}

void Scene::AddGameObject(GameObject* _gameObject)
{
	m_gameObjects[static_cast<int>(_gameObject->GetObjectType())].push_back(_gameObject);

	// TODO: Collider 있으면 충돌처리 추가
}
