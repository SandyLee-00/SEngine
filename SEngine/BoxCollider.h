#pragma once

#include "Component.h"
#include "Vector3.h"

/// <summary>
/// �����÷��� �߿� �ݶ��̴��� �ִ� ������Ʈ�� �������� �ϴ� ���, ������Ʈ�� ������ٵ� ������Ʈ�� ÷���ؾ� �մϴ�. 
/// ������Ʈ�� �ٸ� ������Ʈ�� �������� ��ȣ�ۿ��� ���� �ʵ��� �Ϸ��� ������ٵ� Ű�׸�ƽ���� ������ �� �ֽ��ϴ�.
/// OnTriggerEnter�� �޸� OnCollisionEnter�� Collider �ƴ� Collision Ŭ������ ���޹޽��ϴ�.
/// 
/// https://docs.unity3d.com/ScriptReference/BoxCollider.html
/// https://docs.unity3d.com/ScriptReference/Collision.html
/// https://docs.unity3d.com/ScriptReference/ContactPoint.html
/// 240112 �̼���
/// </summary>
class BoxCollider : public Component
{
public:
	// Constructors

	// Public Methods


	// Messages
	void OnCollisionEnter(const Collision& otherCollider);
	void OnCollisionStay(const Collision& otherCollider);
	void OnCollisionExit(const Collision& otherCollider);
	void OnTriggerEnter(const BoxCollider& otherCollider);
	void OnTriggerStay(const BoxCollider& otherCollider);
	void OnTriggerExit(const BoxCollider& otherCollider);

private:
	// Properties
	Vector3 center;
	Vector3 size;

	// Inherited Members Properties
	bool isTrigger;
};

