#include "PrecompileHeader.h"
#include "C2_BackGround.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C2_BackGround::C2_BackGround()
{
}

C2_BackGround::~C2_BackGround()
{
}

void C2_BackGround::Start()
{
	BackGround = CreateComponent<GameEngineSpriteRenderer>();
	BackGround->SetTexture("TiledBackground_Chap02.png");
	BackGround->GetTransform()->SetLocalScale({ 1280.0f, 720.0f,1.0f });
	BackGround->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
}

void C2_BackGround::Update(float _DeltaTime)
{

}

void C2_BackGround::Render(float _Delta)
{

};


