#include "GameEngine.h"

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::Initialize(HWND hWnd, Renderer* renderer)
{
	// GameEngine Initialize
	m_hWnd = hWnd;
	m_renderer = renderer;

	// Manager Initialize

}

void GameEngine::Process()
{
	// Time TimeManager deltaTime 계산

	// Input InputManger 유저 키입력 체크

	// Physics SceneManager FIXED_DELTATIME FixedUpdate() 처리

	// Update - Object 현재 Scene GameObject Update()

	// Update - Collision 현재 충돌 상태 CollisionManager 처리

	// UI UI Event 처리

	// Camera Camera이동

	// Render Renderer에서 BeginRender

	// GameObject Render 현재 씬에 있는 GameObject에 있는 Render 대상인 Component MeshRenderer

	// DebugRender Time/Scene/Camera
}

void GameEngine::Finalize()
{

}
