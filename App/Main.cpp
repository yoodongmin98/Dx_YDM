#include <Windows.h>
#include <GameEngineBase\GameEngineFile.h>
#include <GameEngineBase\GameEngineDirectory.h>
#include <GameEngineCore\GameEngineCore.h>
#include <Thereisnogame\GameCore.h>

#pragma comment(lib, "GameEngineCore.lib")
#pragma comment(lib, "Thereisnogame.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	GameEngineCore::Start(hInstance,
		GameCore::GameStart,
		GameCore::GameEnd,
		{ 2000, 0 }
	);
}

