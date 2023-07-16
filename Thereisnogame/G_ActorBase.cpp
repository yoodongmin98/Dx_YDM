 #include "PrecompileHeader.h"
#include "G_ActorBase.h"
#include "ActorTypeEnum.h"
#include "Mouse.h"
#include "G_RigidBody.h"
//Base
#include <GameEngineBase/GameEngineString.h>
#include <GameEngineBase/GameEngineMath.h>
//PlatForm
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEngineTime.h>
//Core
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineFontRenderer.h>


//StaticActor
#include "RightRotate.h"
#include "LevelStateManager.h"
#include "Play within a play Level.h"

G_ActorBase::G_ActorBase()
	:pRigidBody(nullptr)
{
	CreateRigidBody();
}

G_ActorBase::~G_ActorBase()
{
	//LeakªË¡¶
	if (nullptr != pRigidBody)
	{
		delete pRigidBody;
		pRigidBody = nullptr;
	}
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
		GetTransform()->SetLocalPosition(
			float4::LerpClamp(
			GetTransform()->GetLocalPosition(),
			{ _MoveValue,GetTransform()->GetLocalPosition().y},
			_DeltaTime));
	}
	if (ReverseTime > 1.0f)
	{
		GetTransform()->SetLocalPosition(
			float4::LerpClamp(
			GetTransform()->GetLocalPosition(),
			{-_MoveValue,GetTransform()->GetLocalPosition().y },
			_DeltaTime));
		if (ReverseTime > 2.0f)
		{
			ReverseTime = 0.0f;
		}
	}
}

std::shared_ptr<GameEngineSpriteRenderer> G_ActorBase::Init(
	std::shared_ptr<GameEngineSpriteRenderer> _Render,
	const std::string_view& _ImageName,
	float4 _Scale,
	float4 _Position)
{
	_Render = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::BackActor);
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);

	return _Render;
}

std::shared_ptr<GameEngineSpriteRenderer> G_ActorBase::NullCheckInit(
	std::shared_ptr<GameEngineSpriteRenderer> _Render,
	const std::string_view& _ImageName,
	float4 _Scale,
	float4 _Position)
{
	if (nullptr == _Render)
	{
		_Render = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::BackActor);
	}
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);

	return _Render;
}

std::shared_ptr<GameEngineSpriteRenderer> G_ActorBase::AnimationInit(
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
		_Render = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::BackActor);
	}
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);
	_Render->CreateAnimation({ _AnimationName, _FileName, 0,_AnimationCount,_InterTime,_Loop});
	_Render->ChangeAnimation(_AnimationName);
	return _Render;
}

std::shared_ptr<GameEngineSpriteRenderer> G_ActorBase::NoChangeAnimationInit(
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
		_Render = CreateComponent<GameEngineSpriteRenderer>(ActorTypeEnum::BackActor);
	}
	_Render->SetScaleToTexture(_ImageName);
	_Render->GetTransform()->SetLocalScale(_Scale);
	_Render->GetTransform()->SetLocalPosition(_Position);
	_Render->CreateAnimation({ _AnimationName, _FileName, 0,_AnimationCount,_InterTime,_Loop });
	return _Render;
}

std::shared_ptr<GameEngineCollision> G_ActorBase::CollisionInit(
	std::shared_ptr<GameEngineCollision> _Collision,
	float4 _Scale,
	float4 _Position)
{
	_Collision = CreateComponent<GameEngineCollision>(ActorTypeEnum::BackActor);
	_Collision->GetTransform()->SetLocalScale(_Scale);
	_Collision->GetTransform()->SetLocalPosition({ _Position.x,_Position.y });

	return _Collision;
}

std::shared_ptr<GameEngineCollision> G_ActorBase::BlockCollisionInit(
	std::shared_ptr<GameEngineCollision> _Collision,
	float4 _Scale,
	float4 _Position)
{
	_Collision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Block);
	_Collision->GetTransform()->SetLocalScale(_Scale);
	_Collision->GetTransform()->SetLocalPosition({ _Position.x,_Position.y });

	return _Collision;
}

std::shared_ptr<GameEngineCollision> G_ActorBase::BallCollisionInit(
	std::shared_ptr<GameEngineCollision> _Collision,
	float4 _Scale,
	float4 _Position)
{
	_Collision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Ball);
	_Collision->GetTransform()->SetLocalScale(_Scale);
	_Collision->GetTransform()->SetLocalPosition({ _Position.x,_Position.y });

	return _Collision;
}

void G_ActorBase::AnimationImageLoad(const std::string_view& _FileName)
{
	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ThereisnogameResource");
	NewDir.Move("ThereisnogameResource");
	NewDir.Move("Animation");

	GameEngineSprite::LoadFolder(NewDir.GetPlusFileName(_FileName).GetFullPath());
}

