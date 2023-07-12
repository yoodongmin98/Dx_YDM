#include "PrecompileHeader.h"
#include "MediaPicture.h"
#include "ActorTypeEnum.h"
//PlatForm
#include <GameEngineBase/GameEngineString.h>
//Core

//Actor
#include "MediaPlay.h"
#include "MediaPause.h"
#include "Fake Program Level.h"

MediaPicture* MediaPicture::MainMediaPicture;

MediaPicture::MediaPicture()
{
	MainMediaPicture = this;
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

	WalnutPicture = AnimationInit(WalnutPicture, "MediaVignetteMusic01_00.png", { 366,204 }, { 197,-65,0 }, "WalnutPicture", "Walnut",1, 0.5f,true);
	ArchivePicture = AnimationInit(ArchivePicture, "MediaVignetteMusic02_00.png", { 366,204 }, { 197,-65,0 }, "ArchivePicture", "Archive",1, 0.4f, true);
	RainPicture = AnimationInit(RainPicture, "MediaVignetteMusic03_00.png", { 366,204 }, { 197,-65,0 }, "RainPicture", "Rain",2, 0.1f, true);
	RadioPicture = AnimationInit(RadioPicture, "MediaVignetteMusic04_00.png", { 366,204 }, { 197,-65,0 }, "RadioPicture", "Radio",2, 0.2f, true);

	Font1 = FontCreate(Font1, 25, "ȣ�α�� ����\n����������Ű", { 200,-190,0 }, GetTransform(), 2);
	Font2 = FontCreate(Font2, 25, "�Ӹ��� ����\n������ ��ī�̺�", { 200,-190,0 }, GetTransform(), 2);
	Font3 = FontCreate(Font3, 25, "����\n�ڿ��� �Ҹ�", { 200,-190,0 }, GetTransform(), 2);
	Font4 = FontCreate(Font4, 25, "���������� ���\n13��5���ִ�", { 200,-190,0 }, GetTransform(), 2);
	
	
	PictureCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Picture);
	PictureCollision->GetTransform()->SetLocalScale({ 366,204 });
	PictureCollision->GetTransform()->SetLocalPosition({ 197,-65,0 });


	PictureSelectVector.push_back(WalnutPicture);
	PictureSelectVector.push_back(ArchivePicture);
	PictureSelectVector.push_back(RainPicture);
	PictureSelectVector.push_back(RadioPicture);

	FontSelectVector.push_back(Font1);
	FontSelectVector.push_back(Font2);
	FontSelectVector.push_back(Font3);
	FontSelectVector.push_back(Font4);

	WhatisPicture = ChangeMusicRender(WalnutPicture);
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
		MsgAssert("nullptr������ MusicRender�� �ٲٷ� �߽��ϴ�.");
	}
	for (size_t i = 0; i <= 3; ++i)
	{
		FontSelectVector[i]->Off();
		PictureSelectVector[i]->Off();
		if (PictureSelectVector[i] == _PictureRender)
		{
			FontSelectVector[i]->On();
			PictureSelectVector[i]->On();
		}
	}
	return _PictureRender;
}

void MediaPicture::ChangeMusicPicture(int _Value)
{
	int SetPictureValue = _Value;
	WhatisPicture->SetAnimPauseOff();
	MediaPlay::MainMediaPlay->SetMediaPlayoff(1);
	MediaPause::MainMediaPause->SetMediaPauseoff();
	switch (SetPictureValue)
	{
	case 1:
		WhatisPicture = ChangeMusicRender(WalnutPicture);
		break;
	case 2:
		WhatisPicture = ChangeMusicRender(ArchivePicture);
		break;
	case 3:
		WhatisPicture = ChangeMusicRender(RainPicture);
		break;
	case 4:
		WhatisPicture = ChangeMusicRender(RadioPicture);
		break;
	default:
		MsgAssert("MusicPicture�� �̻��� ���� �������� �ΰ���");
		break;
	}
}

void MediaPicture::SetPlayandPause(const std::string_view& _PlayandPause)
{
	std::string UpperName=GameEngineString::ToUpper(_PlayandPause);
	if (UpperName == "PLAY")
	{
		WhatisPicture->SetAnimPauseOff();
	}
	else if (UpperName == "PAUSE")
	{
		WhatisPicture->SetAnimPauseOn();
	}
	else
	{
		MsgAssert("MediaPlayer�� ���� ���� Play�Ǵ�Pause�� �ƴմϴ�");
	}
}
