#pragma once

#include <string>
#include <vector>

#include "Defines.h"

/// <summary>
/// Scene에 GameObject를 넣어서 ObjectType별로 update, render를 한다
/// 231231 이서영
/// </summary>
class Scene
{
public:
	Scene() = default;
	virtual ~Scene();

public:
	// 상속한 실제 Scene에서 구현해야 하는 함수
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	// 해당 씬의 GameObject에 있는 함수를 타입별로 호출
	void Start();
	void FixedUpdate(float FIXED_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

public:
	// Scene의 공통 기능
	void AddGameObject(class GameObject* _gameObject);

private:
	// 씬 이름
	std::string m_sceneName;

	// 렌더러
	class Renderer* m_renderer;

	// ObjectType에 따른 GameObject들
	std::vector<class GameObject*> m_gameObjects[static_cast<int>(ObjectOrder::End)];

};

