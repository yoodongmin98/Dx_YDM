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
void Cursor::Update(float _DeltaTime)
{
	if (true == LevelStateManager::MG->GetIsPopBalloon())
	{
		Fall(Cursors, Cursor_Overlap, CursorsCollision,40.0f, _DeltaTime);
	}
	CursorCatchBools=CatchCheck(Cursors, Cursor_Overlap, CursorsCollision);
	if (false == LevelStateManager::MG->GetIsPopBalloon())
	{
		CursorMoveCheck(_DeltaTime);
	}
	CollisionDeathCheck();
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