#pragma once

#include "Defines.h"

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
	ObjectOrder GetObjectType() const { return m_objectType; }


private:
	ObjectOrder m_objectType;
};

