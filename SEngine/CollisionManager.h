#pragma once

/// <summary>
/// 
/// 240102 �̼���
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

