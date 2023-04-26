#include "PrecompileHeader.h"
#include "C_0Letter_T.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C_Letter_T::C_Letter_T()
{
}

C_Letter_T::~C_Letter_T()
{
}

void C_Letter_T::Start()
{
	Init(Letter_T, "Letter01.png", { 140,458,1 }, { -200,200,0 });
	Init(Letter_H, "Letter02.png", { 140,458,1 }, { -150,200,0 });
	Init(Letter_E, "Letter03.png", { 140,458,1 }, { -100,200,0 });
	Init(Letter_R, "Letter04.png", { 140,458,1 }, { -50,200,0 });
	Init(Letter_e, "Letter05.png", { 140,458,1 }, {  0,200,0 });
	Init(Letter_I, "Letter06.png", { 140,458,1 }, { 50,200,0 });
	Init(Letter_S, "Letter07.png", { 140,458,1 }, { 100,200,0 });
	/*Init(Letter_N, "Letter08.png", { 140,458,1 }, { 150,200,0 });
	Init(Letter_O, "Letter09.png", { 140,458,1 }, { 200,200,0 });
	Init(Letter_G, "Letter010.png", { 140,458,1 }, { -150,200,0 });
	Init(Letter_A, "Letter11.png", { 140,458,1 }, { -150,200,0 });
	Init(Letter_M, "Letter12.png", { 140,458,1 }, { -150,200,0 });
	Init(Letter_E2, "Letter13.png", { 140,458,1 }, { -150,200,0 });*/
}

void C_Letter_T::Update(float _DeltaTime)
{
	
	


}

void C_Letter_T::Render(float _Delta)
{

};
