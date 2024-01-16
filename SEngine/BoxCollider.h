#pragma once

#include "Component.h"
#include "Vector3.h"

/// <summary>
/// �����÷��� �߿� �ݶ��̴��� �ִ� ������Ʈ�� �������� �ϴ� ���, ������Ʈ�� ������ٵ� ������Ʈ�� ÷���ؾ� �մϴ�. 
/// ������Ʈ�� �ٸ� ������Ʈ�� �������� ��ȣ�ۿ��� ���� �ʵ��� �Ϸ��� ������ٵ� Ű�׸�ƽ���� ������ �� �ֽ��ϴ�.
/// OnTriggerEnter�� �޸� OnCollisionEnter�� Collider �ƴ� Collision Ŭ������ ���޹޽��ϴ�.
/// if (collision.gameObject.name == "MyGameObjectName") Tag X Name O
/// 
/// https://docs.unity3d.com/ScriptReference/BoxCollider.html
/// https://docs.unity3d.com/ScriptReference/Collision.html
/// https://docs.unity3d.com/ScriptReference/ContactPoint.html
/// https://docs.unity3d.com/550/Documentation/Manual/LayerBasedCollision.html
/// 240112 �̼���
/// </summary>
class BoxCollider : public Component
{
public:
	// Constructors

	// Process
// 	virtual void Start() override;
// 	virtual void FixedUpdate(float FIXED_DELTATIME) override;
// 	virtual void Update(float deltaTime) override;
// 	virtual void DebugRender(class Renderer* renderer) override;

	// Public Methods


	// Messages
	void OnCollisionEnter(const Collision& collision);
	void OnCollisionStay(const Collision& collision);
	void OnCollisionExit(const Collision& collision);
	void OnTriggerEnter(const BoxCollider& otherCollider);
	void OnTriggerStay(const BoxCollider& otherCollider);
	void OnTriggerExit(const BoxCollider& otherCollider);

private:
	// Properties
	Vector3 center;
	Vector3 size;

	// Inherited Members Properties
	bool isTrigger;
	Vector3 offset;
};

