#include "PrecompileHeader.h"
#include "DayTree.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>



DayTree::DayTree()
{
}

DayTree::~DayTree()
{
}

void DayTree::Start()
{
	//나중에 position 설정
	Tree_BigDay = Init(Tree_BigDay, "Tree_BigDay.png", { 597,486 }, float4::Zero);
	Tree_BigNight = Init(Tree_BigNight, "Tree_BigNight.png", { 597,486 }, float4::Zero);
	Tree_SmallDay = Init(Tree_SmallDay, "Tree_SmallDay.png", { 159,108 }, { 70,-132,0 });
	Tree_SmallNight = Init(Tree_SmallNight, "Tree_SmallNight.png", { 159,108 }, {70,-132,0});

	Tree_BigDay->Off();
	Tree_BigNight->Off();
	Tree_SmallDay->Off();
	Tree_SmallNight->On();
}

void DayTree::Update(float _DeltaTime)
{

}

void DayTree::Render(float _Delta)
{

};
