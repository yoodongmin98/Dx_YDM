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
	DrawerCollision = CollisionInit(DrawerCollision, { 200,100 }, float4::Zero);
	

	DrawerOpen->Off();
	DrawerClose->On();
	
}

void DrawerPicture::Update(float _DeltaTime)
{
	if (true == ClickCheck(DrawerCollision))
	{
		DrawerOpen->On();
		DrawerClose->Off();
	}
	RenderRotateCheck(DrawerOpen);
	RenderRotateCheck(DrawerClose);
	//if RotateCheck값이 2라면 Create ScreenActor(병따개?)
}

void DrawerPicture::Render(float _Delta)
{

};
