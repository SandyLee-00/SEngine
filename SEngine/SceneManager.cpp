#include "SceneManager.h"

void SceneManager::Initialize()
{

}


void SceneManager::Initialize(std::unordered_map<std::string, class Scene*> scenes, class Scene* currentScene)
{
	m_scenes = scenes;
	m_currentScene = currentScene;
}

void SceneManager::Finalize()
{

}

void SceneManager::FixedUpdate(float PHYSICS_DELTATIME)
{

}

void SceneManager::Update(float deltaTime)
{

}

void SceneManager::Render(class Renderer* renderer)
{

}
