#pragma once

#include <string>
#include <vector>

#include "ObjectType.h"

/// <summary>
/// Scene�� GameObject�� �־ ObjectType���� update, render�� �Ѵ�
/// 231231 �̼���
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
	// �� �̸�
	std::string m_sceneName;

	// ������
	// class Renderer* m_renderer;

	// ObjectType�� ���� GameObject��
	std::vector<GameObject*> m_gameObjects[static_cast<int>(ObjectType::End)];

};

