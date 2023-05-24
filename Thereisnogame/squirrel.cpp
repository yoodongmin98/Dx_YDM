#include "PrecompileHeader.h"
#include "squirrel.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor


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
