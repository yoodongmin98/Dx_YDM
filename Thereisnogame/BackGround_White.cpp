#include "PrecompileHeader.h"
#include "BackGround_White.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

BackGroundWhite::BackGroundWhite()
{
}

BackGroundWhite::~BackGroundWhite()
{
}

void BackGroundWhite::Start()
{
	WhiteBackGround = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::WhiteFront);
	WhiteBackGround->SetTexture("BackGroundWhite.png");
	WhiteBackGround->GetTransform()->SetLocalScale({ 1280.0f, 720.0f,1.0f });
	WhiteBackGround->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });

	WhiteBackGround->ColorOptionValue.MulColor.a = 0.1f;
}

void BackGroundWhite::Update(float _DeltaTime)
{

}

void BackGroundWhite::Render(float _Delta)
{

};


