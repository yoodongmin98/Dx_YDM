#include "PrecompileHeader.h"
#include "ClockBranch.h"

//PlatForm
//Core


#include "ColManager.h"

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
		ClockBranchs->GetTransform()->AddLocalPosition({ 0,-5,0 });
		if (ClockBranchs->GetTransform()->GetLocalPosition().y < -500)
		{
			Death();
		}
	}
	if (true == ClickCheck(ClockBranchsCollision))
	{
		FallCount++;
		ClockBranchs->GetTransform()->AddLocalPosition({ 0,-5,0 });
		ClockBranchsCollision->GetTransform()->AddLocalPosition({ 0,-5,0 });
		if (5 == FallCount&& true == ClickCheck(ClockBranchsCollision))
		{
			ColManager::MG->PlusClockValue();
			int asda=ColManager::MG->GetClockValue();
		}
	}
}

void ClockBranch::Render(float _Delta)
{

};
