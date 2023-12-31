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
	void Update();
	void Render();

public:
	ObjectType GetObjectType() const { return m_objectType; }


private:
	ObjectType m_objectType;
};

