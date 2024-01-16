#include "BoxCollider.h"

/// <summary>
/// Collider/rigidbody가 다른 rigidbody/Collider와 접촉하기 시작하면 OnCollisionEnter가 호출됩니다.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnCollisionEnter(const Collision& collision)
{

}

/// <summary>
/// OnCollisionStay는 다른 Collider 또는 rigidbody에 닿는 모든 Collider 또는 rigidbody에 대해 프레임당 한 번 호출됩니다.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnCollisionStay(const Collision& collision)
{

}

/// <summary>
/// Collider/rigidbody가 다른 rigidbody/Collider와 접촉을 멈췄을 때 호출됩니다.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnCollisionExit(const Collision& collision)
{

}

/// <summary>
/// GameObject가 다른 GameObject와 충돌하면 Unity는 OnTriggerEnter를 호출합니다.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnTriggerEnter(const BoxCollider& otherCollider)
{
	
}

/// <summary>
/// Trigger에 닿는 다른 모든 Collider에 대해 거의 모든 프레임에서 OnTriggerStay가 호출됩니다. 
/// 이 함수는 물리 타이머에 있으므로 반드시 매 프레임마다 실행되지는 않습니다.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnTriggerStay(const BoxCollider& otherCollider)
{

}

/// <summary>
/// OnTriggerExit는 다른 Collider가 Trigger 터치를 멈췄을 때 호출됩니다.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnTriggerExit(const BoxCollider& otherCollider)
{

}
