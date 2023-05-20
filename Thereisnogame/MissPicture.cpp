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
}

void MissPicture::Update(float _DeltaTime)
{
	RenderRotateCheck(MissJP);
	RenderRotateCheck(MissUS);
	RenderRotateCheck(MissFR);
}

void MissPicture::Render(float _Delta)
{

};
