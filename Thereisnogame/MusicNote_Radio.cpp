#include "PrecompileHeader.h"
#include "MusicNote_Radio.h"

//PlatForm
//Core

//Actor
#include "MediaPicture.h"


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
}

void MusicNote_Radio::Update(float _DeltaTime)
{
	ManagedCollision(MusicNote_RadiosCollision, 1);
	if (true == ClickCheck(MusicNote_RadiosCollision))
	{
		MediaPicture::MainMediaPicture->ChangeMusicPicture(4);
	}
}

void MusicNote_Radio::Render(float _Delta)
{

};
