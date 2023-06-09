#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//Platform
#include <GameEnginePlatform/GameEngineInput.h>
//Core

//Actor
#include "R_Sissor.h"
#include "R_Paper.h"
#include "R_Rock.h"
#include "R_EnemyPaper.h"
#include "R_EnemyRock.h"
#include "R_EnemySissor.h"
#include "R_Dos.h"
#include "LevelStateManager.h"


void PlaywithinaplayLevel::RSBChangeState(RoshamboState _State)
{
	RoshamboState NextState = _State;
	RoshamboState PrevState = RSBStateValue;

	RSBStateValue = NextState;

	switch (NextState)
	{
	case RoshamboState::SelectCard:
		SelectCardStart();
		break;
	case RoshamboState::EnemyCard:
		EnemyCardStart();
		break;
	case RoshamboState::CardDownAndOff:
		CardDownAndOffStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case RoshamboState::SelectCard:
		SelectCardEnd();
		break;
	case RoshamboState::EnemyCard:
		EnemyCardEnd();
		break;
	case RoshamboState::CardDownAndOff:
		CardDownAndOffEnd();
		break;
	default:
		break;
	}
}

void PlaywithinaplayLevel::RSBUpdateState(float _DeltaTime)
{
	switch (RSBStateValue)
	{
	case RoshamboState::SelectCard:
		SelectCardUpdate(_DeltaTime);
		break;
	case RoshamboState::EnemyCard:
		EnemyCardUpdate(_DeltaTime);
		break;
	case RoshamboState::CardDownAndOff:
		CardDownAndOffUpdate(_DeltaTime);
		break;
	default:
		break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::SelectCardStart()
{

}
void PlaywithinaplayLevel::SelectCardUpdate(float _DeltaTime)
{
	//Collision작용을 위한 빈 State
}
void PlaywithinaplayLevel::SelectCardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::EnemyCardStart()
{
	
}
void PlaywithinaplayLevel::EnemyCardUpdate(float _DeltaTime)
{
	EnemyCardTime += _DeltaTime;
	std::function<void()> Functions;
	if (EnemyCardTime>1.0f)
	{
		Functions = std::bind(&R_Dos::Shake, R_DosPtr.get());
		Functions();
	}
	if (EnemyCardTime > 3.0f)
	{
		if (true == LevelStateManager::MG->GetIsRock())
		{
			R_DosPtr.get()->Off();
			R_EnemyPaperPtr.get()->On();
		}
		if (true == LevelStateManager::MG->GetIsSissor())
		{
			R_DosPtr.get()->Off();
			R_EnemyRockPtr.get()->On();
		}
		if (true == LevelStateManager::MG->GetIsPaper())
		{
			R_DosPtr.get()->Off();
			R_EnemySissorPtr.get()->On();
		}
	}
	if (EnemyCardTime > 6.0f)
	{
		RSBChangeState(RoshamboState::CardDownAndOff);
	}
}
void PlaywithinaplayLevel::EnemyCardEnd()
{
	EnemyCardTime = 0.0f;
	R_DosPtr.get()->SetCountClear();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::CardDownAndOffStart()
{
	LevelStateManager::MG->SetIsRockfalse();
	LevelStateManager::MG->SetIsSissorfalse();
	LevelStateManager::MG->SetIsPaperfalse();
	R_DosPtr.get()->On();
	R_EnemyRockPtr.get()->Off();
	R_EnemyPaperPtr.get()->Off();
	R_EnemySissorPtr.get()->Off();
}
void PlaywithinaplayLevel::CardDownAndOffUpdate(float _DeltaTime)
{

}
void PlaywithinaplayLevel::CardDownAndOffEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
