#pragma once

#include <Windows.h>
#include <memory>

class GameProcess
{
public:
	GameProcess(HINSTANCE hInstance, int CmdShow);
	~GameProcess();

	bool Initialize();
	int Loop();
	void Finalize();



private:

	void Update();
	void Render();


private:
	void RegisterClass(HINSTANCE hInstance);
	bool InitInstance();


public:

private:
	HINSTANCE m_hInstance;
	int m_cmdShow;
	WNDCLASSEXW m_wcex;
	HWND m_hWnd;
};

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);


