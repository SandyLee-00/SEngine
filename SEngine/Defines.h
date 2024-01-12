#pragma once

/// <summary>
/// Scene���� GameObject�� Type���� ���� �� ������ �θ��� 
/// </summary>
enum class Layers
{
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
	RigidBody,
	Transform,

	BoxCollider,
	SphereCollider,
	End = 32
};