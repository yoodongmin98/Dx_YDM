#include "PrecompileHeader.h"
#include "EndingDeleteButton.h"
#include "ActorTypeEnum.h"
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>
//Core
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

EndingDeleteButton::EndingDeleteButton()
{
}

EndingDeleteButton::~EndingDeleteButton()
{
}

bool EndingAnimationImageBool11 = true;
void EndingDeleteButton::Start()
{
	if (true == EndingAnimationImageBool11)
	{
		AnimationImageLoad("EndingDeleteButton");
		EndingAnimationImageBool11 = false;
	}
	WoodPanel = Init(WoodPanel, "End_Planche.png", { 75,243 }, {0,-500,0});
	Buttons = NoChangeAnimationInit(Buttons, "End_BoutonDie_Closed1.png", { 259,131 }, { 60,-470 }, "DeleteButton", "EndingDeleteButton", 4, 0.1f, false);
}

void EndingDeleteButton::Update(float _DeltaTime)
{
	if (WoodPanel->GetTransform()->GetLocalPosition().y < -270.0f)
	{
		WoodPanel->GetTransform()->AddLocalPosition({ 0,200 * _DeltaTime ,0 });
		Buttons->GetTransform()->AddLocalPosition({ 0,200 * _DeltaTime ,0 });
	}
	if (GetLiveTime() > 24.5f)
	{
		Buttons->ChangeAnimation("DeleteButton");
	}
}

void EndingDeleteButton::Render(float _Delta)
{

};
