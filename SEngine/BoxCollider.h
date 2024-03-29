#pragma once

#include "Component.h"
#include "Vector3.h"

/// <summary>
/// 게임플레이 중에 콜라이더가 있는 오브젝트를 움직여야 하는 경우, 오브젝트에 리지드바디 컴포넌트도 첨부해야 합니다. 
/// 오브젝트가 다른 오브젝트와 물리적인 상호작용을 하지 않도록 하려면 리지드바디를 키네마틱으로 설정할 수 있습니다.
/// OnTriggerEnter와 달리 OnCollisionEnter는 Collider 아닌 Collision 클래스를 전달받습니다.
/// if (collision.gameObject.name == "MyGameObjectName") Tag X Name O
/// 
/// https://docs.unity3d.com/ScriptReference/BoxCollider.html
/// https://docs.unity3d.com/ScriptReference/Collision.html
/// https://docs.unity3d.com/ScriptReference/ContactPoint.html
/// https://docs.unity3d.com/550/Documentation/Manual/LayerBasedCollision.html
/// 240112 이서영
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

