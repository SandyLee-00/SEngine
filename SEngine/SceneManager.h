#pragma once
#include <unordered_map>
#include <string>

/// <summary>
/// 현재 Scene을 갖고 있어서 Scene을 전환할 수 있도록 한다
/// 현재 Scene에 FixedUpdate / Update / Render 를 전달한다
/// 
/// Update : GameProcess -> SceneManager -> Scene -> GameObject -> Component
/// Render : GameProcess -> SceneManager -> Scene -> GameObject -> Render 관련된 Component
/// 
/// 240102 이서영
/// </summary>

class SceneManager
{
public:
	SceneManager() = default;
	~SceneManager() {};

public:
	void Initialize(std::unordered_map<std::string, class Scene*> scenes, class Scene* currentScene);
	void Finalize();

	void FixedUpdate(float PHYSICS_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

private:
	std::unordered_map<std::string, class Scene*> m_scenes;
	class Scene* m_currentScene;

};

