#pragma once

#include "ObjectType.h"

/// <summary>
/// Scene���� Update �ϴ� GameObject
/// IComponent�� ����� Component�� ���� ����Ѵ� 
/// 231231 �̼���
/// </summary>
class GameObject
{

public:
	GameObject();
	virtual ~GameObject();

	void Start();
	void FixedUpdate(float FIXED_DELTATIME);
	void Update(float deltaTime);
	void Render(class Renderer* renderer);

public:
	ObjectType GetObjectType() const { return m_objectType; }


private:
	ObjectType m_objectType;
};

