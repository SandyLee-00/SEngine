#pragma once
#include "IManager.h"

/// <summary>
/// 
/// 240102 �̼���
/// </summary>
class ResourceManager : public IManager
{
public:
	ResourceManager() {};
	~ResourceManager() {};

public:
	void Initialize() override;
	void Finalize() override;
};

