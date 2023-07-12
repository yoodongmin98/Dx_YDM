#include "PrecompileHeader.h"
#include "SkiteIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "SkiteProfil.h"
#include "LevelStateManager.h"
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
	Font = FontCreate(Font, 30, "³ª ¾Æ´Ô", { 360,20,0 }, GetTransform(), 2);
}

void SkiteIcon::Update(float _DeltaTime)
{
	ManagedCollision(SkiteIconsCollision, 1);
	if (true == ClickCheck(SkiteIconsCollision))
	{
		if (true == CreateBool)
		{
			Play(Sound, "OpenWindow.wav", 0.1f);
			SkiteProfilPtr = GetLevel()->CreateActor<SkiteProfil>();
			CreateBool = false;
		}
	}
	if (true == IsDeath()&&nullptr!= SkiteProfilPtr)
	{
		SkiteProfilPtr.get()->Death();
		CreateBool = true;
	}
}

void SkiteIcon::Render(float _Delta)
{

};
