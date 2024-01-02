#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene() = default;
	~StartScene() {};

public:
	void Enter() override;
	void Exit() override;
};

