#include "PrecompileHeader.h"
#include "DayTree.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>


//Actor
#include "DayPicture.h"
#include "RightRotate.h"
#include "ColManager.h"
#include "Mouse.h"

DayTree::DayTree()
{
}

DayTree::~DayTree()
{
}

void DayTree::Start()
{

	Tree_BigDay = Init(Tree_BigDay, "Tree_BigDay.png", { 597,486 }, { 0,50,0 });
	Tree_SmallDay = Init(Tree_SmallDay, "Tree_SmallDay.png", { 159,108 }, { 70,-132,0 });
	Tree_BigNight = Init(Tree_BigNight, "Tree_BigNight.png", { 597,486 }, { 0,50,0 });
	Tree_SmallNight = Init(Tree_SmallNight, "Tree_SmallNight.png", { 159,108 }, { 70,-132,0 });

	Tree_BigCollision = CollisionInit(Tree_BigCollision, { 597,486 }, { 0,50,0 });
	Tree_SmallCollision = CollisionInit(Tree_SmallCollision, { 159,108 }, { 70,-132,0 });
	if (true==ColManager::MG->GetIsBigTree())
	{
		Tree_BigCollision->On();		
		Tree_SmallCollision->Off();
	}
	else
	{
		Tree_BigCollision->Off();
		Tree_SmallCollision->On();
	}

	TreeVector.push_back(Tree_BigDay);
	TreeVector.push_back(Tree_SmallDay);
	TreeVector.push_back(Tree_BigNight);
	TreeVector.push_back(Tree_SmallNight);

	WhatisTree = ChangeTreeRender(Tree_SmallNight);
}

void DayTree::Update(float _DeltaTime)
{
	GetTheNutFunc();
	if (Tree_SmallCollision->Collision(ActorTypeEnum::Cup_Full, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&&true==Mouse::MainMouse->IsInteractable())
	{
		ColManager::MG->SetIsBigTreeTrue();
	}
	WhatisTreeRender();
	RotatePositionSet(Tree_BigDay,{ 0,50,0 },1);
	RotatePositionSet(Tree_BigNight, { 0,50,0 },1);
	RotatePositionSet(Tree_SmallDay,{ 70,-132,0 },0);
	RotatePositionSet(Tree_SmallNight, { 70,-132,0 },0);
}

void DayTree::Render(float _Delta)
{

};




void DayTree::RotatePositionSet(std::shared_ptr<GameEngineSpriteRenderer> _Render, float4 _Pos,int _Value)
{
	if (nullptr != _Render)
	{
		int ClickValue = RightRotate::MainRightRotate->GetHowManyClick();
		switch (ClickValue)
		{
		case 0:
		case 4:
			_Render->GetTransform()->SetLocalRotation(float4::Zero);
			_Render->GetTransform()->SetLocalPosition(_Pos);
			break;
		case 1:
		case -3:
			_Render->GetTransform()->SetLocalRotation({ 0,0,-90 });
			if (_Value != 1)
			{
				_Render->GetTransform()->SetLocalPosition(_Pos+float4{-200,60,0});
			}
			else
			{
				_Render->GetTransform()->SetLocalPosition(_Pos + float4{ 50,-50,0 });
			}
			break;
		case 2:
		case -2:
			_Render->GetTransform()->SetLocalRotation({ 0,0,-180 });
			if (_Value != 1)
			{
				_Render->GetTransform()->SetLocalPosition(_Pos + float4{ -135,265,0 });
			}
			else
			{
				_Render->GetTransform()->SetLocalPosition(_Pos + float4{ 0,-100,0 });
			}
			break;
		case -1:
		case 3:
			_Render->GetTransform()->SetLocalRotation({ 0,0,-270 });
			if (_Value != 1)
			{
				_Render->GetTransform()->SetLocalPosition(_Pos + float4{ 60,200,0 });
			}
			else
			{
				_Render->GetTransform()->SetLocalPosition(_Pos + float4{ -50,-50,0 });
			}
		default:
			break;
		}
	}
}

std::shared_ptr<GameEngineSpriteRenderer> DayTree::ChangeTreeRender(std::shared_ptr<class GameEngineSpriteRenderer> _PictureRender)
{
	if (nullptr == _PictureRender)
	{
		MsgAssert("nullptr상태인 TreeRender로 바꾸려 했습니다.");
	}
	for (size_t i = 0; i <= 3; ++i)
	{
		TreeVector[i]->Off();
		if (TreeVector[i] == _PictureRender)
		{
			TreeVector[i]->On();
		}
	}
	return _PictureRender;
}

void DayTree::WhatisTreeRender()
{
	if (2 == ColManager::MG->GetClockValue())
	{
		if (true == ColManager::MG->GetIsBigTree())
		{
			WhatisTree = ChangeTreeRender(Tree_BigDay);
		}
		else
		{
			WhatisTree = ChangeTreeRender(Tree_SmallDay);
		}
	}
	else
	{
		if (true == ColManager::MG->GetIsBigTree())
		{
			WhatisTree = ChangeTreeRender(Tree_BigNight);
		}
		else
		{
			WhatisTree = ChangeTreeRender(Tree_SmallNight);
		}
	}
}

void DayTree::GetTheNutFunc()
{
	if (true == ClickCheck(Tree_BigCollision)&&2==ColManager::MG->GetClockValue())
	{
		GetTheNut++;
	}
	if (GetTheNut >= 5)
	{
		//
	}
}