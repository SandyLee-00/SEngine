#pragma once
#include "Scene.h"

/// <summary>
/// 기본적으로 있는 처음 시작하는 씬 
/// 
/// 240103 이서영
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

