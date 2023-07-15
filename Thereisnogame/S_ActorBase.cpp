#include "PrecompileHeader.h"
#include "S_ActorBase.h"
#include "ActorTypeEnum.h"

//Base
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "Mouse.h"
#include "LevelStateManager.h"


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


std::shared_ptr<GameEngineSpriteRenderer> S_ActorBase::SAnimationInit(
	std::shared_ptr<GameEngineSpriteRenderer> _Render,
	const std::string_view& _ImageName,
	float4 _Scale,
	float4 _Position,
	const std::string_view& _AnimationName,
	const std::string_view& _FileName,
	size_t _AnimationCount,
	float _InterTime,
	bool _Loop)
{
	if (nullptr == _Render)
	{
		_Render = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::ScreenActor);
	}
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);
	_Render->CreateAnimation({ _AnimationName, _FileName, 0,_AnimationCount,_InterTime,_Loop });

	return _Render;

}

void S_ActorBase::SAnimationImageLoad(const std::string_view& _FileName)
{
	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ThereisnogameResource");
	NewDir.Move("ThereisnogameResource");
	NewDir.Move("Animation");

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName(_FileName).GetFullPath());
}

void S_ActorBase::Fall(std::shared_ptr<GameEngineSpriteRenderer> _Render,
	std::shared_ptr<GameEngineSpriteRenderer> _Render2,
	std::shared_ptr<GameEngineCollision> _Collision,
	float _ImageHalfScale,float _DeltaTime)
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (true == Mouse::MainMouse->IsInteractable())
	{
		MoveDir = float4::Down * _DeltaTime * FallSpeed;
	}
	
	if (_Render->GetTransform()->GetLocalPosition().y < -GameEngineWindow::GetScreenSize().half().y + _ImageHalfScale)
	{
		MoveDir = float4::Zero;
	}
	_Render->GetTransform()->AddLocalPosition(MoveDir* Times);
	_Render2->GetTransform()->AddLocalPosition(MoveDir * Times);
	_Collision->GetTransform()->AddLocalPosition(MoveDir * Times);
}

bool S_ActorBase::CatchCheck(std::shared_ptr<GameEngineSpriteRenderer> _Render,
	std::shared_ptr<GameEngineSpriteRenderer> _Render2,
	std::shared_ptr<GameEngineCollision> _Collision)
{
	// 이 조건문 때문에 Actor를잡고 빠르게 움직이면 놓쳐버림 얘 없으면 잘 됨.
	if (_Collision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		float4 MousePos = Mouse::MainMouse->GetMousePos();
		if (false == Mouse::MainMouse->IsInteractable())
		{
			_Render->GetTransform()->SetLocalPosition(MousePos);
			_Render2->GetTransform()->SetLocalPosition({ MousePos.x - 3,MousePos.y + 3 });
			_Collision->GetTransform()->SetLocalPosition(MousePos);
			return true;
		}
		_Render->Off();
		_Render2->On();
	}
	else
	{
		_Render->On();
		_Render2->Off();
		return false;
	}
}

void S_ActorBase::Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
	_ControlSoundName.SetLoop(0);

	
}

void S_ActorBase::Pause(GameEngineSoundPlayer _ControlSoundName)
{
	_ControlSoundName.SetPause(true);
}