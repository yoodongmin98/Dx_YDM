#include "PrecompileHeader.h"
#include "MusicNote_Rain.h"

//PlatForm
//Core

//Actor
#include "MediaPicture.h"
#include "LevelStateManager.h"
#include "Fake Program Level.h"

MusicNote_Rain::MusicNote_Rain()
{
}

MusicNote_Rain::~MusicNote_Rain()
{
}

void MusicNote_Rain::Start()
{
	Init(MusicNote_Rains, "Note.png", { 100,110 }, { -400,-150,0 });
	MusicNote_RainsCollision = CollisionInit(MusicNote_RainsCollision, { 100,110,1 }, { -400,-150,0 });
	Font = FontCreate(Font, 20, "Æ®·¢\n03", { -400,-200,0 }, GetTransform(), 2);
}

void MusicNote_Rain::Update(float _DeltaTime)
{
	ManagedCollision(MusicNote_RainsCollision, 1);
	if (true == ClickCheck(MusicNote_RainsCollision))
	{
		LevelStateManager::MG->SetIsRaintrue();
		LevelStateManager::MG->SetIsWalNutfalse();
		MediaPicture::MainMediaPicture->ChangeMusicPicture(3);
		Sound=FakeProgramLevel::FP->ChangeBGM("RainLoop.wav");
		Sound.SetLoop(-1);
	}
}

void MusicNote_Rain::Render(float _Delta)
{

};
