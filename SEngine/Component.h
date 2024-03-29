#pragma once

#include "Defines.h"

/// <summary>
/// GameObject에 붙혀 기능을 작동시킨다
/// 
/// 240108 이서영
/// </summary>
class Component
{
public:
	Component();
	virtual ~Component() {};

	// Process
	virtual void Start() {};
	virtual void FixedUpdate(float FIXED_DELTATIME) {};
	virtual void Update(float deltaTime) {};
	virtual void Render(class Renderer* renderer) {};
	virtual void DebugRender(class Renderer* renderer) {};

public:
	ComponentOrder GetCallOrder() const { return m_componentType; }
	Entity* GetEntity() const { return m_entity; }

	void SetEntity(class Entity* entity) { m_entity = entity; }

public:
	const class AllManagers* GetAllManagers() const;
	const class PathManager* GetPathManager() const;
	const class ResourceManager* GetResourceManager() const;
	const class SoundManager* GetSoundManager() const;
	const class TimeManager* GetTimeManager() const;
	const class InputManager* GetInputManager() const;
	const class SceneManager* GetSceneManager() const;
	const class CameraManager* GetCameraManager() const;
	const class CollisionManager* GetCollisionManager() const;
	const class UIManager* GetUIManager() const;

private:
	const ComponentOrder m_componentType;
	class Entity* m_entity;

};

