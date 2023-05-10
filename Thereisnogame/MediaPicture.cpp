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

void MediaPicture::Start()
{
	//아마 애니메이션으로 바꿀듯
	Init(MediaPictures, "MediaVignetteMusic01_00.png", { 366,204 }, { 197,-65,0 });
}

void MediaPicture::Update(float _DeltaTime)
{

}

void MediaPicture::Render(float _Delta)
{

};
