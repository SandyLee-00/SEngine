#pragma once

/// <summary>
/// 
/// 240102 ¿Ãº≠øµ
/// </summary>
class CollisionManager
{
public:
	CollisionManager() {};
	~CollisionManager() {};

	void Initalize();
	void Finalize();

	void ProcessCollision(float deltaTime);
};

