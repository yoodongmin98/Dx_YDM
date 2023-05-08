#include "PrecompileHeader.h"
#include "squirrel.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>


squirrel::squirrel()
{
}

squirrel::~squirrel()
{
}

void squirrel::Start()
{
	Init(squirrels, "Squirrel_Oss.png", {381,520}, { 0,10,0 });
}

void squirrel::Update(float _DeltaTime)
{

}

void squirrel::Render(float _Delta)
{

};
