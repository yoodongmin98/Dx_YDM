#include "PrecompileHeader.h"
#include "Gigaprivate.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>

//Actor
#include "LevelStateManager.h"
#include "Private18.h"
#include "BoxCroix_PR_18.h"
#include "PrivatePanel_18.h"


Gigaprivate::Gigaprivate()
{
}

Gigaprivate::~Gigaprivate()
{
}

void Gigaprivate::Start()
{
	Init(Gigaprivates, "Folder.png", { 96,87 }, { -200,20 });
	GigaprivatesCollision = CollisionInit(GigaprivatesCollision, { 96,87,1 }, { -200,20 });

	Font = FontCreate(Font, 25, "기가 개인용", { -200,-40 }, GetTransform(), 2);
	Font1 = FontCreate(Font1, 25, "진실03", { -60,-40 }, GetTransform(), 2);
	Font2 = FontCreate(Font2, 25, "울트라 개인용", { -210,120 }, GetTransform(), 2);
}

void Gigaprivate::Update(float _DeltaTime)
{
	ManagedCollision(GigaprivatesCollision, 3);
	if (true == ClickCheck(GigaprivatesCollision))
	{
		Play(Sound, "OpenWindow.wav", 0.1f);
		LevelStateManager::MG->PlusCollisionValue();
		PrivatePanel_18Ptr = GetLevel()->CreateActor<PrivatePanel_18>();
		BoxCroix_PR_18Ptr = GetLevel()->CreateActor<BoxCroix_PR_18>();
		Private18Ptr = GetLevel()->CreateActor<Private18>();
	}
	if (nullptr != BoxCroix_PR_18Ptr)
	{
		BoxCroixDeathCheck();
	}
}

void Gigaprivate::Render(float _Delta)
{

};

void Gigaprivate::BoxCroixDeathCheck()
{
	if (true == BoxCroix_PR_18Ptr->IsDeath())
	{
		PrivatePanel_18Ptr.get()->Death();
		Private18Ptr.get()->Death();
	}
}