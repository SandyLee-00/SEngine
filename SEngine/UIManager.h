#pragma once
#include "IManager.h"

/// <summary>
/// 
/// 240102 ¿Ãº≠øµ
/// </summary>

class UIManager : public IManager
{
public:
	UIManager() {};
	~UIManager() {};

	void Initialize() override;
	void Finalize() override;

	void ProcessUIEvent();
};

