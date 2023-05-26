#include "PrecompileHeader.h"
#include "StartPictures.h"
#include "ActorTypeEnum.h"
StartPictures::StartPictures()
{
}

StartPictures::~StartPictures()
{
}

void StartPictures::Start()
{
	RStartPictures=Init(RStartPictures, "Flag_SupportLevel.png", { 209,505,1 }, { -170,650,0 });
	ChapterPictureOff = Init(ChapterPictureOff, "Chapter01.png", { 151,100,1 }, { -170,650,0 });
	ChapterPictureOn = Init(ChapterPictureOn, "Chapter01b.png", { 151,100,1 }, { -170,450,0 });

	StartPictureCollision = CollisionInit(StartPictureCollision, { 151,100,1 }, { -170,650,0 });
}

void StartPictures::Update(float _DeltaTime)
{
	Repeat(7, _DeltaTime*0.8f);
	if (StartPictureCollision->Collision(ActorTypeEnum::Mouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ChapterPictureOff->Off();
		ChapterPictureOn->On();
	}
	else
	{
		ChapterPictureOff->On();
		ChapterPictureOn->Off();
	}
}

void StartPictures::Render(float _Delta)
{

};

void StartPictures::PictureDown(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,-400 }, _DeltaTime));
}

void StartPictures::PictureUp(float _DeltaTime)
{
	GetTransform()->SetLocalPosition(float4::LerpClamp(GetTransform()->GetLocalPosition(), { 0,300 }, _DeltaTime));
}

