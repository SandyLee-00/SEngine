#pragma once

#include "Component.h"
#include "Vector3.h"

/// <summary>
/// �����÷��� �߿� �ݶ��̴��� �ִ� ������Ʈ�� �������� �ϴ� ���, ������Ʈ�� ������ٵ� ������Ʈ�� ÷���ؾ� �մϴ�. 
/// ������Ʈ�� �ٸ� ������Ʈ�� �������� ��ȣ�ۿ��� ���� �ʵ��� �Ϸ��� ������ٵ� Ű�׸�ƽ���� ������ �� �ֽ��ϴ�.
/// 
/// https://docs.unity3d.com/ScriptReference/BoxCollider.html
/// </summary>
class BoxCollider : public Component
{
public:
	// Constructors

	// Public Methods

	// Messages
	void OnCollisionEnter(const BoxCollider& collision);


private:
	// Properties
	Vector3 center;
	Vector3 size;

	// Inherited Members Properties
	bool isTrigger;
	class GameObject* gameObject;
};

