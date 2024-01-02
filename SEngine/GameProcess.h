#pragma once

#include <Windows.h>
#include <memory>

/// <summary>
/// ���� ����	���� ��������� �帧�� ����ϴ� Ŭ����
/// 231231 �̼���
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


