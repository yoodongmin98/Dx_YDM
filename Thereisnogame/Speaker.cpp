#include "PrecompileHeader.h"
#include "Speaker.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>



//Actor
#include "Mouse.h"
#include "LevelStateManager.h"
#include "TitleMetal.h"
#include "Cursor.h"

Speaker* Speaker::TM;
Speaker::Speaker()
{
	TM = this;
}

Speaker::~Speaker()
{
}

void Speaker::Start()
{
	float4 Position = { -300,400 };
	Speakers = Init(Speakers, "SpeekerIcon_On.png", { 78,70 }, Position);
	SpeakersOff = Init(SpeakersOff, "SpeakerIcon_Off.png", { 82,75 }, Position);
	SpeakersOff->Off();
	
	SpeakersCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Speaker);
	SpeakersCollision->GetTransform()->SetLocalScale({ 78,70 });
	SpeakersCollision->GetTransform()->SetLocalPosition(Position);
}


bool SpeakerFallTrue = false;
void Speaker::Update(float _DeltaTime)
{
	ClickOnOffCheck(_DeltaTime);
	if (false == SpeakerFallTrue)
	{
		SpeakerFall(_DeltaTime);
	}
}

void Speaker::Render(float _Delta)
{

};
void Speaker::SpeakerFall(float _DeltaTime)
{
	float4 MoveDir = float4::Down * _DeltaTime * 500.0f;
	if (Speakers->GetTransform()->GetLocalPosition().y < -GameEngineWindow::GetScreenSize().half().y + 35.0f)
	{
		MoveDir = float4::Zero;
		SpeakerFallTrue = true;
	}
	Speakers->GetTransform()->AddLocalPosition(MoveDir * Times);
	SpeakersOff->GetTransform()->AddLocalPosition(MoveDir * Times);
	SpeakersCollision->GetTransform()->AddLocalPosition(MoveDir * Times);
}

void Speaker::ClickOnOffCheck(float _DeltaTime)
{
	Times += _DeltaTime;
	if (false==LevelStateManager::MG->GetIsClickSpeaker())
	{		
		if (true == BreathBool)
		{
			Sound.Stop();
			Sound = Play(Sound, "Breath.wav", 0.1f);
			BreathBool = false;
		}
		Speakers->On();
		SpeakersOff->Off();
	}

	if (true == ClickCheck(SpeakersCollision)
		&& false == LevelStateManager::MG->GetIsClickSpeaker())
	{
		Sound = Play(Sound, "Mmm01.wav", 0.1f);
		LevelStateManager::MG->SetIsClickSpeakerTrue();
		BreathBool = true;
		GetLevel()->CreateActor<Cursor>();
		Speakers->Off();
		SpeakersOff->On();
	}
}