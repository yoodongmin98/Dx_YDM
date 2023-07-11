#include "PrecompileHeader.h"
#include "ClockBranch.h"

//PlatForm
//Core


#include "LevelStateManager.h"

ClockBranch::ClockBranch()
{
}

ClockBranch::~ClockBranch()
{
}
bool Branchbool = true;
void ClockBranch::Start()
{
	if (true == Branchbool)
	{
		AnimationImageLoad("Branch");
		Branchbool = false;
	}
	ClockBranchs = AnimationInit(ClockBranchs, "ClockBranch00.png", { 30,40 }, {-230,80}, "shakeBranch", "Branch", 3, 0.15f, true);
	ClockBranchsCollision = CollisionInit(ClockBranchsCollision, { 30,40 }, { -230,80 });
	
}

void ClockBranch::Update(float _DeltaTime)
{
	ManagedCollision(ClockBranchsCollision, 1);
	if (5 <= FallCount)
	{
		ClockBranchsCollision->Death();
		ClockBranchs->GetTransform()->AddLocalPosition({ 0,-5*_DeltaTime*100.0f,0 });
		if (ClockBranchs->GetTransform()->GetLocalPosition().y < -500)
		{
			Death();
		}
	}
	if (true == ClickCheck(ClockBranchsCollision))
	{
		Play(Sound, "Drag.wav", 0.1f);
		FallCount++;
		ClockBranchs->GetTransform()->AddLocalPosition({ 0,-5*_DeltaTime * 100.0f,0 });
		ClockBranchsCollision->GetTransform()->AddLocalPosition({ 0,-5*_DeltaTime * 100.0f,0 });
		if (5 == FallCount&& true == ClickCheck(ClockBranchsCollision))
		{
			Play(Sound, "HaloSun.wav", 0.1f);
			LevelStateManager::MG->PlusClockValue();
			int asda=LevelStateManager::MG->GetClockValue();
		}
	}
}

void ClockBranch::Render(float _Delta)
{

};
