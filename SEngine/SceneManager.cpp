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
