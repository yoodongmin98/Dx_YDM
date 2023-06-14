#include "PrecompileHeader.h"
#include "Play within a play Level.h"

//Base
//Platform
#include <GameEnginePlatform/GameEngineInput.h>
//Core

//Actor
//나는 Actor의 노예야
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
#include "R_Sissor.h"
#include "R_Paper.h"
#include "R_Rock.h"
#include "R_EnemyPaper.h"
#include "R_EnemyRock.h"
#include "R_EnemySissor.h"
#include "R_Dos.h"
#include "Cordon.h"
#include "TransparencyActor.h"
#include "Binary0.h"
#include "Binary1.h"
#include "BalloonSecure.h"



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
	case Chap1LevelState::Roshambo:
		RoshamboStart();
		break;
	case Chap1LevelState::TiltBoard:
		TiltBoardStart();
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
	case Chap1LevelState::Roshambo:
		RoshamboEnd();
		break;
	case Chap1LevelState::TiltBoard:
		TiltBoardEnd();
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
	case Chap1LevelState::Roshambo:
		RoshamboUpdate(_DeltaTime);
		break;
	case Chap1LevelState::TiltBoard:
		TiltBoardUpdate(_DeltaTime);
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
		if (DebugIntValue == 0) //Debug
		{
			Functions = std::bind(&BackCurtain::CurtainClose, BackCurtainPtr.get());
			Functions();
		}
	}
	if (ChainPtr->GetLiveTime() > 3.0f && ChainPtr->GetLiveTime() < 5.0f || ChainPtr->GetLiveTime() > 9.0f && ChainPtr->GetLiveTime() < 15.0f)
	{
		if (DebugIntValue == 0) //Debug
		{
			Functions = std::bind(&BackCurtain::CurtainOpen, BackCurtainPtr.get());
			Functions();
		}
	}
	if (ChainPtr->GetLiveTime() > 6.0f&& true==BoardCreateBool)
	{
		Lope_ChainPtr=CreateActor<Lope_Chain>();
		Lope_CordePtr=CreateActor<Lope_Corde>();
		BoardPtr=CreateActor<Board>();
		BalloonSecurePtr = CreateActor<BalloonSecure>();
		BalloonSecurePtr->GetTransform()->SetParent(BoardPtr->GetBoardRender());
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
		BackCurtainPtr.get()->Death();
		BackCurtainPtr = nullptr;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::DownBoardStart()
{
	//Debug------------------------------------------
	if (nullptr == BoardPtr)
	{
		Lope_ChainPtr = CreateActor<Lope_Chain>();
		Lope_CordePtr = CreateActor<Lope_Corde>();
		BoardPtr = CreateActor<Board>();
	}
	//-----------------------------------------------
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
	//Debug------------------------------------------
	if (nullptr != BackCurtainPtr)
	{
		BackCurtainPtr.get()->Death();
		BackCurtainPtr = nullptr;
	//-----------------------------------------------
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//모르겠으면 그냥 노가다를 하자
bool Setbool1 = true; bool Setbool2 = true; bool Setbool3 = true; bool Setbool4 = true; bool Setbool5 = true; bool Setbool6 = true; bool Setbool7 = true; 
bool Setbool8 = true; bool Setbool9 = true; bool Setbool10 = true; bool Setbool11 = true; bool Setbool12 = true; bool Setbool13 = true;
void PlaywithinaplayLevel::ClearBoardStart()
{
	//Debug------------------------------------------
	if (nullptr != ChainPtr)
	{
		ChainPtr.get()->Death();
		ChainPtr = nullptr;
	}
	//-----------------------------------------------
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
	//chain이랑 lope부모 해제
	Lope_ChainPtr->GetTransform()->SetParent(nullptr);
	Lope_CordePtr->GetTransform()->SetParent(nullptr);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PlaywithinaplayLevel::SlantBoardStart()
{
	//Debug------------------------------------------
	if (nullptr == T_TitleMetalPtr)
	{
		T_TitleMetalPtr = CreateActor<T_TitleMetal>(); T_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		H_TitleMetalPtr = CreateActor<H_TitleMetal>(); H_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		E_TitleMetalPtr = CreateActor<E_TitleMetal>(); E_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		R_TitleMetalPtr = CreateActor<R_TitleMetal>(); R_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		RE_TitleMetalPtr = CreateActor<RE_TitleMetal>(); RE_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		I_TitleMetalPtr = CreateActor<I_TitleMetal>(); I_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		S_TitleMetalPtr = CreateActor<S_TitleMetal>(); S_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		N_TitleMetalPtr = CreateActor<N_TitleMetal>(); N_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		O_TitleMetalPtr = CreateActor<O_TitleMetal>(); O_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		G_TitleMetalPtr = CreateActor<G_TitleMetal>(); G_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		A_TitleMetalPtr = CreateActor<A_TitleMetal>(); A_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		M_TitleMetalPtr = CreateActor<M_TitleMetal>(); M_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
		ME_TitleMetalPtr = CreateActor<ME_TitleMetal>(); ME_TitleMetalPtr->GetTransform()->SetParent(BoardPtr->GetTransform());
	}
	//-----------------------------------------------
}
void PlaywithinaplayLevel::SlantBoardUpdate(float _DeltaTime)
{
	if (true == LevelStateManager::MG->GetLopeDownStart())
	{
		Lope_ChainPtr->GetTransform()->AddLocalPosition({ 0,-1.0f* _DeltaTime*200.0f,0 });
		Lope_CordePtr->GetTransform()->AddLocalPosition({ 0,-0.7f* _DeltaTime*200.0f,0 });
	}
	//사운드가 끝나고, Metal 특정횟수 이상 건드렸을때 ChangeState
}
void PlaywithinaplayLevel::SlantBoardEnd()
{
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool RoshamboBool = true;
bool RoshamboStateBools = true;
void PlaywithinaplayLevel::RoshamboStart()
{
	//Debug------------------------------------------
	if (false != LevelStateManager::MG->GetIsProgress())
	{
		LevelStateManager::MG->SetIsProgressFalse();
	}
	BoardPtr.get()->GetCollision()->Off();
	//-----------------------------------------------
	if (nullptr != ChainPtr) { ChainPtr->Death(); ChainPtr = nullptr; }
	if (nullptr != BackCurtainPtr) { BackCurtainPtr->Death(); BackCurtainPtr = nullptr; }
	if (nullptr != CordonPtr) { CordonPtr->Death(); CordonPtr = nullptr; }
	
}
void PlaywithinaplayLevel::RoshamboUpdate(float _DeltaTime)
{
	//Roshambo FSM
	RSBUpdateState(_DeltaTime);

	CardTime += _DeltaTime;
	if (true == RoshamboBool)
	{
		R_SissorPtr = CreateActor<R_Sissor>();
		R_PaperPtr = CreateActor<R_Paper>();
		R_RockPtr = CreateActor<R_Rock>();
		R_EnemySissorPtr = CreateActor<R_EnemySissor>();
		R_EnemyRockPtr = CreateActor<R_EnemyRock>();
		R_EnemyPaperPtr = CreateActor<R_EnemyPaper>();
		R_DosPtr = CreateActor<R_Dos>();
		RoshamboBool = false;
	}
	//여기 밑은 전부 사운드가 끝나면 카드들 올라오게하기
	std::function<void()> Functions;
	if (CardTime > 3.0f && CardTime < 14.0f) { Functions = std::bind(&R_Rock::Up, R_RockPtr.get()); Functions();}
	if (CardTime > 6.0f && CardTime < 14.0f) { Functions = std::bind(&R_Paper::Up, R_PaperPtr.get()); Functions();}
	if (CardTime > 9.0f && CardTime < 14.0f) { Functions = std::bind(&R_Sissor::Up, R_SissorPtr.get()); Functions();}
	if (CardTime > 12.0f && CardTime < 14.0f)
	{
		Functions = std::bind(&R_Dos::Up, R_DosPtr.get()); Functions();
		Functions = std::bind(&R_EnemyPaper::Up, R_EnemyPaperPtr.get()); Functions();
		Functions = std::bind(&R_EnemyRock::Up, R_EnemyRockPtr.get()); Functions();
		Functions = std::bind(&R_EnemySissor::Up, R_EnemySissorPtr.get()); Functions();
	}
	//나는 다 골랐어요 사운드가 끝난후에
	if (CardTime > 15.0f && false==LevelStateManager::MG->GetIsSetCard()) { RSBChangeState(RoshamboState::SelectCard); LevelStateManager::MG->SetIsSetCardTrue(); }
	if (true==LevelStateManager::MG->GetIsCutTheLope()
		&& true==RoshamboStateBools)
	{
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::TiltBoard);
		RoshamboStateBools = false;
	}
}
void PlaywithinaplayLevel::RoshamboEnd()
{
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool BinaryCreateBool = true;
bool MetalNBool = true;
bool MetalOBool = true;
void PlaywithinaplayLevel::TiltBoardStart()
{
	//Debug------------------------------------------
	if (Lope_CordePtr.get() != nullptr)
	{
		Lope_CordePtr->Death();
		Lope_CordePtr = nullptr;
	}
	//-----------------------------------------------
	R_SissorPtr->Death();
	R_PaperPtr->Death();
	R_RockPtr->Death();
	R_EnemySissorPtr->Death();
	R_EnemyRockPtr->Death();
	R_EnemyPaperPtr->Death();
	R_DosPtr->Death();
	ChainPtr = CreateActor<Chain>();
	ChainPtr->SetChainLiveTime(5);
	TransparencyActorPtr = CreateActor<TransparencyActor>();
	BoardPtr->GetTransform()->SetParent(TransparencyActorPtr->GetRenderTransform());
}
void PlaywithinaplayLevel::TiltBoardUpdate(float _DeltaTime)
{
	if (TransparencyActorPtr->GetRenderTransform()->GetLocalRotation().z > -59.0f)
	{
		TransparencyActorPtr->GetRenderTransform()->AddLocalRotation({ 0,0,-100.0f * _DeltaTime });
	}
	if (TransparencyActorPtr->GetRenderTransform()->GetLocalRotation().z < -59.0f
		&&true== BinaryCreateBool)
	{
		N_TitleMetalPtr->GetTransform()->SetParent(nullptr);
		O_TitleMetalPtr->GetTransform()->SetParent(nullptr);
		Binary0Ptr1 = CreateActor<Binary0>(); Binary0Ptr1->SetBinary(2.2f, 700, { -700,300,0 }, { 42,42 });
		Binary0Ptr2 = CreateActor<Binary0>(); Binary0Ptr2->SetBinary(2.3f, 700, { -780,240,0 }, { 39,39 });
		Binary0Ptr3 = CreateActor<Binary0>(); Binary0Ptr3->SetBinary(2.7f, 600, { -840,210,0 }, { 44,44 });
		Binary0Ptr4 = CreateActor<Binary0>(); Binary0Ptr4->SetBinary(2.4f, 800, { -890,360,0 }, { 37,37 });
		Binary0Ptr5 = CreateActor<Binary0>(); Binary0Ptr5->SetBinary(2.5f, 600, { -900,260,0 }, { 35,35 });
		Binary0Ptr6 = CreateActor<Binary0>(); Binary0Ptr6->SetBinary(2.2f, 500, { -1020,400,0 }, { 37,37 });
		Binary0Ptr7 = CreateActor<Binary0>(); Binary0Ptr7->SetBinary(2.4f, 750, { -1020,340,0 }, { 39,39 });
		Binary0Ptr8 = CreateActor<Binary0>(); Binary0Ptr8->SetBinary(2.05f, 550, { -730,200,0 }, { 37,37 });
		Binary0Ptr9 = CreateActor<Binary0>(); Binary0Ptr9->SetBinary(2.1f, 500, { -800,120,0 }, { 42,42 });
		Binary0Ptr10 = CreateActor<Binary0>(); Binary0Ptr10->SetBinary(2.15f, 550, { -790,80,0 }, { 42,42  });
		Binary0Ptr11 = CreateActor<Binary0>(); Binary0Ptr11->SetBinary(2.2f, 600, { -820,-20,0 }, { 45,45 });
		//Binary 1 Setting
		Binary1Ptr1 = CreateActor<Binary1>();   Binary1Ptr1->SetBinary(2.2f, 600, { -800,280,0 }, { 42,42 });
		Binary1Ptr2 = CreateActor<Binary1>();	Binary1Ptr2->SetBinary(2.3f, 500, { -900,200,0 }, { 38,38 });
		Binary1Ptr3 = CreateActor<Binary1>();	Binary1Ptr3->SetBinary(2.7f, 550, { -850,200,0 }, { 35,35 });
		Binary1Ptr4 = CreateActor<Binary1>();	Binary1Ptr4->SetBinary(2.4f, 750, { -750,180,0 }, { 40,40 });
		Binary1Ptr5 = CreateActor<Binary1>();	Binary1Ptr5->SetBinary(2.5f, 500, { -770,80,0 }, { 31,31 });
		Binary1Ptr6 = CreateActor<Binary1>();	Binary1Ptr6->SetBinary(2.2f, 600, { -720,50,0 }, { 42,42 });
		Binary1Ptr7 = CreateActor<Binary1>();	Binary1Ptr7->SetBinary(2.4f, 800, { -700,-50,0 }, { 42,42 });
		Binary1Ptr8 = CreateActor<Binary1>();	Binary1Ptr8->SetBinary(2.05f, 600, { -980,-80,0 }, { 38,38 });
		Binary1Ptr9 = CreateActor<Binary1>();	Binary1Ptr9->SetBinary(2.1f, 700, { -1000,-100,0 }, { 46,46 });
		Binary1Ptr10 = CreateActor<Binary1>();	Binary1Ptr10->SetBinary(2.6f, 700, { -910,-120,0 }, { 40,40 });
		BinaryCreateBool = false;
	}
	if (false == BinaryCreateBool)
	{
		NOTime += _DeltaTime;
		N_TitleMetalPtr.get()->RightFallRigid(2.1f, 600, MetalNBool, NOTime);
		O_TitleMetalPtr.get()->RightFallRigid(2.2f, 500, MetalOBool, NOTime);
	}
}
void PlaywithinaplayLevel::TiltBoardEnd()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////