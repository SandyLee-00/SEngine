#pragma once
#include "IManager.h"

/// <summary>
/// 
/// 240102 �̼���
/// </summary>

class SceneManager : public IManager
{
public:
	SceneManager() {};
	~SceneManager() {};

public:
	void Initialize() override;
	void Finalize() override;

};

