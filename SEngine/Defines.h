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
/// CollisionManager���� �浹�� �Ǵ��� �� ����ϴ� �±�
/// 
/// 240112 �̼���
/// </summary>
enum class Tags
{
	None,
	Enemy,
	Player,
	EnemyBullet,
	PlayerBullet,
	End = 32
};