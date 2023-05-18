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

	WalnutPicture = AnimationInit(WalnutPicture, "MediaVignetteMusic01_00.png", { 366,204 }, { 197,-65,0 }, "WalnutPicture", "Walnut",1, 0.5f);
	ArchivePicture = AnimationInit(ArchivePicture, "MediaVignetteMusic02_00.png", { 366,204 }, { 197,-65,0 }, "ArchivePicture", "Archive",1, 0.5f);
	RainPicture = AnimationInit(RainPicture, "MediaVignetteMusic03_00.png", { 366,204 }, { 197,-65,0 }, "RainPicture", "Rain",2, 0.1f);
	RadioPicture = AnimationInit(RadioPicture, "MediaVignetteMusic04_00.png", { 366,204 }, { 197,-65,0 }, "RadioPicture", "Radio",2, 0.5f);

	//조건에 따라 On off 바꾸기
	PictureSelectVector.push_back(WalnutPicture);
	PictureSelectVector.push_back(ArchivePicture);
	PictureSelectVector.push_back(RainPicture);
	PictureSelectVector.push_back(RadioPicture);

	WhatisPicture = ChangeMusicRender(RadioPicture);
}

void MediaPicture::Update(float _DeltaTime)
{
	ChangeMusicRender(WhatisPicture);
}

void MediaPicture::Render(float _Delta)
{

};

std::shared_ptr<GameEngineSpriteRenderer> MediaPicture::ChangeMusicRender(std::shared_ptr<class GameEngineSpriteRenderer> _PictureRender)
{
	if (nullptr == _PictureRender)
	{
		MsgAssert("nullptr상태인 MusicRender로 바꾸려 했습니다.");
	}
	for (size_t i = 0; i <= 3; ++i)
	{
		PictureSelectVector[i]->Off();
		if (PictureSelectVector[i] == _PictureRender)
		{
			PictureSelectVector[i]->On();
		}
	}
	return _PictureRender;
}

void MediaPicture::ChangeMusicPicture(int _Value)
{
	/*switch (_Value)
	{
	case 1:
		break;
	}*/
}