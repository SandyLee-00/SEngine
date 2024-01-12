#pragma once

/// <summary>
/// Scene���� GameObject�� Type���� ���� �� ������ �θ��� 
/// https://docs.unity3d.com/Manual/class-TagManager.html
/// 
/// 240112 �̼���
/// </summary>
enum class Layers
{
	None,
	Background, // ���� �� ���̾�
	BackgroundObject, // ��� ������Ʈ
	Object, // �Ϲ� ������Ʈ
	Enemy, // ��
	Player, // �÷��̾�
	Effect, // ����Ʈ
	UI, // UI
	End = 32 // ���� �� ���̾�
};

/// <summary>
/// GameObject���� Component�� Type���� ���� �� ������ �θ���
/// </summary>
enum class ComponentOrder
{
	None,
	RigidBody,
	Transform,

	BoxCollider,
	SphereCollider,
	End = 32
};

/// <summary>
/// Entity�� ������
/// void OnCollisionEnter(Collision collision) ���� if (collision.gameObject.tag == "MyGameObjectTag") ó�� ����Ѵ� 
/// + �ϴ� �̸����� ���� ���߿� �߰��ϱ�
/// 
/// https://docs.unity3d.com/Manual/class-TagManager.html
/// https://docs.unity3d.com/Manual/Tags.html
/// 240112 �̼���
/// </summary>
// enum class Tags
// {
// 	None,
// 	Enemy,
// 	Player,
// 	EnemyBullet,
// 	PlayerBullet,
// 	End = 32
// };

/// <summary>
/// Collision ������ Collider.OnCollisionEnter, Collider.OnCollisionStay �� Collider.OnCollisionExit �̺�Ʈ�� ���޵˴ϴ�.
/// 
/// https://docs.unity3d.com/ScriptReference/Collision.html
/// https://docs.unity3d.com/ScriptReference/ContactPoint.html
/// 240112 �̼���
/// </summary>
struct Collision
{
	class Entity* otherEntity;
	class BoxCollider* otherCollider;
	class BoxCollider* thisCollider;
};
