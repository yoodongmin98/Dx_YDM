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
	Init(Letter_N, "Letter08.png", { 161,464,1 }, { -170,190,0 });
	Init(Letter_O, "Letter09.png", { 124,468,1 }, { -70,200,0 });

	Init(Letter_A, "Letter11.png", { 124,468,1 }, { 90,200,0 });
	Init(Letter_G, "Letter10.png", { 128,440,1 }, { 30,210,0 });
	Init(Letter_E2, "Letter13.png", { 110,425,1 }, { 250,200,0 });
	Init(Letter_M, "Letter12.png", { 161,459,1 }, { 160,180,0 });



	Init(Letter_H, "Letter02.png", { 125,459,1 }, { -100,300,0 });
	Init(Letter_T, "Letter01.png", { 140,458,1 }, { -180,320,0 });
	Init(Letter_R, "Letter04.png", { 100,446,1 }, { 30,310,0 });
	Init(Letter_E, "Letter03.png", { 134,458,1 }, { -40,310,0 });
	Init(Letter_e, "Letter05.png", { 115,452,1 }, {  80,320,0 });

	Init(Letter_I, "Letter06.png", { 88,434,1 }, { 170,310,0 });
	Init(Letter_S, "Letter07.png", { 103,436,1 }, { 200,290,0 });

	
}

void C_Letter_T::Update(float _DeltaTime)
{
	LetterRepeat(0.05, _DeltaTime);
	


}

void C_Letter_T::Render(float _Delta)
{

};