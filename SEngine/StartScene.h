#pragma once
#include "Scene.h"

/// <summary>
/// �⺻������ �ִ� ó�� �����ϴ� �� 
/// 
/// 240103 �̼���
/// </summary>
class StartScene : public Scene
{
public:
	StartScene() = default;
	~StartScene() {};

public:
	void Enter() override;
	void Exit() override;
};

