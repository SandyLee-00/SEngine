#include "GameEngine.h"

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
	std::unordered_map<std::string, Scene*> scenes;

	Scene* startScene = new StartScene();
	scenes.insert(std::make_pair("StartScene", startScene));

	m_sceneManager->Initialize(scenes, startScene);
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
