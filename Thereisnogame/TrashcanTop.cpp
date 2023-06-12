#include "PrecompileHeader.h"
#include "TrashcanTop.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core

//Actor
#include "Mouse.h"
#include "LevelStateManager.h"
TrashcanTop* TrashcanTop::Top;
TrashcanTop::TrashcanTop()
{
	Top = this;
}

TrashcanTop::~TrashcanTop()
{
}
bool TrashcanImageLoad = true;
bool TrashCanFall = false;
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
	ManagedCollision(TrashcanTopsCollision, 0);
	if (true == ClickCheck(TrashcanTopsCollision))
	{
		TrashcanTops->ChangeAnimation("TrashcanReapeat");
	}
	TrashCanFallandDeathCheck();
}

void TrashcanTop::Render(float _Delta)
{

};


void TrashcanTop::TrashCanFallandDeathCheck()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (TrashcanTopsCollision->Collision(ActorTypeEnum::Decapsuleur, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&& true == Mouse::MainMouse->IsInteractable())
	{
		LevelStateManager::MG->SetTrashCanOpen();
		TrashCanFall = true;
	}
	if (true == TrashCanFall)
	{
		TrashcanTopsCollision->Off();
		TrashcanTops->GetTransform()->AddLocalPosition({ 0,-5*Times,0 });
	}
	if (TrashcanTops->GetTransform()->GetLocalPosition().y < -500)
	{
		Death();
	}
}