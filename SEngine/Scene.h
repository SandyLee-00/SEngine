#pragma once

#include <string>
#include <vector>

#include "Defines.h"

/// <summary>
/// Scene�� GameObject�� �־ ObjectType���� update, render�� �Ѵ�
/// 231231 �̼���
/// </summary>
class Scene
{
public:
	Scene() = default;
	virtual ~Scene();

public:
	// ����� ���� Scene���� �����ؾ� �ϴ� �Լ�
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	// �ش� ���� GameObject�� �ִ� �Լ��� Ÿ�Ժ��� ȣ��
	void Start();
	void FixedUpdate(float FIXED_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

public:
	// Scene�� ���� ���
	void AddGameObject(class GameObject* _gameObject);

private:
	// �� �̸�
	std::string m_sceneName;

	// ������
	class Renderer* m_renderer;

	// ObjectType�� ���� GameObject��
	std::vector<class GameObject*> m_gameObjects[static_cast<int>(ObjectOrder::End)];

};

