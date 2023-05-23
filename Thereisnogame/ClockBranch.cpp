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
	ClockBranchs = AnimationInit(ClockBranchs, "ClockBranch00.png", { 30,40 }, {-230,80}, "shakeBranch", "Branch", 1, 0.15f);
	ClockBranchsCollision = CollisionInit(ClockBranchsCollision, { 30,40 }, { -230,80 });
	
}

void ClockBranch::Update(float _DeltaTime)
{
	ManagedCollision(ClockBranchsCollision, 1);
	if (true == ClickCheck(ClockBranchsCollision))
	{
		FallCount++;
		ClockBranchs->GetTransform()->AddLocalPosition({ 0,-5,0 });
		ClockBranchsCollision->GetTransform()->AddLocalPosition({ 0,-5,0 });
		if (5 <= FallCount&& true == ClickCheck(ClockBranchsCollision))
		{
			ColManager::MG->PlusClockValue();
		}
	}
	if (5 <= FallCount)
	{
		ClockBranchsCollision->Death();
		ClockBranchs->GetTransform()->AddLocalPosition({ 0,-1,0 });
		if (ClockBranchs->GetTransform()->GetLocalPosition().y < -500)
		{
			Death();
		}
	}
}

void ClockBranch::Render(float _Delta)
{

};
