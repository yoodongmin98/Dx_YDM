#include "PrecompileHeader.h"
#include "DayIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "DayPicture.h"
#include "DayTree.h"
#include "BoxCroix_DayPicture.h"
#include "LeftRotate.h"
#include "RightRotate.h"
#include "LevelStateManager.h"
#include "PurpleBox.h"

DayIcon::DayIcon()
{
}

DayIcon::~DayIcon()
{
}

void DayIcon::Start()
{
	Icon_BigDay = Init(Icon_BigDay, "Picture01BigDay.png", { 90,93 }, {-340,20});
	Icon_BigNight = Init(Icon_BigNight, "Picture01BigNight.png", { 90,93 }, { -340,20 });
	Icon_SmallDay = Init(Icon_SmallDay, "Picture01SmallDay.png", { 90,93 }, { -340,20 });
	Icon_SmallNight = Init(Icon_SmallNight, "Picture01SmallNight.png", { 90,93 }, { -340,20 });

	DayIconCollision = CollisionInit(DayIconCollision, { 90,93,1 }, { -340,20 });

	DayIconVector.push_back(Icon_BigDay);
	DayIconVector.push_back(Icon_BigNight);
	DayIconVector.push_back(Icon_SmallDay);
	DayIconVector.push_back(Icon_SmallNight);

	WhatisIcon = ChangeDayIconRender(Icon_SmallNight);
	Font = FontCreate(Font, 25, "이미지\n01", { -340,-40 }, GetTransform(), 2);
}

void DayIcon::Update(float _DeltaTime)
{
	ManagedCollision(DayIconCollision, 1);
	WhatisIconRender();
	if (true == ClickCheck(DayIconCollision))
	{
		LevelStateManager::MG->PlusCollisionValue();
		if (2 == LevelStateManager::MG->GetClockValue())
		{
			Sound = Play(Sound, "AmbianceDay.wav", 0.1f);
			Sound.SetLoop(-1);
		}
		else
		{
			Sound = Play(Sound, "AmbianceNight.wav", 0.1f);
			Sound.SetLoop(-1);
		}
		DayPicturePtr=GetLevel()->CreateActor<DayPicture>();
		DayTreePtr=GetLevel()->CreateActor<DayTree>();
		LeftRotatePtr=GetLevel()->CreateActor<LeftRotate>();
		RightRotatePtr=GetLevel()->CreateActor<RightRotate>();
		PurpleBoxptr = GetLevel()->CreateActor<PurpleBox>();
		BoxCroix_DayPicturePtr = GetLevel()->CreateActor<BoxCroix_DayPicture>();
	}
	if (nullptr != BoxCroix_DayPicturePtr)
	{
		BoxCroixDeathCheck();
	}
}

void DayIcon::Render(float _Delta)
{

};




//----------------------------------------------------------------------------------------------------------------------------

void DayIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_DayPicturePtr->IsDeath())
	{
		Sound.Stop();
		DayPicturePtr.get()->Death();
		DayTreePtr.get()->Death();
		LeftRotatePtr.get()->Death();
		RightRotatePtr.get()->Death();
		PurpleBoxptr.get()->Death();
	}
}

std::shared_ptr<GameEngineSpriteRenderer> DayIcon::ChangeDayIconRender(std::shared_ptr<class GameEngineSpriteRenderer> _PictureRender)
{
	if (nullptr == _PictureRender)
	{
		MsgAssert("nullptr상태인 DayIconRender로 바꾸려 했습니다.");
	}
	for (size_t i = 0; i <= 3; ++i)
	{
		DayIconVector[i]->Off();
		if (DayIconVector[i] == _PictureRender)
		{
			DayIconVector[i]->On();
		}
	}
	return _PictureRender;
}

void DayIcon::WhatisIconRender()
{
	if (2 == LevelStateManager::MG->GetClockValue())
	{
		if (true == LevelStateManager::MG->GetIsBigTree())
		{
			WhatisIcon = ChangeDayIconRender(Icon_BigDay);
		}
		else
		{
			WhatisIcon = ChangeDayIconRender(Icon_SmallDay);
		}
	}
	else
	{
		if (true == LevelStateManager::MG->GetIsBigTree())
		{
			WhatisIcon = ChangeDayIconRender(Icon_BigNight);
		}
		else
		{
			WhatisIcon = ChangeDayIconRender(Icon_SmallNight);
		}
	}
}