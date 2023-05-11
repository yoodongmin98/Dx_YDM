#include "PrecompileHeader.h"
#include "MediaPicture.h"

//PlatForm
//Core



MediaPicture::MediaPicture()
{
}

MediaPicture::~MediaPicture()
{
}
bool MediaPictureImageLoad = true;
void MediaPicture::Start()
{
	if (true == MediaPictureImageLoad)
	{
		AnimationImageLoad("Archive");
		AnimationImageLoad("Radio");
		AnimationImageLoad("Rain");
		AnimationImageLoad("Walnut");
		MediaPictureImageLoad = false;
	}

	WalnutPicture = AnimationInit(WalnutPicture, "MediaVignetteMusic01_00.png", { 366,204 }, { 197,-65,0 }, "WalnutPicture", "Walnut", 0.5f);
	ArchivePicture = AnimationInit(ArchivePicture, "MediaVignetteMusic02_00.png", { 366,204 }, { 197,-65,0 }, "ArchivePicture", "Archive", 0.5f);
	RainPicture = AnimationInit(RainPicture, "MediaVignetteMusic03_00.png", { 366,204 }, { 197,-65,0 }, "RainPicture", "Rain", 0.5f);
	RadioPicture = AnimationInit(RadioPicture, "MediaVignetteMusic04_00.png", { 366,204 }, { 197,-65,0 }, "RadioPicture", "Radio", 0.5f);

	//조건에 따라 On off 바꾸기
	WalnutPicture->On();
	ArchivePicture->Off();
	RainPicture->Off();
	RadioPicture->Off();
}

void MediaPicture::Update(float _DeltaTime)
{
	
}

void MediaPicture::Render(float _Delta)
{

};
