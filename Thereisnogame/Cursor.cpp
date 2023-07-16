#include "PrecompileHeader.h"
#include "Cursor.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core



//Actor
#include "Mouse.h"
#include "LevelStateManager.h"
#include "Speaker.h"

Cursor::Cursor()
{
}

Cursor::~Cursor()
{
}

void Cursor::Start()
{
	if (false == LevelStateManager::MG->GetIsPopBalloon())
	{
		StartPosition = { 700,50,0 };
	}
	else if (true == LevelStateManager::MG->GetIsPopBalloon())
	{
		Play(Sound, "BalloonPop.wav", 0.2f);
		StartPosition = Mouse::MainMouse->GetMousePos();
	}
	else
	{
		return;
	}
	Cursors = Init(Cursors, "MouseCursorObj.png", { 52,79 }, StartPosition);
	Cursor_Overlap = Init(Cursor_Overlap, "MouseCursorObj_Overlap.png", { 77,103 }, { StartPosition.x - 3,StartPosition.y + 3 });


	CursorsCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Cursor);
	CursorsCollision->GetTransform()->SetLocalScale({ 52,79 });
	CursorsCollision->GetTransform()->SetLocalPosition(StartPosition);

	Starts = StartPosition;
	Ends = Speaker::TM->GetSpeakerPosition();


}
bool CursorCatchBools = false;
bool CursorSoundTimeBool = false;
void Cursor::Update(float _DeltaTime)
{
	if (true == CursorSoundTimeBool)
	{
		SoundTime += _DeltaTime;
	}
	if (true == LevelStateManager::MG->GetIsPopBalloon())
	{
		Fall(Cursors, Cursor_Overlap, CursorsCollision,40.0f, _DeltaTime);
		CursorSoundTimeBool = true;
	}
	CursorCatchBools=CatchCheck(Cursors, Cursor_Overlap, CursorsCollision);
	if (false == LevelStateManager::MG->GetIsPopBalloon())
	{
		CursorMoveCheck(_DeltaTime);
	}
	CollisionDeathCheck();
	if (4.0f < SoundTime)
	{
		SoundAndText(_DeltaTime);
	}
}

void Cursor::Render(float _Delta)
{

};


void Cursor::CollisionDeathCheck()
{
	if (CursorsCollision->Collision(ActorTypeEnum::Speaker, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		LevelStateManager::MG->SetIsClickSpeakerFalse();
		Death();
	}
}

void Cursor::CursorMoveCheck(float _DeltaTime)
{
	MoveTime += _DeltaTime;
	if (true == LevelStateManager::MG->GetIsClickSpeaker()
		&&false== CursorCatchBools)
	{
		Positions = float4::LerpClamp(Starts, Ends, MoveTime);
		Cursors->GetTransform()->SetLocalPosition(Positions);
		Cursor_Overlap->GetTransform()->SetLocalPosition(Positions);
		CursorsCollision->GetTransform()->SetLocalPosition(Positions);
	}
}

void Cursor::SoundAndText(float _DeltaTime)
{
	TextTime += _DeltaTime;
	if (TextTime > 1.0f)
	{
		static bool Play71 = true;
		if (true == Play71)
		{
			Sound = Play(Sound, "Chap01BoardDead01.wav", 0.1f);
			Play71 = false;
		}
		Font = NFontCreate(Font, "장난치는 것도 아니고!", GetTransform(), 2.5f);
	}

	if (TextTime > 4.0f)
	{
		static bool Play72 = true;
		if (true == Play72)
		{
			Sound = Play(Sound, "Chap01BoardDead02.wav", 0.1f);
			Play72 = false;
		}
		Font2 = NFontCreate(Font2, "해놓은 꼴을 좀 봐요. 새로 만든 제목인데!", GetTransform(), 3.0f);
	}

	if (TextTime > 7.5f)
	{
		static bool Play73 = true;
		if (true == Play73)
		{
			Sound = Play(Sound, "Chap01BoardDead03.wav", 0.1f);
			Play73 = false;
		}
		Font3 = NFontCreate(Font3, "뭘 부수고 싶다면, 배틀 오브 듀티나 하시든가.", GetTransform(), 3.0f);
	}
}