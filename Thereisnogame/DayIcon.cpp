#include "PrecompileHeader.h"
#include "DayIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "DayPicture.h"
#include "DayTree.h"

DayIcon::DayIcon()
{
}

DayIcon::~DayIcon()
{
}

void DayIcon::Start()
{
	//�갡 DayPicture Create
	Icon_BigDay = Init(Icon_BigDay, "Picture01BigDay.png", { 90,93 }, {-340,20});
	Icon_BigNight = Init(Icon_BigNight, "Picture01BigNight.png", { 90,93 }, { -340,20 });
	Icon_SmallDay = Init(Icon_SmallDay, "Picture01SmallDay.png", { 90,93 }, { -340,20 });
	Icon_SmallNight = Init(Icon_SmallNight, "Picture01SmallNight.png", { 90,93 }, { -340,20 });

	DayIconCollision = CollisionInit(DayIconCollision, { 90,93,1 }, { -340,20 });

	Icon_BigDay->On();
	Icon_BigNight->Off();
	Icon_SmallDay->Off();
	Icon_SmallNight->Off();
}

void DayIcon::Update(float _DeltaTime)
{
	if (true == ClickCheck(DayIconCollision))
	{
		DayPicturePtr=GetLevel()->CreateActor<DayPicture>();
		DayTreePtr=GetLevel()->CreateActor<DayTree>();
	}
}

void DayIcon::Render(float _Delta)
{

};