bool G_ActorBase::ClickCheck(std::shared_ptr<GameEngineCollision> _Collision)
{
	if (_Collision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& GameEngineInput::IsDown("LeftMouse"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void G_ActorBase::ManagedCollision(std::shared_ptr<GameEngineCollision> _Collision,int Value)
{
	int CollisionManageValue = LevelStateManager::MG->GetCollisionValue();
	if (Value == CollisionManageValue)
	{
		_Collision->On();
	}
	else
	{
		_Collision->Off();
	}
}

void G_ActorBase::RenderRotateCheck(std::shared_ptr<GameEngineSpriteRenderer> _Render)
{
	if (nullptr != _Render)
	{
		int ClickValue = RightRotate::MainRightRotate->GetHowManyClick();
		switch (ClickValue)
		{
		case 0:
		case 4:
			_Render->GetTransform()->SetLocalRotation(float4::Zero);
			break;
		case 1:
		case -3:
			_Render->GetTransform()->SetLocalRotation({ 0,0,-90 });
			break;
		case 2:
		case -2:
			_Render->GetTransform()->SetLocalRotation({ 0,0,-180 });
			break;
		case -1:
		case 3:
			_Render->GetTransform()->SetLocalRotation({ 0,0,-270 });
		default:
			break;
		}
	}
}

void G_ActorBase::CreateRigidBody()
{
	pRigidBody = new G_RigidBody();
	pRigidBody->Parents = this;
}

void G_ActorBase::CubeMoveDeathCheck(std::shared_ptr<GameEngineCollision> _Collision)
{
	float Times=GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if ((_Collision->Collision(ActorTypeEnum::Ball, ColType::AABBBOX2D, ColType::AABBBOX2D)))
	{
		BallCheckEvent();
		Sound = Play(Sound, "BallBreakLetter.wav", 0.1f);
	}
	if (true==_Collision->IsDeath())
	{
		GetTransform()->AddLocalPosition(float4::Down * 2* Times);
		if (GetTransform()->GetLocalPosition().y < -500.0f)
		{
			PlaywithinaplayLevel::LM->MinusBlockCount();
			Death();
		}
	}
}

void G_ActorBase::InfinityShape(float _DeltaTime)
{
	Progress += _DeltaTime * 1.5f;
	float4 Pos = GetTransform()->GetLocalPosition();
	Pos.x = cosf(Progress) * 2.0f;
	Pos.y = sinf(Progress * 2.0f) * 3.0f;
	GetTransform()->SetLocalPosition(Pos);
}

void G_ActorBase::RoShamboStateCheck(std::shared_ptr<GameEngineCollision> _Collision)
{
	if (false == LevelStateManager::MG->GetIsSelectCard()
		&& true== LevelStateManager::MG->GetIsSetCard())
	{
		_Collision->On();
	}
	else
	{
		_Collision->Off();
	}
}

void G_ActorBase::RightFallRigid(float _RightValue,float _DownValue,bool _globalvariable,float _DeltaTime)
{
	G_RigidBody* Rigids = GetRigidBody();
	Rigids->SetFrictionCoeff(2);
	if (_DeltaTime < 0.1f && true == _globalvariable)
	{
		Rigids->AddForce(float4::Right * _RightValue);
	}
	if (_DeltaTime > 0.1f)
	{
		_globalvariable = false;
		Rigids->AddForce(float4::Down * _DownValue);
	}
	Rigids->RigidBodyUpdate();
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

GameEngineSoundPlayer G_ActorBase::Play(GameEngineSoundPlayer _ControlSoundName, const std::string_view& _MusicName, float _Volume)
{
	_ControlSoundName = GameEngineSound::Play(_MusicName);
	_ControlSoundName.SetVolume(_Volume);
	_ControlSoundName.SetLoop(0);

	return _ControlSoundName;
}

void G_ActorBase::Pause(GameEngineSoundPlayer _ControlSoundName)
{
	_ControlSoundName.SetPause(true);
}


std::shared_ptr<GameEngineFontRenderer> G_ActorBase::FontCreate(std::shared_ptr<GameEngineFontRenderer> _FontRender,
	float _Scale, const std::string_view _Text, float4 _Position,
	GameEngineTransform* _Transform,
	int _Index)
{
	_FontRender = CreateComponent<GameEngineFontRenderer>();
	_FontRender->GetTransform()->SetParent(_Transform);
	_FontRender->SetFont(Font);
	_FontRender->SetFontFlag(FW1_CENTER);
	_FontRender->SetScale(_Scale);
	_FontRender->SetColor(float4::White);
	_FontRender->SetText(_Text);
	if (1 == _Index)
	{
		_FontRender->GetTransform()->SetLocalPosition(_Position);
	}
	else
	{
		_FontRender->GetTransform()->SetWorldPosition(_Position);
	}
	return _FontRender;
}

std::shared_ptr<GameEngineFontRenderer> G_ActorBase::NFontCreate(std::shared_ptr<GameEngineFontRenderer> _FontRender,
	const std::string_view _Text,
	GameEngineTransform* _Transform,
	float _Time)
{
	if (nullptr == _FontRender)
	{
		_FontRender = CreateComponent<GameEngineFontRenderer>(ActorTypeEnum::Font);
		_FontRender->GetTransform()->SetParent(_Transform);
		_FontRender->SetFont(Font);
		_FontRender->SetFontFlag(FW1_CENTER);
		_FontRender->SetScale(30);
		_FontRender->SetColor(float4::White);
		_FontRender->SetText(_Text);
	}
	float4 Pos = GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition();
	_FontRender->GetTransform()->SetWorldPosition(float4{ 0,330,0 } + Pos);

	if (_FontRender->GetLiveTime() > _Time)
	{
		_FontRender->Death();
	}
	return _FontRender;
}