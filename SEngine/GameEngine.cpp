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
	// Time TimeManager deltaTime 계산
	m_timeManager->ProcessDeltaTime();
	float deltaTime = m_timeManager->GetDeltaTime();

	// Input InputManger 유저 키입력 체크
	m_inputManager->ProcessUserInput();

	// Physics SceneManager FIXED_DELTATIME FixedUpdate() 처리
	constexpr float PHYSICS_DELTATIME = 0.02f;
	m_elapsedPhysicsTime += deltaTime;

	while (m_elapsedPhysicsTime >= PHYSICS_DELTATIME)
	{
		m_sceneManager->FixedUpdate(PHYSICS_DELTATIME);
		m_elapsedPhysicsTime -= PHYSICS_DELTATIME;
	}
	
	// Update - Object 현재 Scene GameObject Update()
	m_sceneManager->Update(deltaTime);

	// Update - Collision 현재 충돌 상태 CollisionManager 처리
	m_collisionManager->ProcessCollision(deltaTime);

	// UI UI Event 처리
	m_UIManager->ProcessUIEvent();

	// Camera Camera이동
	m_cameraManager->ProcessCamera();

	// Render Renderer에서 BeginRender
	m_renderer->BeginRender();

	// GameObject Render 현재 씬에 있는 GameObject에 있는 Render 대상인 Component MeshRenderer
	m_sceneManager->Render(m_renderer);

	// DebugRender Time/Scene/Camera


}

void GameEngine::Finalize()
{

}
