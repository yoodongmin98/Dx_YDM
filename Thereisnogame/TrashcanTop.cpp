#include "PrecompileHeader.h"
#include "TrashcanTop.h"

//PlatForm
//Core


TrashcanTop* TrashcanTop::Top;
TrashcanTop::TrashcanTop()
{
	Top = this;
}

TrashcanTop::~TrashcanTop()
{
}
bool TrashcanImageLoad = true;
void TrashcanTop::Start()
{
	if (true == TrashcanImageLoad)
	{
		AnimationImageLoad("TrashcanTop");
		TrashcanImageLoad = false;
	}
	TrashcanTops = AnimationInit(TrashcanTops, "IconRubbishTop00.png",{ 73, 46 }, { 419,-165,0 }, "TrashcanReapeat", "TrashcanTop", 4, 0.1f, false);
	TrashcanTopsCollision = CollisionInit(TrashcanTopsCollision, { 73, 46 }, { 419,-165,0 });
}

void TrashcanTop::Update(float _DeltaTime)
{
	if (true == ClickCheck(TrashcanTopsCollision))
	{
		TrashcanTops->ChangeAnimation("TrashcanReapeat");
	}
}

void TrashcanTop::Render(float _Delta)
{

};
