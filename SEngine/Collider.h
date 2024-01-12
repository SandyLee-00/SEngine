#pragma once

/// <summary>
/// 게임플레이 중에 콜라이더가 있는 오브젝트를 움직여야 하는 경우, 오브젝트에 리지드바디 컴포넌트도 첨부해야 합니다. 
/// 오브젝트가 다른 오브젝트와 물리적인 상호작용을 하지 않도록 하려면 리지드바디를 키네마틱으로 설정할 수 있습니다.
/// 
/// https://docs.unity3d.com/Manual/collision-section.html
/// https://docs.unity3d.com/ScriptReference/Collider.html
/// </summary>
class Collider
{
public:
	// Constructors

	// Public Methods

	// Messages



private:
	// Properties
	bool isTrigger;

	class GameObject* gameObject;
};

