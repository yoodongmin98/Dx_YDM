#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//Platform
#include <GameEnginePlatform/GameEngineInput.h>
//Core

//Actor



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


void SelectCardStart()
{

}
void SelectCardUpdate(float _DeltaTime)
{

}
void SelectCardEnd()
{

}