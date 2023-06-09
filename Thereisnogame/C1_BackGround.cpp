#include "PrecompileHeader.h"
#include "C1_BackGround.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

C1_BackGround::C1_BackGround()
{
}

C1_BackGround::~C1_BackGround()
{
}

void C1_BackGround::Start()
{
	BackGround = CreateComponent<GameEngineSpriteRenderer>();
	BackGround->SetTexture("TiledBackground_Chap01.png");
	BackGround->GetTransform()->SetLocalScale({ 1280.0f, 720.0f,1.0f });
	BackGround->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
}

void C1_BackGround::Update(float _DeltaTime)
{

}

void C1_BackGround::Render(float _Delta)
{

};


