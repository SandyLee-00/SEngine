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
	// Time TimeManager deltaTime ���

	// Input InputManger ���� Ű�Է� üũ

	// Physics SceneManager FIXED_DELTATIME FixedUpdate() ó��

	// Update - Object ���� Scene GameObject Update()

	// Update - Collision ���� �浹 ���� CollisionManager ó��

	// UI UI Event ó��

	// Camera Camera�̵�

	// Render Renderer���� BeginRender

	// GameObject Render ���� ���� �ִ� GameObject�� �ִ� Render ����� Component MeshRenderer

	// DebugRender Time/Scene/Camera
}

void GameEngine::Finalize()
{

}
