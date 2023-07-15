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
	static bool Play58 = true;
	if (true == Play58)
	{
		RoshamboWinNarate.push_back("Chap01ShifumiWin01.wav");
		RoshamboWinNarate.push_back("Chap01ShifumiWin02.wav");
		RoshamboWinNarate.push_back("Chap01ShifumiWin03.wav");
		RoshamboWinNarate.push_back("Chap01ShifumiWin04.wav");
		RoshamboWinNarate.push_back("Chap01ShifumiWin05.wav");

		RoshamboRePlayNarate.push_back("Chap01ShifumiReplay01.wav");
		RoshamboRePlayNarate.push_back("Chap01ShifumiReplay02.wav");
		RoshamboRePlayNarate.push_back("Chap01ShifumiReplay03.wav");
		RoshamboRePlayNarate.push_back("Chap01ShifumiReplay04.wav");
		RoshamboRePlayNarate.push_back("Chap01ShifumiReplay05.wav");
		
		Play58 = false;
	}
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
	EnemyCardBool = true;
}
void PlaywithinaplayLevel::EnemyCardUpdate(float _DeltaTime)
{
	EnemyCardTime += _DeltaTime;
	std::function<void()> Functions;
	if (EnemyCardTime>1.0f)
	{
		if (true == ScotchBool)
		{
			Sound = Play(Sound, "Scotch.wav", 0.1f);
			ScotchBool = false;
		}
		Functions = std::bind(&R_Dos::Shake, R_DosPtr.get());
		Functions();
	}
	if (EnemyCardTime > 3.0f)
	{
		if (true == LevelStateManager::MG->GetIsRock())
		{
			if (true == RockBool)
			{
				Sound = Play(Sound, "CardDrop.wav", 0.1f);
				RockBool = false;
			}
			R_DosPtr.get()->Off();
			R_EnemyPaperPtr.get()->On();
		}
		if (true == LevelStateManager::MG->GetIsSissor())
		{
			if (true == ScissorBool)
			{
				Sound = Play(Sound, "CardDrop.wav", 0.1f);
				ScissorBool = false;
			}
			R_DosPtr.get()->Off();
			R_EnemyRockPtr.get()->On();
		}
		if (true == LevelStateManager::MG->GetIsPaper())
		{
			if (true == PaperBool)
			{
				Sound = Play(Sound, "CardDrop.wav", 0.1f);
				PaperBool = false;
			}
			R_DosPtr.get()->Off();
			R_EnemySissorPtr.get()->On();
		}
	}
	if (EnemyCardTime > 4.0f)
	{
		if (true == WinBool)
		{
			Sound = Play(Sound, RoshamboWinNarate[NarateValue], 0.1f);
			WinBool = false;
		}
	}

	if (EnemyCardTime > 7.0f)
	{
		if (true == ReplayBool)
		{
			Sound = Play(Sound, RoshamboRePlayNarate[NarateValue], 0.1f);
			ReplayBool = false;
		}
	}
	if (EnemyCardTime > 9.0f)
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
	EnemyCardBool = false;
	NarateValue++;
	if (NarateValue >= 4)
	{
		NarateValue = 0;
	}
	Sound = Play(Sound, "CardDrop.wav", 0.1f);
	LevelStateManager::MG->SetIsSelectCardFalse();
	LevelStateManager::MG->SetIsRockfalse();
	LevelStateManager::MG->SetIsSissorfalse();
	LevelStateManager::MG->SetIsPaperfalse();
	R_DosPtr.get()->GetRenderTransform()->SetLocalRotation(float4::Zero);
	R_DosPtr.get()->On();
	R_EnemyRockPtr.get()->Off();
	R_EnemyPaperPtr.get()->Off();
	R_EnemySissorPtr.get()->Off();
	R_RockPtr.get()->SetBool();
	R_SissorPtr.get()->SetBool();
	R_PaperPtr.get()->SetBool();

	ScotchBool = true;
	RockBool = true;
	ScissorBool = true;
	PaperBool = true;
	WinBool = true;
	ReplayBool = true;
}
void PlaywithinaplayLevel::CardDownAndOffUpdate(float _DeltaTime)
{

}
void PlaywithinaplayLevel::CardDownAndOffEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
