#pragma once
#include "IManager.h"

/// <summary>
/// 
/// 240102 �̼���
/// </summary>
class PathManager : public IManager
{
public:
	PathManager() {};
	~PathManager() {};

public:
	void Initialize() override;
	void Finalize() override;
};

