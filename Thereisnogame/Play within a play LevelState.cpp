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
#include "T_TitleCube.h"
#include "H_TitleCube.h"
#include "E_TitleCube.h"
#include "R_TitleCube.h"
#include "RE_TitleCube.h"
#include "I_TitleCube.h"
#include "S_TitleCube.h"
#include "N_TitleCube.h"
#include "O_TitleCube.h"
#include "G_TitleCube.h"
#include "A_TitleCube.h"
#include "M_TitleCube.h"
#include "ME_TitleCube.h"
#include "Ball_TitleCube.h"
#include "Excla_TitleCube.h"
#include "Mouse.h"
#include "LevelStateManager.h"

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
	case Chap1LevelState::DownBoard:
		DownBoardStart();
		break;
	case Chap1LevelState::ClearBoard:
		ClearBoardStart();
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
	case Chap1LevelState::DownBoard:
		DownBoardEnd();
		break;
	case Chap1LevelState::ClearBoard:
		ClearBoardEnd();
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
	case Chap1LevelState::DownBoard:
		DownBoardUpdate(_DeltaTime);
		break;
	case Chap1LevelState::ClearBoard:
		ClearBoardUpdate(_DeltaTime);
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
	ChainPtr->SetChainLiveTime(7);
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
		//there is no game
		T_TitleCubePtr=CreateActor<T_TitleCube>();
		T_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		H_TitleCubePtr=CreateActor<H_TitleCube>();
		H_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		E_TitleCubePtr=CreateActor<E_TitleCube>();
		E_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		R_TitleCubePtr=CreateActor<R_TitleCube>();
		R_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		RE_TitleCubePtr=CreateActor<RE_TitleCube>();
		RE_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		I_TitleCubePtr=CreateActor<I_TitleCube>();
		I_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		S_TitleCubePtr=CreateActor<S_TitleCube>();
		S_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		N_TitleCubePtr=CreateActor<N_TitleCube>();
		N_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		O_TitleCubePtr=CreateActor<O_TitleCube>();
		O_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		G_TitleCubePtr=CreateActor<G_TitleCube>();
		G_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		A_TitleCubePtr=CreateActor<A_TitleCube>();
		A_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		M_TitleCubePtr=CreateActor<M_TitleCube>();
		M_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		ME_TitleCubePtr=CreateActor<ME_TitleCube>();
		ME_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		Excla_TitleCubePtr=CreateActor<Excla_TitleCube>();
		Excla_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		Ball_TitleCubePtr=CreateActor<Ball_TitleCube>();
		Ball_TitleCubePtr->GetTransform()->SetParent(BoardPtr->GetTransform());

		Lope_ChainPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		Lope_CordePtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		BoardCreateBool = false;
	}
}
void PlaywithinaplayLevel::CreateBoardEnd()
{
	if (true == ChainPtr->IsDeath())
	{
		ChainPtr = nullptr;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::DownBoardStart()
{
	
}
void PlaywithinaplayLevel::DownBoardUpdate(float _DeltaTime)
{
	
}
void PlaywithinaplayLevel::DownBoardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::ClearBoardStart()
{

}
void PlaywithinaplayLevel::ClearBoardUpdate(float _DeltaTime)
{

}
void PlaywithinaplayLevel::ClearBoardEnd()
{

}