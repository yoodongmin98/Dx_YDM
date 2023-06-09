#include "PrecompileHeader.h"
#include "DrawerPicture.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "RightRotate.h"
#include "Decapsuleur.h"

DrawerPicture::DrawerPicture()
{
}

DrawerPicture::~DrawerPicture()
{
}
bool CreateBool = true;
void DrawerPicture::Start()
{
	DrawerOpen = Init(DrawerOpen, "Picture02b #75260.png", { 642,642 }, float4::Zero);
	DrawerClose = Init(DrawerClose, "Picture02a #75200.png", { 642,642 }, float4::Zero);
	DrawerCollision = CollisionInit(DrawerCollision, { 200,100 }, float4::Zero);
}

void DrawerPicture::Update(float _DeltaTime)
{
	if (true == ClickCheck(DrawerCollision))
	{
		DrawerOpen->On();
		DrawerClose->Death();
	}
	RenderRotateCheck(DrawerOpen);
	RenderRotateCheck(DrawerClose);
	ScreenActorCreateCheck();
}

void DrawerPicture::Render(float _Delta)
{

};

void DrawerPicture::ScreenActorCreateCheck()
{
	if (2 == RightRotate::MainRightRotate->GetHowManyClick()
		|| -2 == RightRotate::MainRightRotate->GetHowManyClick())
	{
		if (true == CreateBool&& true==DrawerClose->IsDeath())
		{
			GetLevel()->CreateActor<Decapsuleur>();
			CreateBool = false;
		}
	}
}