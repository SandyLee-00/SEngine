#pragma once

#include <string>
#include <vector>

#include "ObjectType.h"

/// <summary>
/// Scene에 GameObject를 넣어서 ObjectType별로 update, render를 한다
/// 231231 이서영
/// </summary>
class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	void Start();
	void Update();
	void Render();

public:
	void AddGameObject(class GameObject* _gameObject);

private:
	// 씬 이름
	std::string m_sceneName;

	// 렌더러
	// class Renderer* m_renderer;

	// ObjectType에 따른 GameObject들
	std::vector<GameObject*> m_gameObjects[static_cast<int>(ObjectType::End)];

};

