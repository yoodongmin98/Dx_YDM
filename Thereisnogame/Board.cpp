#include "PrecompileHeader.h"
#include "Board.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "Play within a play Level.h"
#include "LevelStateManager.h"
#include "Play within a play Level.h"
Board::Board()
{
}

Board::~Board()
{
}

void Board::Start()
{
	Boards = Init(Boards, "Board.png", { 776,422 }, { 0,70,0 });
	BoardsCollision = CollisionInit(BoardsCollision, { 770,420 }, { 0,70,0 });
	BoardsCollision->Off();
	FontVector.push_back(FontW0);
	FontVector.push_back(FontW1);
	FontVector.push_back(FontW2);
	FontVector.push_back(FontW3);
	FontVector.push_back(FontW4);
	FontVector.push_back(FontW5);

	FontReplayVector.push_back(FontR0);
	FontReplayVector.push_back(FontR1);
	FontReplayVector.push_back(FontR2);
	FontReplayVector.push_back(FontR3);
	FontReplayVector.push_back(FontR4);
	FontReplayVector.push_back(FontR5);
}

void Board::Update(float _DeltaTime)
{
	BoardMoveCheck();
	LevelStateMoveCheck();
	if (false == BoardFunc)
	{
		SoudAndText(_DeltaTime);
	}
	RoshamboText(_DeltaTime);
}

void Board::Render(float _Delta)
{

};


bool Boardmoves = true;
void Board::BoardMoveCheck()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (Chap1LevelState::DownBoard == PlaywithinaplayLevel::LM->GetLevelState()
		&& true==Boardmoves)
	{
		GetTransform()->AddLocalPosition({ 0,-1*Times,0 });
		if (GetTransform()->GetLocalPosition().y < -70.0f)
		{
			LevelStateManager::MG->SetIsBoardDownTrue();
			Boardmoves = false;
		}
	}
	if (true == LevelStateManager::MG->GetplaqueNarate())
	{
		BoardsCollision->On();
	}
	if (false == LevelStateManager::MG->GetIsProgress()
		&& true == ClickCheck(BoardsCollision))
	{
		Sound = Play(Sound, "IronTitleDown.wav", 0.1f);
		BoardsCollision->Death();
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::DownBoard);
	}
}


bool RemoveDown = true;
void Board::LevelStateMoveCheck()
{
	float Times=GameEngineTime::GlobalTime.GetDeltaTime()*200;
	if (Chap1LevelState::SlantBoard == PlaywithinaplayLevel::LM->GetLevelState()
		&&true== RemoveDown)
	{
		LevelStateManager::MG->SetLopeDownStartTrue();
		GetTransform()->AddLocalPosition({ 0,-1.5f*Times,0 });
		GetTransform()->AddLocalRotation({ 0,0,-0.05f*Times });
		if (GetTransform()->GetLocalPosition().y < -80.0f)
		{
			RemoveDown = false;
			LevelStateManager::MG->SetIsSlantBoardTrue();
			LevelStateManager::MG->SetLopeDownStartFalse();
		}
	}
}


//Functional ȣ���
void Board::BoardUp()
{
	float Times = GameEngineTime::GlobalTime.GetDeltaTime() * 200;
	if (true == BoardFunc)
	{
		GetTransform()->AddLocalPosition({ 0,1*Times,0 });
	}
	if (GetTransform()->GetLocalPosition().y > 70.0f)
	{
		BoardFunc = false;
	}
}

void Board::SoudAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	if (SoundTime > 2.0f)
	{
		static bool Play30 = true;
		if (true == Play30)
		{
			Sound = Play(Sound, "Chap01NoTitle01.wav", 0.1f);
			Play30 = false;
		}
		Font = NFontCreate(Font, "���, ������. ���� �������� �ڼ�ġ�� �־��...", GetTransform(), 3.0f);
	}

	if (SoundTime > 5.5f)
	{
		static bool Play31 = true;
		if (true == Play31)
		{
			Sound = Play(Sound, "Chap01NoTitle02.wav", 0.1f);
			Play31 = false;
		}
		Font2 = NFontCreate(Font2, "�� �Ƹ��ٿ� ������ ������ ���ĳ��׿�.", GetTransform(), 4.0f);
	}

	if (SoundTime > 10.0f)
	{
		static bool Play32 = true;
		if (true == Play32)
		{
			Sound = Play(Sound, "Chap01NoTitle03.wav", 0.1f);
			Play32 = false;
		}
		Font3 = NFontCreate(Font3, "��, �׷��� �Ѵٸ� ��¿ �� ����. �̹��� �� �ܴ��ϰ� ���� �ſ���.", GetTransform(), 5.0f);
	}

	if (SoundTime > 22.0f)
	{
		static bool Play33 = true;
		if (true == Play33)
		{
			Sound = Play(Sound, "Chap01TitleIron01.wav", 0.1f);
			Play33 = false;
		}
		Font4 = NFontCreate(Font4, "���� ��� �� �� ���׿�...", GetTransform(), 2.5f);
	}

	if (SoundTime > 25.0f)
	{
		static bool Play34 = true;
		if (true == Play34)
		{
			Sound = Play(Sound, "Chap01TitleIron02.wav", 0.1f);
			Play34 = false;
		}
		Font5 = NFontCreate(Font5, "�̹��� ������ �� ������������ �ؿ�...", GetTransform(), 3.0f);
	}

	if (SoundTime > 29.0f)
	{
		static bool Play35 = true;
		if (true == Play35)
		{
			Sound = Play(Sound, "Chap01TitleIron03.wav", 0.1f);
			Play35 = false;
		}
		Font6 = NFontCreate(Font6, "�� �迭�� ������ ���� �ǰ�, �ƴϸ� ���ڰ� ������ �ǰ�?", GetTransform(), 4.0f);
	}
}

void Board::RoshamboText(float _DeltaTime)
{
	Value = PlaywithinaplayLevel::LM->GetNarateValue();
	CardBool = PlaywithinaplayLevel::LM->GetEnemyCardBool();
	if (CardBool == true)
	{
		Time += _DeltaTime;
	}
	if (Time > 4.0f)
	{
		if (0 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "���� �̰��! �� ���׿�!", GetTransform(), 2.5f);
		}
		if (1 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "�� �̰��! �̰� �ǰ� ��ճ�!", GetTransform(), 2.5f);
		}
		if (2 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "��, ��Ÿ���׿�! �� �����.", GetTransform(), 2.5f);
		}
		if (3 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "�� ���� �ǰ� ��ճ׿�. �� �׷�����?", GetTransform(), 2.5f);
		}
		if (4 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "������ ���ġ�� �� �ƴϿ���.�ƴ�,�ƴ�,�ƴϿ���...", GetTransform(), 2.5f);
		}
	}
	if (Time > 7.0f)
	{
		if (0 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "��, �� �� �� �սô�!", GetTransform(), 1.9f);
		}
		if (1 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "������ ����� �̱� �� ���׿�. �׳� �˰ھ��.", GetTransform(), 1.9f);
		}
		if (2 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "�������� ����.", GetTransform(), 1.9f);
		}
		if (3 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "���� �ݺ��Ǵ� ������������.", GetTransform(), 1.9f);
		}
		if (4 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "���� �� �� ���ܿ���?", GetTransform(), 1.9f);
		}
	}
	if (Time > 8.99f)
	{
		Time = 0.0f;
	}
}

