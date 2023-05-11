#include "PrecompileHeader.h"
#include "G_ActorBase.h"
//Base
#include <GameEngineBase/GameEngineString.h>
//PlatForm
//Core
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineActor.h>


G_ActorBase::G_ActorBase()
{

}

G_ActorBase::~G_ActorBase()
{
}

void G_ActorBase::Start()
{

}
void G_ActorBase::Update(float _DeltaTime)
{
	
}


void G_ActorBase::Repeat(float _MoveValue,float _DeltaTime)
{
		ReverseTime += _DeltaTime;
		if (ReverseTime < 1.0f)
		{
			GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { _MoveValue,GetTransform()->GetLocalPosition().y}, _DeltaTime));
		}
		if (ReverseTime > 1.0f)
		{
			GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(),{-_MoveValue,GetTransform()->GetLocalPosition().y }, _DeltaTime));
			if (ReverseTime > 2.0f)
			{
				ReverseTime = 0.0f;
			}
		}
}

void G_ActorBase::Init(std::shared_ptr<GameEngineSpriteRenderer> _Render, const std::string_view& _ImageName,float4 _Scale, float4 _Position)
{
	
	_Render = CreateComponent<GameEngineSpriteRenderer>();
	
	
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);
}

void G_ActorBase::AnimationImageLoad(const std::string_view& _FileName)
{
	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ThereisnogameResource");
	NewDir.Move("ThereisnogameResource");
	NewDir.Move("Animation");

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName(_FileName).GetFullPath());
}

void G_ActorBase::Down(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-400}, _DeltaTime));
}



void G_ActorBase::Up(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,300 }, _DeltaTime));
}

void G_ActorBase::FlagDown(float _EndValue,float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-_EndValue }, _DeltaTime));
}

void G_ActorBase::FlagUp(float _PlusXvalue,float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { -1300- _PlusXvalue,GetTransform()->GetLocalPosition().y}, _DeltaTime));
}