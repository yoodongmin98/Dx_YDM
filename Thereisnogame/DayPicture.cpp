#include "PrecompileHeader.h"
#include "DayPicture.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>



DayPicture::DayPicture()
{
}

DayPicture::~DayPicture()
{
}

void DayPicture::Start()
{
	//¾ê°¡ Daytree Create
	Picture_Day = Init(Picture_Day, "Picture01Day.png", { 642,642 }, float4::Zero);
	Picture_Night = Init(Picture_Night, "Picture01Night.png", { 642,642 }, float4::Zero);

	Picture_Day->Off();
	Picture_Night->On();
}

void DayPicture::Update(float _DeltaTime)
{

}

void DayPicture::Render(float _Delta)
{

};
