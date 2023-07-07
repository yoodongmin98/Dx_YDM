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


#include "MainMenuLevel.h"
SelectBox::SelectBox()
{
}

SelectBox::~SelectBox()
{
}

void SelectBox::Start()
{
	Box_1=Init(Box_1, "MenuPrincipal_Panel_Jeu.png", { 312,276,1 }, { -330,-580,0 });
	Box_2=Init(Box_2, "MenuPrincipal_Panel_Options.png", {315,246,1 }, { 0,-590,0 });
	Box_3=Init(Box_3, "MenuPrincipal_Panel_Quit.png", { 315,300,1 }, { 330,-560,0 });


	Box_1Collision = CollisionInit(Box_1Collision, { 315,200,1 }, { -330,-620,0 });
	Box_2Collision = CollisionInit(Box_2Collision, { 315,200,1 }, { 0,-620,0 });
	Box_3Collision = CollisionInit(Box_3Collision, { 315,200,1 }, { 330,-620,0 });

	Play(Sound, "MainMenu_PanelChoiceIn.wav", 0.1f);
}

void SelectBox::Update(float _DeltaTime)
{
	if (true == ClickCheck(Box_1Collision))
	{
		MainMenuLevel::ML->SetIsClickStartButtonTrue();
	}
}

void SelectBox::Render(float _Delta)
{

};
