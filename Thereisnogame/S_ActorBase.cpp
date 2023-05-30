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

std::shared_ptr<GameEngineSpriteRenderer> S_ActorBase::Init(
	std::shared_ptr<GameEngineSpriteRenderer> _Render,
	const std::string_view& _ImageName,
	float4 _Scale,
	float4 _Position)
{
	_Render = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::ScreenActor);
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition({ _Position.x,_Position.y});

	return _Render;
}

std::shared_ptr<GameEngineCollision> S_ActorBase::CollisionInit(
	std::shared_ptr<GameEngineCollision> _Collision,
	float4 _Scale,
	float4 _Position)
{
	_Collision = CreateComponent<GameEngineCollision>(ActorTypeEnum::ScreenActor);
	_Collision->GetTransform()->SetLocalScale(_Scale);
	_Collision->GetTransform()->SetLocalPosition({ _Position.x,_Position.y });

	return _Collision;
}

void S_ActorBase::Fall(std::shared_ptr<GameEngineSpriteRenderer> _Render,
	std::shared_ptr<GameEngineSpriteRenderer> _Render2,
	std::shared_ptr<GameEngineCollision> _Collision,
	float _ImageHalfScale,float _DeltaTime)
{
	float4 MoveDir = float4::Down * _DeltaTime * FallSpeed;
	
	if (_Render->GetTransform()->GetLocalPosition().y < -GameEngineWindow::GetScreenSize().half().y + _ImageHalfScale)
	{
		MoveDir = float4::Zero;
	}
	_Render->GetTransform()->AddLocalPosition(MoveDir);
	_Render2->GetTransform()->AddLocalPosition(MoveDir);
	_Collision->GetTransform()->AddLocalPosition(MoveDir);
}

void S_ActorBase::CatchCheck(std::shared_ptr<GameEngineSpriteRenderer> _Render,
	std::shared_ptr<GameEngineSpriteRenderer> _Render2,
	std::shared_ptr<GameEngineCollision> _Collision)
{
	if (_Collision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		float4 MousePos = Mouse::MainMouse->GetMousePos();
		if (false == Mouse::MainMouse->IsInteractable())
		{
			_Render->GetTransform()->SetLocalPosition(MousePos);
			_Render2->GetTransform()->SetLocalPosition({ MousePos.x - 3,MousePos.y + 3 });
			_Collision->GetTransform()->SetLocalPosition(MousePos);
		}
		_Render->Off();
		_Render2->On();
	}
	else
	{
		_Render->On();
		_Render2->Off();
	}
}
