#pragma once
#include "Component.h"

/// <summary>
/// 3차원 공간에서 GameObject의 물리와 중력을 담당하는 컴포넌트
/// </summary>
class RigidBody : Component
{

private:
	float mass;
	float gravityScale;
};

