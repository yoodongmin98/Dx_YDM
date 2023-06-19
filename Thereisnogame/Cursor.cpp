#include "PrecompileHeader.h"
#include "Cursor.h"
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
	float4 Position = { 500,0,0 };
	Cursors = Init(Cursors, "MouseCursorObj.png", { 52,79 }, Position);

	CursorsCollision = CollisionInit(CursorsCollision, { 52,79 }, Position);
	Starts = Position;
	Ends = Speaker::TM->GetSpeakerPosition();
}

void Cursor::Update(float _DeltaTime)
{
	MoveTime += _DeltaTime;
	if (true == LevelStateManager::MG->GetIsClickSpeaker())
	{
		Positions=float4::LerpClamp(Starts, Ends, MoveTime);
		Cursors->GetTransform()->SetLocalPosition(Positions);
		CursorsCollision->GetTransform()->SetLocalPosition(Positions);
	}
}

void Cursor::Render(float _Delta)
{

};
