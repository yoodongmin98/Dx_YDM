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


//Functional 호출용
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
		Font = NFontCreate(Font, "브라보, 유저님. 지금 가상으로 박수치고 있어요...", GetTransform(), 3.0f);
	}

	if (SoundTime > 5.5f)
	{
		static bool Play31 = true;
		if (true == Play31)
		{
			Sound = Play(Sound, "Chap01NoTitle02.wav", 0.1f);
			Play31 = false;
		}
		Font2 = NFontCreate(Font2, "내 아름다운 제목을 완전히 망쳐놨네요.", GetTransform(), 4.0f);
	}

	if (SoundTime > 10.0f)
	{
		static bool Play32 = true;
		if (true == Play32)
		{
			Sound = Play(Sound, "Chap01NoTitle03.wav", 0.1f);
			Play32 = false;
		}
		Font3 = NFontCreate(Font3, "뭐, 그래야 한다면 어쩔 수 없죠. 이번엔 좀 단단하게 만들 거예요.", GetTransform(), 5.0f);
	}

	if (SoundTime > 22.0f)
	{
		static bool Play33 = true;
		if (true == Play33)
		{
			Sound = Play(Sound, "Chap01TitleIron01.wav", 0.1f);
			Play33 = false;
		}
		Font4 = NFontCreate(Font4, "조금 흥분 한 거 같네요...", GetTransform(), 2.5f);
	}

	if (SoundTime > 25.0f)
	{
		static bool Play34 = true;
		if (true == Play34)
		{
			Sound = Play(Sound, "Chap01TitleIron02.wav", 0.1f);
			Play34 = false;
		}
		Font5 = NFontCreate(Font5, "이번엔 제목을 좀 내버려줬으면 해요...", GetTransform(), 3.0f);
	}

	if (SoundTime > 29.0f)
	{
		static bool Play35 = true;
		if (true == Play35)
		{
			Sound = Play(Sound, "Chap01TitleIron03.wav", 0.1f);
			Play35 = false;
		}
		Font6 = NFontCreate(Font6, "색 배열에 수차가 생긴 건가, 아니면 글자가 기울어진 건가?", GetTransform(), 4.0f);
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
			FontVector[Value] = NFontCreate(FontVector[Value], "내가 이겼다! 운 좋네요!", GetTransform(), 2.5f);
		}
		if (1 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "또 이겼다! 이거 되게 재밌네!", GetTransform(), 2.5f);
		}
		if (2 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "아, 안타깝네요! 또 졌어요.", GetTransform(), 2.5f);
		}
		if (3 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "이 게임 되게 재밌네요. 안 그런가요?", GetTransform(), 2.5f);
		}
		if (4 == Value)
		{
			FontVector[Value] = NFontCreate(FontVector[Value], "정말로 사기치는 건 아니에요.아뇨,아뇨,아니에요...", GetTransform(), 2.5f);
		}
	}
	if (Time > 7.0f)
	{
		if (0 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "자, 한 번 더 합시다!", GetTransform(), 1.9f);
		}
		if (1 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "다음엔 당신이 이길 거 같네요. 그냥 알겠어요.", GetTransform(), 1.9f);
		}
		if (2 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "포기하지 마요.", GetTransform(), 1.9f);
		}
		if (3 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "조금 반복되는 느낌이지만요.", GetTransform(), 1.9f);
		}
		if (4 == Value)
		{
			FontReplayVector[Value] = NFontCreate(FontReplayVector[Value], "지는 건 안 지겨워요?", GetTransform(), 1.9f);
		}
	}
	if (Time > 8.99f)
	{
		Time = 0.0f;
	}
}

