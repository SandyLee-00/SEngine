#pragma once
#include <Windows.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Initialize(HWND hWnd);
	void Render();

public:
	void BeginRender();
	void EndRender();
};

