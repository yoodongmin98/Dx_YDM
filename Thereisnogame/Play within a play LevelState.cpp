#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//Platform
//Core

//Actor
#include "AlphaCircle.h"
#include "BackCurtain.h"
#include "Chain.h"

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

void PlaywithinaplayLevel::CreateBoardStart()
{
	ChainPtr = CreateActor<Chain>();
	ChainPtr->SetChainLiveTime(7);
}
void PlaywithinaplayLevel::CreateBoardUpdate(float _DeltaTime)
{
	CreateBoardTime += _DeltaTime;
	std::function<void()> Functions;
	Functions = std::bind(&BackCurtain::CurtainClose, BackCurtainPtr.get());
	Functions();
}
void PlaywithinaplayLevel::CreateBoardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////