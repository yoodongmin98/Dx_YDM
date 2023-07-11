#include "PrecompileHeader.h"
#include "MediaPlay.h"

//PlatForm
//Core

//Actor
#include "MediaPicture.h"
#include "MediaPause.h"
#include "Fake Program Level.h"


MediaPlay* MediaPlay::MainMediaPlay;
MediaPlay::MediaPlay()
{
	MainMediaPlay = this;
}

MediaPlay::~MediaPlay()
{
}

void MediaPlay::Start()
{
	MediaPlays=Init(MediaPlays, "MediaPlayOn.png", { 96,96 }, { -49,-23,0 });
	MediaPlayoffs = Init(MediaPlayoffs, "MediaPlayOff.png", { 96,96 }, { -49,-23,0 });
	MediaPlaysCollision = CollisionInit(MediaPlaysCollision, { 96,96,1 }, { -49,-23,0 });
	MediaPlayoffs->Off();
}

void MediaPlay::Update(float _DeltaTime)
{
	if (true == ClickCheck(MediaPlaysCollision))
	{
		MediaPlays->On();
		MediaPlayoffs->Off();
		MediaPause::MainMediaPause->SetMediaPauseoff();
		MediaPicture::MainMediaPicture->SetPlayandPause("Play");
	}
}

void MediaPlay::Render(float _Delta)
{

};

void MediaPlay::SetMediaPlayoff(int _Value)
{
	if (1 == _Value)
	{
		MediaPlays->On();
		MediaPlayoffs->Off();
	}
	else if (2 == _Value)
	{
		MediaPlays->Off();
		MediaPlayoffs->On();
	}
	else
	{
		MsgAssert("MediaPlay에 이상한 값 넣지마라")
	}
}
