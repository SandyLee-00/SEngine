#pragma once
#include "IManager.h"

/// <summary>
/// 
/// 240102 ÀÌ¼­¿µ
/// </summary>

class SoundManager : public IManager
{
public:
	SoundManager() {};
	~SoundManager() {};

public:
	void Initialize() override;
	void Finalize() override;
};

