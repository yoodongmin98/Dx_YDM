#include "PrecompileHeader.h"
#include "SkiteIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "SkiteProfil.h"

SkiteIcon::SkiteIcon()
{
}

SkiteIcon::~SkiteIcon()
{
}

void SkiteIcon::Start()
{
	SkiteIcons=Init(SkiteIcons, "Skiteface.png", { 63,63 }, { 270,0,0 });
	SkiteIconsCollision = CollisionInit(SkiteIconsCollision, { 63,63,1 }, { 270,0,0 });
}

void SkiteIcon::Update(float _DeltaTime)
{
	ManagedCollision(SkiteIconsCollision, 1);
	if (true == ClickCheck(SkiteIconsCollision))
	{
		SkiteProfilPtr = GetLevel()->CreateActor<SkiteProfil>();
	}
	if (true == IsDeath())
	{
		//ㅋㅋ이게되네
		SkiteProfilPtr.get()->Death();
	}
}

void SkiteIcon::Render(float _Delta)
{

};
