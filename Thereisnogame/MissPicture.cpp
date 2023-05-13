#include "PrecompileHeader.h"
#include "MissPicture.h"

//PlatForm
//Core
//Actor



MissPicture::MissPicture()
{
}

MissPicture::~MissPicture()
{
}

void MissPicture::Start()
{
	MissFR=Init(MissFR, "PictureBoard02.png", { 642,642 }, float4::Zero);
	MissUS=Init(MissUS, "PictureBoard01.png", { 642,642 }, float4::Zero);
	MissJP=Init(MissJP, "PictureBoard03", { 642,642 }, float4::Zero);
}

void MissPicture::Update(float _DeltaTime)
{

}

void MissPicture::Render(float _Delta)
{

};
