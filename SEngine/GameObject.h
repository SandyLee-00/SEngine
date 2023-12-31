#pragma once

#include "ObjectType.h"

/// <summary>
/// Scene에서 Update 하는 GameObject
/// IComponent를 상속한 Component를 붙혀 사용한다 
/// 231231 이서영
/// </summary>
class GameObject
{

public:
	GameObject();
	virtual ~GameObject();

	void Start();
	void Update();
	void Render();

public:
	ObjectType GetObjectType() const { return m_objectType; }


private:
	ObjectType m_objectType;
};

