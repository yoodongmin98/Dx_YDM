#include "PrecompileHeader.h"
#include "StartPictures.h"

StartPictures::StartPictures()
{
}

StartPictures::~StartPictures()
{
}

void StartPictures::Start()
{
	Init(RStartPictures, "Flag_SupportLevel.png", { 209,505,1 }, { -170,650,-10 });
}

void StartPictures::Update(float _DeltaTime)
{
	Repeat(7, _DeltaTime*0.8f);
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

