/// <summary>
/// 2023.12.20
/// 김동일 유승운
/// 게임 껍데기 시작!
/// </summary>
#include <memory>

#include "framework.h"

//게임엔진 헤더
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