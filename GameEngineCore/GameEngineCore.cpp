#include "PrecompileHeader.h"
#include "GameEngineCore.h"
#include <GameEngineBase\GameEngineDebug.h>
#include <GameEnginePlatform\GameEngineInput.h>
#include <GameEnginePlatform\GameEngineWindow.h>
#include <GameEnginePlatform\GameEngineSound.h>
#include <GameEnginePlatform\GameEngineInput.h>
#include <GameEngineBase\GameEngineTime.h>
#include "GameEngineDevice.h"

std::map<std::string, std::shared_ptr<GameEngineLevel>> GameEngineCore::LevelMap;
std::shared_ptr<GameEngineLevel> GameEngineCore::MainLevel = nullptr;
std::shared_ptr<GameEngineLevel> GameEngineCore::NextLevel = nullptr;

GameEngineCore::GameEngineCore() 
{
}

GameEngineCore::~GameEngineCore() 
{
}

void GameEngineCore::EngineStart(std::function<void()> _ContentsStart)
{
	// �ھ��̴ϼȶ�����
	// Rect Box

	GameEngineDevice::Initialize();

	CoreResourcesInit();

	if (nullptr == _ContentsStart)
	{
		MsgAssert("���� �������� �������� �ʽ��ϴ�.");
	}
	_ContentsStart();
}

void GameEngineCore::EngineUpdate() 
{
	if (nullptr != NextLevel)
	{
		MainLevel = NextLevel;
	}

	if (nullptr == MainLevel)
	{
		MsgAssert("�ƹ��� ������ �������� �ʰ� �ֽ��ϴ�.");
		return;
	}

	float TimeDeltaTime = GameEngineTime::GlobalTime.TimeCheck();
	GameEngineInput::Update(TimeDeltaTime);
	GameEngineSound::SoundUpdate();

	MainLevel->TimeEvent.Update(TimeDeltaTime);
	MainLevel->Update(TimeDeltaTime);

	GameEngineDevice::RenderStart();
	MainLevel->Render(TimeDeltaTime);
	GameEngineDevice::RenderEnd();
}

void GameEngineCore::EngineEnd(std::function<void()> _ContentsEnd)
{
	if (nullptr == _ContentsEnd)
	{
		MsgAssert("�� �������� �������� �ʽ��ϴ�.");
	}

	_ContentsEnd();

	LevelMap.clear();
	CoreResourcesEnd();
	GameEngineDevice::Release();
}

void GameEngineCore::Start(HINSTANCE _instance,  std::function<void()> _Start, std::function<void()> _End, float4 _Pos, float4 _Size)
{
	GameEngineDebug::LeakCheck();

	if (false == GameEngineInput::IsKey("EngineMouseLeft"))
	{
		GameEngineInput::CreateKey("EngineMouseLeft", VK_LBUTTON);
		GameEngineInput::CreateKey("EngineMouseRight", VK_RBUTTON);
	}

	GameEngineWindow::WindowCreate(_instance, "MainWindow", _Size, _Pos);
	GameEngineWindow::WindowLoop(std::bind(GameEngineCore::EngineStart, _Start), GameEngineCore::EngineUpdate, std::bind(GameEngineCore::EngineEnd, _End));
}

void GameEngineCore::ChangeLevel(const std::string_view& _Name) 
{
	std::string UpperName = GameEngineString::ToUpper(_Name);

	if (LevelMap.end() == LevelMap.find(UpperName))
	{
		MsgAssert("�������� �ʴ� ������ ü���� �Ϸ��� �߽��ϴ�.");
		return;
	}

	NextLevel = LevelMap[UpperName];
}

void GameEngineCore::LevelInit(std::shared_ptr<GameEngineLevel> _Level) 
{
	_Level->Start();
}

