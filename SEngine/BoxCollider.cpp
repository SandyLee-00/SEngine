#include "BoxCollider.h"

/// <summary>
/// Collider/rigidbody�� �ٸ� rigidbody/Collider�� �����ϱ� �����ϸ� OnCollisionEnter�� ȣ��˴ϴ�.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnCollisionEnter(const Collision& collision)
{

}

/// <summary>
/// OnCollisionStay�� �ٸ� Collider �Ǵ� rigidbody�� ��� ��� Collider �Ǵ� rigidbody�� ���� �����Ӵ� �� �� ȣ��˴ϴ�.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnCollisionStay(const Collision& collision)
{

}

/// <summary>
/// Collider/rigidbody�� �ٸ� rigidbody/Collider�� ������ ������ �� ȣ��˴ϴ�.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnCollisionExit(const Collision& collision)
{

}

/// <summary>
/// GameObject�� �ٸ� GameObject�� �浹�ϸ� Unity�� OnTriggerEnter�� ȣ���մϴ�.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnTriggerEnter(const BoxCollider& otherCollider)
{
	
}

/// <summary>
/// Trigger�� ��� �ٸ� ��� Collider�� ���� ���� ��� �����ӿ��� OnTriggerStay�� ȣ��˴ϴ�. 
/// �� �Լ��� ���� Ÿ�̸ӿ� �����Ƿ� �ݵ�� �� �����Ӹ��� ��������� �ʽ��ϴ�.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnTriggerStay(const BoxCollider& otherCollider)
{

}

/// <summary>
/// OnTriggerExit�� �ٸ� Collider�� Trigger ��ġ�� ������ �� ȣ��˴ϴ�.
/// </summary>
/// <param name="otherCollider"></param>
void BoxCollider::OnTriggerExit(const BoxCollider& otherCollider)
{

}
