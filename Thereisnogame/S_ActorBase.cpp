#include "PrecompileHeader.h"
#include "S_ActorBase.h"
//Base
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineMath.h>
//PlatForm
//Core
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineActor.h>


S_ActorBase::S_ActorBase()
{

}

S_ActorBase::~S_ActorBase()
{
}

void S_ActorBase::Start()
{

}
void S_ActorBase::Update(float _DeltaTime)
{

}


void S_ActorBase::Repeat(float _MoveValue, float _DeltaTime)
{
	ReverseTime += _DeltaTime;
	if (ReverseTime < 1.0f)
	{
		GetTransform()->SetLocalPosition(
			float4::LerpClamp(
				GetTransform()->GetLocalPosition(),
				{ _MoveValue,GetTransform()->GetLocalPosition().y },
				_DeltaTime));
	}
	if (ReverseTime > 1.0f)
	{
		GetTransform()->SetLocalPosition(
			float4::LerpClamp(
				GetTransform()->GetLocalPosition(),
				{ -_MoveValue,GetTransform()->GetLocalPosition().y },
				_DeltaTime));
		if (ReverseTime > 2.0f)
		{
			ReverseTime = 0.0f;
		}
	}
}

std::shared_ptr<GameEngineSpriteRenderer> S_ActorBase::Init(
	std::shared_ptr<GameEngineSpriteRenderer> _Render,
	const std::string_view& _ImageName,
	float4 _Scale,
	float4 _Position)
{
	_Render = CreateComponent<GameEngineSpriteRenderer>();
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);

	return _Render;
}

std::shared_ptr<GameEngineSpriteRenderer> S_ActorBase::AnimationInit(
	std::shared_ptr<GameEngineSpriteRenderer> _Render,
	const std::string_view& _ImageName,
	float4 _Scale,
	float4 _Position,
	const std::string_view& _AnimationName,
	const std::string_view& _FileName,
	size_t _AnimationCount,
	float _InterTime)
{
	_Render = CreateComponent<GameEngineSpriteRenderer>();
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);
	_Render->CreateAnimation({ _AnimationName, _FileName, 0,_AnimationCount,_InterTime });
	_Render->ChangeAnimation(_AnimationName);

	/*std::string_view AnimationName = "";
	std::string_view SpriteName = "";
	size_t Start = static_cast<size_t>(-1);
	size_t End = static_cast<size_t>(-1);
	float FrameInter = 0.1f;
	bool Loop = true;
	bool ScaleToTexture = false;*/
	return _Render;

}

void S_ActorBase::AnimationImageLoad(const std::string_view& _FileName)
{
	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ThereisnogameResource");
	NewDir.Move("ThereisnogameResource");
	NewDir.Move("Animation");

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName(_FileName).GetFullPath());
}







void S_ActorBase::Down(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-400 }, _DeltaTime));
}

void S_ActorBase::Up(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,300 }, _DeltaTime));
}

void S_ActorBase::FlagDown(float _EndValue, float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-_EndValue }, _DeltaTime));
}

void S_ActorBase::FlagUp(float _PlusXvalue, float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { -1300 - _PlusXvalue,GetTransform()->GetLocalPosition().y }, _DeltaTime));
}