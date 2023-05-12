#include "PrecompileHeader.h"
#include "DrawerIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>



DrawerIcon::DrawerIcon()
{
}

DrawerIcon::~DrawerIcon()
{
}

void DrawerIcon::Start()
{
	//¾ê°¡ DrawerPicture Create
	Init(DrawerIcons, "Picture02a.png", { 90,93 }, { -180,20 });
}

void DrawerIcon::Update(float _DeltaTime)
{

}

void DrawerIcon::Render(float _Delta)
{

};
