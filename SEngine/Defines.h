#pragma once

/// <summary>
/// Scene에서 GameObject를 Type별로 놓고 이 순서로 부른다 
/// https://docs.unity3d.com/Manual/class-TagManager.html
/// 
/// 240112 이서영
/// </summary>
enum class Layers
{
	None,
	Background, // 가장 밑 레이어
	BackgroundObject, // 배경 오브젝트
	Object, // 일반 오브젝트
	Enemy, // 적
	Player, // 플레이어
	Effect, // 이펙트
	UI, // UI
	End = 32 // 가장 위 레이어
};

/// <summary>
/// GameObject에서 Component를 Type별로 놓고 이 순서로 부른다
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
/// CollisionManager에서 충돌을 판단할 때 사용하는 태그
/// 
/// https://docs.unity3d.com/Manual/class-TagManager.html
/// https://docs.unity3d.com/Manual/Tags.html
/// 240112 이서영
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

/// <summary>
/// Collision 정보는 Collider.OnCollisionEnter, Collider.OnCollisionStay 및 Collider.OnCollisionExit 이벤트에 전달됩니다.
/// 
/// https://docs.unity3d.com/ScriptReference/Collision.html
/// https://docs.unity3d.com/ScriptReference/ContactPoint.html
/// 240112 이서영
/// </summary>
struct Collision
{
	class Entity* otherGameObject;
	class BoxCollider* otherCollider;
	class BoxCollider* thisCollider;
};
