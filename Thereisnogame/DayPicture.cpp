#include "PrecompileHeader.h"
#include "DayPicture.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "ColManager.h"

DayPicture::DayPicture()
{
}

DayPicture::~DayPicture()
{
}

void DayPicture::Start()
{
	if (2 == ColManager::MG->GetClockValue())
	{
		Picture_Day = Init(Picture_Day, "Picture01Day.png", { 642,642 }, float4::Zero);
	}
	else
	{
		Picture_Night = Init(Picture_Night, "Picture01Night.png", { 642,642 }, float4::Zero);
	}
}

void DayPicture::Update(float _DeltaTime)
{
	RenderRotateCheck(Picture_Day);
	RenderRotateCheck(Picture_Night);
}

void DayPicture::Render(float _Delta)
{

};
