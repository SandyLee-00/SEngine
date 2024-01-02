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
