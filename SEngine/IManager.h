#pragma once

/// <summary>
/// Manager Interface
/// 참조관계 복잡하게 되어있어서 RAII 불가능, 
/// -> GameEngine에서 Initialize/Finalize로 관리
/// 
/// 240102 이서영
/// </summary>

class IManager
{
public:
	IManager(){};
	virtual ~IManager() = 0;

	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

};

