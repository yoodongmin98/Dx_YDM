#include "PrecompileHeader.h"
#include "MusicNote_Radio.h"

//PlatForm
//Core

//Actor
#include "MediaPicture.h"
#include "LevelStateManager.h"
#include "Fake Program Level.h"

MusicNote_Radio::MusicNote_Radio()
{
}

MusicNote_Radio::~MusicNote_Radio()
{
}

void MusicNote_Radio::Start()
{
	Init(MusicNote_Radios, "Note.png", { 100,110 }, { -245,-150,0 });
	MusicNote_RadiosCollision = CollisionInit(MusicNote_RadiosCollision, { 100,110,1 }, { -245,-150,0 });
	Font = FontCreate(Font, 20, "Æ®·¢\n04", { -245,-200,0 }, GetTransform(), 2);
}

void MusicNote_Radio::Update(float _DeltaTime)
{
	ManagedCollision(MusicNote_RadiosCollision, 1);
	if (true == ClickCheck(MusicNote_RadiosCollision))
	{
		LevelStateManager::MG->SetIsRainfalse();
		LevelStateManager::MG->SetIsWalNutfalse();
		MediaPicture::MainMediaPicture->ChangeMusicPicture(4);
		FakeProgramLevel::FP->ChangeBGM("Chap02_ElevatorMusic.wav");
	}
}

void MusicNote_Radio::Render(float _Delta)
{

};
