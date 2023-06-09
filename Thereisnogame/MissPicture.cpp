#include "PrecompileHeader.h"
#include "MissPicture.h"

//PlatForm
//Core
//Actor

MissPicture* MissPicture::MP;

MissPicture::MissPicture()
{
	MP = this;
}

MissPicture::~MissPicture()
{
}

void MissPicture::Start()
{
	MissFR=Init(MissFR, "PictureBoard02.png", { 642,642 }, float4::Zero);
	MissUS=Init(MissUS, "PictureBoard01.png", { 642,642 }, float4::Zero);
	MissJP=Init(MissJP, "PictureBoard03 #75211.png", { 642,642 }, float4::Zero);

	PictureSelectVector.push_back(MissFR);
	PictureSelectVector.push_back(MissUS);
	PictureSelectVector.push_back(MissJP);

	WhatisPicture = ChangeMissPictureRender(MissFR);
}

void MissPicture::Update(float _DeltaTime)
{
	RenderRotateCheck(MissJP);
	RenderRotateCheck(MissUS);
	RenderRotateCheck(MissFR);
	ChangeMissPictureRender(WhatisPicture);
}

void MissPicture::Render(float _Delta)
{

};

std::shared_ptr<GameEngineSpriteRenderer> MissPicture::ChangeMissPictureRender(std::shared_ptr<class GameEngineSpriteRenderer> _PictureRender)
{
	if (nullptr == _PictureRender)
	{
		MsgAssert("nullptr상태인 MissPictureRender로 바꾸려 했습니다.");
	}
	for (size_t i = 0; i <= 2; ++i)
	{
		PictureSelectVector[i]->Off();
		if (PictureSelectVector[i] == _PictureRender)
		{
			PictureSelectVector[i]->On();
		}
	}
	return _PictureRender;
}

void MissPicture::ChangeMissPicture(int _Value)
{
	int SetPictureValue = _Value;
	switch (SetPictureValue)
	{
	case 1:
		WhatisPicture = ChangeMissPictureRender(MissUS);
		break;
	case 2:
		WhatisPicture = ChangeMissPictureRender(MissFR);
		break;
	case 3:
		WhatisPicture = ChangeMissPictureRender(MissJP);
		break;
	default:
		MsgAssert("MissPicture에 이상한 숫자 넣지마라 인간아");
		break;
	}
}