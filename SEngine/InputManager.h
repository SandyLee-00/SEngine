#pragma once
#include "IManager.h"

/// <summary>
/// 
/// 240102 �̼���
/// </summary>

class InputManager : public IManager
{
public:
	InputManager() {};
	~InputManager() {};

	void Initialize() override;
	void Finalize() override;

};

