#pragma once

/// <summary>
/// Manager Interface
/// �������� �����ϰ� �Ǿ��־ RAII �Ұ���, 
/// -> GameEngine���� Initialize/Finalize�� ����
/// 
/// 240102 �̼���
/// </summary>

class IManager
{
public:
	IManager(){};
	virtual ~IManager() = 0;

	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

};

