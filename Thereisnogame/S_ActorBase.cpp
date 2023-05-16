#include "PrecompileHeader.h"
#include "S_ActorBase.h"
#include "ActorTypeEnum.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>


//Actor
#include "Mouse.h"


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
//얘는 떨어져야하기때문에 기본적으로 윈도우좌표계 기준으로 넣을예정
std::shared_ptr<GameEngineSpriteRenderer> S_ActorBase::Init(
	std::shared_ptr<GameEngineSpriteRenderer> _Render,
	const std::string_view& _ImageName,
	float4 _Scale,
	float4 _Position)
{
	_Render = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::ScreenActor);
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition({ _Position.x - ScreenSizeX,_Position.y + ScreenSizeY });

	return _Render;
}

//아마 안쓸듯?
//std::shared_ptr<GameEngineSpriteRenderer> S_ActorBase::AnimationInit(
//	std::shared_ptr<GameEngineSpriteRenderer> _Render,
//	const std::string_view& _ImageName,
//	float4 _Scale,
//	float4 _Position,
//	const std::string_view& _AnimationName,
//	const std::string_view& _FileName,
//	size_t _AnimationCount,
//	float _InterTime)
//{
//	_Render = CreateComponent<GameEngineSpriteRenderer>();
//	_Render->SetScaleToTexture(_ImageName);
//	_Render->GetTransform()->SetLocalScale(_Scale);
//	_Render->GetTransform()->SetLocalPosition(_Position);
//	_Render->CreateAnimation({ _AnimationName, _FileName, 0,_AnimationCount,_InterTime });
//	_Render->ChangeAnimation(_AnimationName);
//
//	return _Render;
//
//}

//void S_ActorBase::AnimationImageLoad(const std::string_view& _FileName)
//{
//	GameEngineDirectory NewDir;
//	NewDir.MoveParentToDirectory("ThereisnogameResource");
//	NewDir.Move("ThereisnogameResource");
//	NewDir.Move("Animation");
//
//	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName(_FileName).GetFullPath());
//}


std::shared_ptr<GameEngineCollision> S_ActorBase::CollisionInit(
	std::shared_ptr<GameEngineCollision> _Collision,
	float4 _Scale,
	float4 _Position)
{
	_Collision = CreateComponent<GameEngineCollision>(ActorTypeEnum::ScreenActor);
	_Collision->GetTransform()->SetLocalScale(_Scale);
	_Collision->GetTransform()->SetLocalPosition({ _Position.x - ScreenSizeX,_Position.y + ScreenSizeY });

	return _Collision;
}

void S_ActorBase::Fall(std::shared_ptr<GameEngineSpriteRenderer> _Render,float _ImageHalfScale,float _DeltaTime)
{
	float4 MoveDir = float4::Down * _DeltaTime * FallSpeed;
	
	if (_Render->GetTransform()->GetLocalPosition().y < -360.0f+ _ImageHalfScale)
	{
		MoveDir = float4::Zero;
	}
	_Render->GetTransform()->AddLocalPosition(MoveDir);
}

void S_ActorBase::CatchCheck(std::shared_ptr<GameEngineSpriteRenderer> _Render)
{
	if (GameEngineInput::IsPress("LeftMouse"))//Collision추가
	{
		float4 MousePos = Mouse::MainMouse->GetMousePos();
		_Render->GetTransform()->SetLocalPosition(MousePos);
	}
}
