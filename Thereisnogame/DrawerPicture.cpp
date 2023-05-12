#include "PrecompileHeader.h"
#include "DrawerPicture.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>



DrawerPicture::DrawerPicture()
{
}

DrawerPicture::~DrawerPicture()
{
}

void DrawerPicture::Start()
{
	DrawerOpen = Init(DrawerOpen, "Picture02b #75260.png", { 642,642 }, float4::Zero);
	DrawerClose = Init(DrawerClose, "Picture02a #75200.png", { 642,642 }, float4::Zero);

	DrawerOpen->Off();
	DrawerClose->On();
	
}

void DrawerPicture::Update(float _DeltaTime)
{

}

void DrawerPicture::Render(float _Delta)
{

};
