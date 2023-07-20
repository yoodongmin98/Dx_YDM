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
	WoodPanel = Init(WoodPanel, "End_Planche.png", { 75,243 }, float4::Zero);
	Buttons = NoChangeAnimationInit(Buttons, "End_BoutonDie_Closed1.png", { 259,131 }, { -60,50 }, "DeleteButton", "EndingDeleteButton", 4, 0.1f, false);
}

void EndingDeleteButton::Update(float _DeltaTime)
{
}

void EndingDeleteButton::Render(float _Delta)
{

};

//void EndingDeleteButton::CurtainOpen()
//{
//	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
//	if (LeftCurtain->GetTransform()->GetLocalPosition().x > -1000.0f)
//	{
//		LeftCurtain->GetTransform()->AddLocalPosition({ -1.0f * Times,0,0 });
//	}
//	if (RightCurtain->GetTransform()->GetLocalPosition().x < 1000.0f)
//	{
//		RightCurtain->GetTransform()->AddLocalPosition({ 1.0f * Times,0,0 });
//	}
//}
//void EndingDeleteButton::CurtainClose()
//{
//	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
//	if (LeftCurtain->GetTransform()->GetLocalPosition().x < -290.0f)
//	{
//		LeftCurtain->GetTransform()->AddLocalPosition({ 10.0f * Times,0,0 });
//	}
//	if (RightCurtain->GetTransform()->GetLocalPosition().x > 290.0f)
//	{
//		RightCurtain->GetTransform()->AddLocalPosition({ -10.0f * Times,0,0 });
//	}
//}
