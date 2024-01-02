#pragma once
#include <unordered_map>
#include <string>
#include "IManager.h"

/// <summary>
/// 
/// 240102 ¿Ãº≠øµ
/// </summary>

class SceneManager : public IManager
{
public:
	SceneManager() = default;
	~SceneManager() {};

public:
	void Initialize() override;
	void Initialize(std::unordered_map<std::string, class Scene*> scenes, class Scene* currentScene);
	void Finalize() override;

private:
	std::unordered_map<std::string, class Scene*> m_scenes;
	class Scene* m_currentScene;

};

