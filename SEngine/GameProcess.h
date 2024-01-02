#pragma once

#include <Windows.h>
#include <memory>

/// <summary>
/// 게임 시작	부터 종료까지의 흐름을 담당하는 클래스
/// 231231 이서영
/// </summary>
class GameProcess
{
public:
	GameProcess(HINSTANCE hInstance, int CmdShow);
	~GameProcess();

	bool Initialize();
	int Loop();
	void Finalize();

private:
	void RegisterClass(HINSTANCE hInstance);
	bool InitInstance();

private:
	HINSTANCE m_hInstance;
	int m_cmdShow;
	WNDCLASSEXW m_wcex;
	HWND m_hWnd;

private:

	// Renderer
	class Renderer* m_renderer;

	// Engine
	class GameEngine* m_gameEngine;

};

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);


