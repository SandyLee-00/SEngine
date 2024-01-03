#include "GameEngine.h"

#include "Renderer.h"

#include "PathManager.h"
#include "ResourceManager.h"
#include "SoundManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "CollisionManager.h"
#include "UIManager.h"
#include "AllManagers.h"

#include "Scene.h"

#include "StartScene.h"

GameEngine::~GameEngine()
{

}

void GameEngine::Initialize(HWND hWnd, Renderer* renderer)
{
	// ==== <GameEngine variable Initialize>
	m_hWnd = hWnd;
	m_renderer = renderer;

	// ==== <Manager new()>
	
	// Resource
	m_pathManager = new PathManager();
	m_resourceManager = new ResourceManager();
	m_soundManager = new SoundManager();

	// Life Cycle - main
	m_timeManager = new TimeManager();
	m_inputManager = new InputManager();
	m_sceneManager = new SceneManager();
	m_cameraManager = new CameraManager();

	// Life Cycle - Physics
	m_collisionManager = new CollisionManager();

	// UI
	m_UIManager = new UIManager();

	// AllManagers
	m_allManagers = new AllManagers();

	// ==== <Manager Initialize>
	m_allManagers->Initialize(m_pathManager, m_resourceManager, m_soundManager, m_timeManager, m_inputManager, m_sceneManager, m_cameraManager, m_collisionManager, m_UIManager);

	// ==== <Scene Initialize>
	Scene* startScene = new StartScene();
	m_scenes.insert(std::make_pair("StartScene", startScene));

	m_sceneManager->Initialize(m_scenes, startScene);
}

void GameEngine::Process()
{
	// Time TimeManager deltaTime ���
	m_timeManager->ProcessDeltaTime();
	float deltaTime = m_timeManager->GetDeltaTime();

	// Input InputManger ���� Ű�Է� üũ
	m_inputManager->ProcessUserInput();

	// Physics SceneManager FIXED_DELTATIME FixedUpdate() ó��
	constexpr float PHYSICS_DELTATIME = 0.02f;
	m_elapsedPhysicsTime += deltaTime;

	while (m_elapsedPhysicsTime >= PHYSICS_DELTATIME)
	{
		m_sceneManager->FixedUpdate(PHYSICS_DELTATIME);
		m_elapsedPhysicsTime -= PHYSICS_DELTATIME;
	}
	
	// Update - Object ���� Scene GameObject Update()
	m_sceneManager->Update(deltaTime);

	// Update - Collision ���� �浹 ���� CollisionManager ó��
	m_collisionManager->ProcessCollision(deltaTime);

	// UI UI Event ó��
	m_UIManager->ProcessUIEvent();

	// Camera Camera�̵�
	m_cameraManager->ProcessCamera();

	// Render Renderer���� BeginRender
	m_renderer->BeginRender();

	// GameObject Render ���� ���� �ִ� GameObject�� �ִ� Render ����� Component MeshRenderer
	m_sceneManager->Render(m_renderer);

	// DebugRender Time/Scene/Camera


}

void GameEngine::Finalize()
{

}
