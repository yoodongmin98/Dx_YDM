#include "PrecompileHeader.h"
#include "MusicNote_Archive.h"

//PlatForm
//Core

//Actor
#include "MediaPicture.h"
#include "LevelStateManager.h"
#include "Fake Program Level.h"

MusicNote_Archive::MusicNote_Archive()
{
}

MusicNote_Archive::~MusicNote_Archive()
{
}

void MusicNote_Archive::Start()
{
	Init(MusicNote_Archives, "Note.png", { 100,110 }, { -245,30,0 });
	MusicNote_ArchivesCollision = CollisionInit(MusicNote_ArchivesCollision, { 100,110,1 }, { -245,30,0 });
	Font = FontCreate(Font, 20, "Ʈ��\n02", { -245,-20,0 }, GetTransform(), 2);
}

void MusicNote_Archive::Update(float _DeltaTime)
{
	ManagedCollision(MusicNote_ArchivesCollision, 1);
	if (true == ClickCheck(MusicNote_ArchivesCollision))
	{
		LevelStateManager::MG->SetIsRainfalse();
		LevelStateManager::MG->SetIsWalNutfalse();
		MediaPicture::MainMediaPicture->ChangeMusicPicture(2);
		FakeProgramLevel::FP->ChangeBGM("Chap02_MetalMusic.wav");
	}
}

void MusicNote_Archive::Render(float _Delta)
{

};
