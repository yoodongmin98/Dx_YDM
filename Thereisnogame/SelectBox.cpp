#include "PrecompileHeader.h"
#include "SelectBox.h"

//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

SelectBox::SelectBox()
{
}

SelectBox::~SelectBox()
{
}

void SelectBox::Start()
{
	Init(Box_1, "MenuPrincipal_Panel_Jeu.png", { 312,276,1 }, { -330,-580,0 });
	Init(Box_2, "MenuPrincipal_Panel_Options.png", {315,246,1 }, { 0,-590,0 });
	Init(Box_3, "MenuPrincipal_Panel_Quit.png", { 315,300,1 }, { 330,-560,0 });
}

void SelectBox::Update(float _DeltaTime)
{

}

void SelectBox::Render(float _Delta)
{

};
