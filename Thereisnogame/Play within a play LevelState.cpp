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
#include "T_TitleMetal.h"
#include "H_TitleMetal.h"
#include "E_TitleMetal.h"
#include "R_TitleMetal.h"
#include "RE_TitleMetal.h"
#include "I_TitleMetal.h"
#include "S_TitleMetal.h"
#include "N_TitleMetal.h"
#include "O_TitleMetal.h"
#include "G_TitleMetal.h"
#include "A_TitleMetal.h"
#include "M_TitleMetal.h"
#include "ME_TitleMetal.h"



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
	case Chap1LevelState::SlantBoard:
		SlantBoardStart();
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
	case Chap1LevelState::SlantBoard:
		SlantBoardEnd();
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
	case Chap1LevelState::SlantBoard:
		SlantBoardUpdate(_DeltaTime);
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
	BlockCount = 13;
}
void PlaywithinaplayLevel::DownBoardUpdate(float _DeltaTime)
{
	if (0 == BlockCount)
	{
		ChangeState(Chap1LevelState::ClearBoard);
	}
}
void PlaywithinaplayLevel::DownBoardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//모르겠으면 그냥 노가다를 하자
bool Setbool1 = true; bool Setbool2 = true; bool Setbool3 = true; bool Setbool4 = true; bool Setbool5 = true; bool Setbool6 = true; bool Setbool7 = true; 
bool Setbool8 = true; bool Setbool9 = true; bool Setbool10 = true; bool Setbool11 = true; bool Setbool12 = true; bool Setbool13 = true;
void PlaywithinaplayLevel::ClearBoardStart()
{
	ChainPtr = CreateActor<Chain>();
	ChainPtr->SetChainLiveTime(7);
}
void PlaywithinaplayLevel::ClearBoardUpdate(float _DeltaTime)
{
	std::function<void()> Functions;

	Functions = std::bind(&Board::BoardUp, BoardPtr.get());
	Functions();
	//사운드끝나는거로바꾸면 베스트
	if (ChainPtr->GetLiveTime() > 6.0f && true == Setbool1) { T_TitleMetalPtr = CreateActor<T_TitleMetal>(); T_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform()); Setbool1 = false; }
	if (ChainPtr->GetLiveTime() > 6.2f && true == Setbool2) { H_TitleMetalPtr = CreateActor<H_TitleMetal>(); H_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool2 = false;}
	if (ChainPtr->GetLiveTime() > 6.4f && true == Setbool3) { E_TitleMetalPtr = CreateActor<E_TitleMetal>(); E_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool3 = false;}
	if (ChainPtr->GetLiveTime() > 6.6f && true == Setbool4) { R_TitleMetalPtr = CreateActor<R_TitleMetal>(); R_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool4 = false;}
	if (ChainPtr->GetLiveTime() > 6.8f && true == Setbool5) { RE_TitleMetalPtr = CreateActor<RE_TitleMetal>(); RE_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool5 = false;}
	if (ChainPtr->GetLiveTime() > 7.0f && true == Setbool6) { I_TitleMetalPtr = CreateActor<I_TitleMetal>(); I_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool6 = false;}
	if (ChainPtr->GetLiveTime() > 7.2f && true == Setbool7) { S_TitleMetalPtr = CreateActor<S_TitleMetal>(); S_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool7 = false;}
	if (ChainPtr->GetLiveTime() > 7.4f && true == Setbool8) { N_TitleMetalPtr = CreateActor<N_TitleMetal>(); N_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool8 = false;}
	if (ChainPtr->GetLiveTime() > 7.6f && true == Setbool9) { O_TitleMetalPtr = CreateActor<O_TitleMetal>(); O_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool9 = false;}
	if (ChainPtr->GetLiveTime() > 7.8f && true == Setbool10) { G_TitleMetalPtr = CreateActor<G_TitleMetal>(); G_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool10 = false;}
	if (ChainPtr->GetLiveTime() > 8.0f && true == Setbool11) { A_TitleMetalPtr = CreateActor<A_TitleMetal>(); A_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool11 = false;}
	if (ChainPtr->GetLiveTime() > 8.2f && true == Setbool12) { M_TitleMetalPtr = CreateActor<M_TitleMetal>(); M_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool12 = false;}
	if (ChainPtr->GetLiveTime() > 8.4f && true == Setbool13) { ME_TitleMetalPtr = CreateActor<ME_TitleMetal>(); ME_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());Setbool13 = false;}
	
}
void PlaywithinaplayLevel::ClearBoardEnd()
{
	//chian이랑 lope부모 해제
	Lope_ChainPtr->GetTransform()->SetParent(nullptr);
	Lope_CordePtr->GetTransform()->SetParent(nullptr);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::SlantBoardStart()
{

}
void PlaywithinaplayLevel::SlantBoardUpdate(float _DeltaTime)
{
	if (true == LevelStateManager::MG->GetLopeDownStart())
	{
		Lope_ChainPtr->GetTransform()->AddLocalPosition({ 0,-1,0 });
		Lope_CordePtr->GetTransform()->AddLocalPosition({ 0,-1,0 });
	}
	//사운드가 끝나고, Metal 특정횟수 이상 건드렸을때 ChangeState


}
void PlaywithinaplayLevel::SlantBoardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::RoshamboStart()
{
	if (nullptr != ChainPtr) { ChainPtr->Death(); ChainPtr = nullptr; }
}
void PlaywithinaplayLevel::RoshamboUpdate(float _DeltaTime)
{
	//사운드가 끝나면
}
void PlaywithinaplayLevel::RoshamboEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////