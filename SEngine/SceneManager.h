#pragma once
#include <unordered_map>
#include <string>
#include "IManager.h"

/// <summary>
/// ���� Scene�� ���� �־ Scene�� ��ȯ�� �� �ֵ��� �Ѵ�
/// ���� Scene�� FixedUpdate / Update / Render �� �����Ѵ�
/// 
/// Update : GameProcess -> SceneManager -> Scene -> GameObject -> Component
/// Render : GameProcess -> SceneManager -> Scene -> GameObject -> Render ���õ� Component
/// 
/// 240102 �̼���
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

	void FixedUpdate(float PHYSICS_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

private:
	std::unordered_map<std::string, class Scene*> m_scenes;
	class Scene* m_currentScene;

};
