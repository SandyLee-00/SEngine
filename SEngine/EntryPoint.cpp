/// <summary>
/// 2023.12.20
/// �赿�� ���¿�
/// ���� ������ ����!
/// </summary>
#include <memory>

#include "framework.h"

//���ӿ��� ���
#include "GameProcess.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	std::unique_ptr<GameProcess> gameProcess = std::make_unique<GameProcess>(hInstance, nCmdShow);

	if (gameProcess->Initialize())
	{
		gameProcess->Loop();
	}

	gameProcess->Finalize();
}