#pragma once
#include "IManager.h"

/// <summary>
/// 
/// 240102 ¿Ãº≠øµ
/// </summary>

class CameraManager : public IManager
{
public:
	CameraManager() {};
	~CameraManager() {};

	void Initialize() override;
	void Finalize() override;

	void ProcessCamera();
};

