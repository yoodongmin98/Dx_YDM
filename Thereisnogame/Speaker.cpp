#include "PrecompileHeader.h"
#include "Speaker.h"
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
	SpeakersCollision = CollisionInit(SpeakersCollision, { 78,70 }, Position);
}


void Speaker::Update(float _DeltaTime)
{
	Times += _DeltaTime;

	if (true==ClickCheck(SpeakersCollision)
		&&false==LevelStateManager::MG->GetIsClickSpeaker())
	{
		LevelStateManager::MG->SetIsClickSpeakerTrue();
		GetLevel()->CreateActor<Cursor>();
		Speakers->Off();
		SpeakersOff->On();
	}

	float4 MoveDir = float4::Down * _DeltaTime * 500.0f;
	if (Speakers->GetTransform()->GetLocalPosition().y < -GameEngineWindow::GetScreenSize().half().y + 35.0f)
	{
		MoveDir = float4::Zero;
	}
	Speakers->GetTransform()->AddLocalPosition(MoveDir * Times);
	SpeakersOff->GetTransform()->AddLocalPosition(MoveDir * Times);
	SpeakersCollision->GetTransform()->AddLocalPosition(MoveDir * Times);
}

void Speaker::Render(float _Delta)
{

};
