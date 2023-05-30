#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//Platform
//Core

//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
#include "Chain.h"
#include "Board.h"
#include "Lope_Chain.h"
#include "Lope_Corde.h"

void PlaywithinaplayLevel::ChangeState(Chap1LevelState _State)
{
	Chap1LevelState NextState = _State;
	Chap1LevelState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case Chap1LevelState::ClickCordon:
		ClickCordonStart();
		break;
	case Chap1LevelState::CreateBoard:
		CreateBoardStart();
		break;
	case Chap1LevelState::SetBoard:
		SetBoardStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case Chap1LevelState::ClickCordon:
		ClickCordonEnd();
		break;
	case Chap1LevelState::CreateBoard:
		CreateBoardEnd();
		break;
	case Chap1LevelState::SetBoard:
		SetBoardEnd();
		break;
	default:
		break;
	}
}

void PlaywithinaplayLevel::UpdateState(float _DeltaTime)
{
	switch (StateValue)
	{
	case Chap1LevelState::ClickCordon:
		ClickCordonUpdate(_DeltaTime);
		break;
	case Chap1LevelState::CreateBoard:
		CreateBoardUpdate(_DeltaTime);
		break;
	case Chap1LevelState::SetBoard:
		SetBoardUpdate(_DeltaTime);
		break;
	default:
		break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PlaywithinaplayLevel::ClickCordonStart()
{
	AlphaCirclePtr = CreateActor<AlphaCircle>();
}
void PlaywithinaplayLevel::ClickCordonUpdate(float _DeltaTime)
{
	std::function<void()> Functions;
	Functions = std::bind(&BackCurtain::CurtainOpen, BackCurtainPtr.get());
	Functions();
	//if(Plaque두드리고 사운드가 끝나면) changeState로 바꿔야함

}
void PlaywithinaplayLevel::ClickCordonEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool BoardCreateBool = true;
void PlaywithinaplayLevel::CreateBoardStart()
{
	ChainPtr = CreateActor<Chain>();
	ChainPtr->SetChainLiveTime(6);
}
void PlaywithinaplayLevel::CreateBoardUpdate(float _DeltaTime)
{
	CreateBoardTime += _DeltaTime;
	std::function<void()> Functions;
	if (ChainPtr->GetLiveTime() < 3.0f || ChainPtr->GetLiveTime() > 5.0f && ChainPtr->GetLiveTime() < 9.0f)
	{
		Functions = std::bind(&BackCurtain::CurtainClose, BackCurtainPtr.get());
		Functions();
	}
	if (ChainPtr->GetLiveTime() > 3.0f && ChainPtr->GetLiveTime() < 5.0f || ChainPtr->GetLiveTime() > 9.0f && ChainPtr->GetLiveTime() < 15.0f)
	{
		Functions = std::bind(&BackCurtain::CurtainOpen, BackCurtainPtr.get());
		Functions();
	}
	if (ChainPtr->GetLiveTime() > 6.0f&& true==BoardCreateBool)
	{
		Lope_ChainPtr=CreateActor<Lope_Chain>();
		Lope_CordePtr=CreateActor<Lope_Corde>();
		BoardPtr=CreateActor<Board>();
		Lope_ChainPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		Lope_CordePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		BoardCreateBool = false;
	}
}
void PlaywithinaplayLevel::CreateBoardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::SetBoardStart()
{

}
void PlaywithinaplayLevel::SetBoardUpdate(float _DeltaTime)
{

}
void PlaywithinaplayLevel::SetBoardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////