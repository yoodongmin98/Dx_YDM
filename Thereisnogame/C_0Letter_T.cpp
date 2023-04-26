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
	Letter_T = CreateComponent<GameEngineSpriteRenderer>();
	Letter_T->SetTexture("Letter01.png");
	Letter_T->GetTransform()->SetLocalScale({ 140.0f, 458.0f,1.0f });
	Letter_T->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });

}

void C_Letter_T::Update(float _DeltaTime)
{


}

void C_Letter_T::Render(float _Delta)
{

};
