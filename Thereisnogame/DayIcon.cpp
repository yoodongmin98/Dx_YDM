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
#include "ColManager.h"

DayIcon::DayIcon()
{
}

DayIcon::~DayIcon()
{
}

void DayIcon::Start()
{
	//¾ê°¡ DayPicture Create
	Icon_BigDay = Init(Icon_BigDay, "Picture01BigDay.png", { 90,93 }, {-340,20});
	Icon_BigNight = Init(Icon_BigNight, "Picture01BigNight.png", { 90,93 }, { -340,20 });
	Icon_SmallDay = Init(Icon_SmallDay, "Picture01SmallDay.png", { 90,93 }, { -340,20 });
	Icon_SmallNight = Init(Icon_SmallNight, "Picture01SmallNight.png", { 90,93 }, { -340,20 });

	DayIconCollision = CollisionInit(DayIconCollision, { 90,93,1 }, { -340,20 });

	Icon_BigDay->Off();
	Icon_BigNight->Off();
	Icon_SmallDay->Off();
	Icon_SmallNight->On();
}

void DayIcon::Update(float _DeltaTime)
{
	ManagedCollision(DayIconCollision, 1);
	if (true == ClickCheck(DayIconCollision))
	{
		ColManager::MG->PlusCollisionValue();
		DayPicturePtr=GetLevel()->CreateActor<DayPicture>();
		DayTreePtr=GetLevel()->CreateActor<DayTree>();
		LeftRotatePtr=GetLevel()->CreateActor<LeftRotate>();
		RightRotatePtr=GetLevel()->CreateActor<RightRotate>();
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

void DayIcon::BoxCroixDeathCheck()
{
	if (true == BoxCroix_DayPicturePtr->IsDeath())
	{
		DayPicturePtr.get()->Death();
		DayTreePtr.get()->Death();
		LeftRotatePtr.get()->Death();
		RightRotatePtr.get()->Death();
	}
}