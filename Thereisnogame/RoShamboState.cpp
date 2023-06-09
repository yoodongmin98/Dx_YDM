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
	//얘는 나중에
	/*std::function<void()> Functions;
	Functions = std::bind(&R_Dos::Shake, R_DosPtr.get());
	Functions();*/
}
void PlaywithinaplayLevel::EnemyCardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::CardDownAndOffStart()
{

}
void PlaywithinaplayLevel::CardDownAndOffUpdate(float _DeltaTime)
{

}
void PlaywithinaplayLevel::CardDownAndOffEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
