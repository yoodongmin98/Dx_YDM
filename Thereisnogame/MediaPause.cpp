#include "PrecompileHeader.h"
#include "MediaPause.h"

//PlatForm
//Core

//Actor
#include "MediaPicture.h"
#include "MediaPlay.h"
#include "Fake Program Level.h"

MediaPause* MediaPause::MainMediaPause;
MediaPause::MediaPause()
{
	MainMediaPause = this;
}

MediaPause::~MediaPause()
{
}

void MediaPause::Start()
{
	MediaPauses=Init(MediaPauses, "MediaPauseoffs.png", { 96,96 }, { 443,-23,0 });
	MediaPauseoffs = Init(MediaPauseoffs, "MediaPauseOff.png", { 96,96 }, { 443,-23,0 });
	MediaPausesCollision = CollisionInit(MediaPausesCollision, { 96,96,1 }, { 443,-23,0 });
	MediaPauses->Off();
}

void MediaPause::Update(float _DeltaTime)
{
	if (true == ClickCheck(MediaPausesCollision))
	{
		MediaPauses->On();
		MediaPauseoffs->Off();
		MediaPlay::MainMediaPlay->SetMediaPlayoff(2);
		MediaPicture::MainMediaPicture->SetPlayandPause("Pause");
	}
}

void MediaPause::Render(float _Delta)
{

};

void MediaPause::SetMediaPauseoff()
{
	MediaPauses->Off();
	MediaPauseoffs->On();
}
