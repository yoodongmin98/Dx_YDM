#include "PrecompileHeader.h"
#include "MusicNote_Walnut.h"

//PlatForm
//Core


//Actor
#include "MediaPicture.h"
#include "LevelStateManager.h"
#include "Fake Program Level.h"
MusicNote_Walnut::MusicNote_Walnut()
{
}

MusicNote_Walnut::~MusicNote_Walnut()
{
}

void MusicNote_Walnut::Start()
{
	Init(MusicNote_Walnuts, "Note.png", { 100,110 }, { -400,30,0 });
	MusicNote_WalnutsCollision = CollisionInit(MusicNote_WalnutsCollision, { 100,110,1 }, { -400,30,0 });
	Font = FontCreate(Font, 20, "Ʈ��\n01", { -400,-20,0 }, GetTransform(), 2);
}

void MusicNote_Walnut::Update(float _DeltaTime)
{
	ManagedCollision(MusicNote_WalnutsCollision, 1);
	if (true == ClickCheck(MusicNote_WalnutsCollision))
	{
		LevelStateManager::MG->SetIsRainfalse();
		LevelStateManager::MG->SetIsWalNuttrue();
		MediaPicture::MainMediaPicture->ChangeMusicPicture(1);
		FakeProgramLevel::FP->ChangeBGM("Chap02_NutCrackerMusic.wav");
	}
}

void MusicNote_Walnut::Render(float _Delta)
{

};
