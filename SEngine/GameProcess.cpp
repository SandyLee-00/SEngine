#include "framework.h"
#include "GameProcess.h"
#include "resource.h"

#define MAX_LOADSTRING 100
WCHAR szTitle[MAX_LOADSTRING] = L"Demo";
WCHAR szWindowClass[MAX_LOADSTRING] = L"Demo";

GameProcess::GameProcess(HINSTANCE hInstance, int CmdShow) : m_hInstance(hInstance), m_cmdShow(CmdShow)
{

}

GameProcess::~GameProcess()
{

}

bool GameProcess::Initialize()
{
	RegisterClass(m_hInstance);

	if (!InitInstance())
	{
		return FALSE;
	}

	return true;
}

int GameProcess::Loop()
{
	MSG msg;

	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Update();
			Render();
		}
	}

	return (int)msg.wParam;
}

void GameProcess::Finalize()
{

}

void GameProcess::Update()
{

}

void GameProcess::Render()
{

}

void GameProcess::RegisterClass(HINSTANCE hInstance)
{
	m_wcex.cbSize = sizeof(WNDCLASSEX);
	m_wcex.style = CS_HREDRAW | CS_VREDRAW;
	m_wcex.lpfnWndProc = WndProc;
	m_wcex.cbClsExtra = 0;
	m_wcex.cbWndExtra = 0;
	m_wcex.hInstance = hInstance;
	m_wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SENGINE));
	m_wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	m_wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	m_wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_SENGINE);
	m_wcex.lpszClassName = szWindowClass;
	m_wcex.hIconSm = LoadIcon(m_wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&m_wcex);
}

bool GameProcess::InitInstance()
{
	m_hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInstance, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	ShowWindow(m_hWnd, m_cmdShow);
	UpdateWindow(m_hWnd);

	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}