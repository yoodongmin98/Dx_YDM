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


//Actor
#include "SquirrelCloud_Need.h"
#include "SquirrelCloud_Crack.h"

squirrel::squirrel()
{
}

squirrel::~squirrel()
{
}

void squirrel::Start()
{
	Init(squirrels, "Squirrel_Oss.png", {381,520}, { 0,10,0 });
	squirrelsCollision = CollisionInit(squirrelsCollision, { 300,300 }, { 0,10,0 });

}

void squirrel::Update(float _DeltaTime)
{
	ManagedCollision(squirrelsCollision, 0);
	if (true == ClickCheck(squirrelsCollision))
	{
		
	}
	//도토리와 닿았을때는 다르게
}

void squirrel::Render(float _Delta)
{

};
