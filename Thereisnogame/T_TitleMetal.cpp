#include "PrecompileHeader.h"
#include "T_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"
#include "Play within a play Level.h"
#include "TitleMetal.h"

T_TitleMetal::T_TitleMetal()
{
}

T_TitleMetal::~T_TitleMetal()
{

}
bool T_TitleMetalStateBool = true;

void T_TitleMetal::Start()
{
	T_TitleMetals = Init(T_TitleMetals, "TitleMetal_T.png", { 94,142 }, { -300,230,0 });
	T_TitleMetalsCollision = CollisionInit(T_TitleMetalsCollision, { 94,142 }, { -300,230,0 });
	Play(Sound, "ImpactIron.wav", 0.1f);
}


void T_TitleMetal::Update(float _DeltaTime)
{
	BeforeRoshambo();
	DeathandCreateScreenT();
	if (false == T_TitleMetalStateBool)
	{
		SoundAndText(_DeltaTime);
	}
}


void T_TitleMetal::Render(float _Delta)
{

};


void T_TitleMetal::BeforeRoshambo()
{
	if (true == ClickCheck(T_TitleMetalsCollision))
	{
		Play(Sound, "MetalHit.wav", 0.1f);
		LevelStateManager::MG->SetHMCMetalPlus();
	}
	if (5 < LevelStateManager::MG->GetHMCMetal()
		&& true == T_TitleMetalStateBool)
	{
		PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::Roshambo);
		T_TitleMetalStateBool = false;
	}
}
bool ScreenTCreateBool = true;
void T_TitleMetal::DeathandCreateScreenT()
{
	if (true == LevelStateManager::MG->GetIsBalloonUp()
		&&true== ScreenTCreateBool)
	{
		Death();
		ScreenTCreateBool = false;
	}
}

void T_TitleMetal::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;

	if (SoundTime > 1.0f)
	{
		static bool Play36 = true;
		if (true == Play36)
		{
			Sound = Play(Sound, "Chap01Shifumi01.wav", 0.1f);
			Play36 = false;
		}
		Font = NFontCreate(Font, "거 그만 좀 두드려요! 짜증나게시리...", GetTransform(), 2.5f);
	}

	if (SoundTime > 4.0f)
	{
		static bool Play37 = true;
		if (true == Play37)
		{
			Sound = Play(Sound, "Chap01Shifumi01b.wav", 0.1f);
			Play37 = false;
		}
		Font2 = NFontCreate(Font2, "이 프로그램 나 혼자서는 못 꺼요", GetTransform(), 2.0f);
	}

	if (SoundTime > 6.5f)
	{
		static bool Play38 = true;
		if (true == Play38)
		{
			Sound = Play(Sound, "Chap01Shifumi01c.wav", 0.1f);
			Play38 = false;
		}
		Font3 = NFontCreate(Font3, "당신이 꺼줘야 해요.", GetTransform(), 1.5f);
	}

	if (SoundTime > 10.0f)
	{
		static bool Play39 = true;
		if (true == Play39)
		{
			Sound = Play(Sound, "Chap01Shifumi02.wav", 0.1f);
			Play39 = false;
		}
		Font4 = NFontCreate(Font4, "좋아요! 알았어요!", GetTransform(), 1.5f);
	}

	if (SoundTime > 12.0f)
	{
		static bool Play40 = true;
		if (true == Play40)
		{
			Sound = Play(Sound, "Chap01Shifumi03.wav", 0.1f);
			Play40 = false;
		}
		Font5 = NFontCreate(Font5, "게임이 하고싶은 거죠. 좋아요.", GetTransform(), 2.5f);
	}

	if (SoundTime > 15.0f)
	{
		static bool Play41 = true;
		if (true == Play41)
		{
			Sound = Play(Sound, "Chap01Shifumi04.wav", 0.1f);
			Play41 = false;
		}
		Font6 = NFontCreate(Font6, "그러면 우리...", GetTransform(), 2.0f);
	}

	if (SoundTime > 17.5f)
	{
		static bool Play42 = true;
		if (true == Play42)
		{
			Sound = Play(Sound, "Chap01Shifumi05.wav", 0.1f);
			Play42 = false;
		}
		Font7 = NFontCreate(Font7, "...어...", GetTransform(), 1.0f);
	}

	if (SoundTime > 19.0f)
	{
		static bool Play43 = true;
		if (true == Play43)
		{
			Sound = Play(Sound, "Chap01Shifumi06.wav", 0.1f);
			Play43 = false;
		}
		Font8 = NFontCreate(Font8, "로샴보 합시다.", GetTransform(), 2.0f);
	}

	if (SoundTime > 22.0f)
	{
		static bool Play44 = true;
		if (true == Play44)
		{
			Sound = Play(Sound, "Chap01Shifumi07.wav", 0.1f);
			Play44 = false;
		}
		Font9 = NFontCreate(Font9, "이거 재밌을 거예요!", GetTransform(), 2.0f);
	}

	if (SoundTime > 24.5f)
	{
		static bool Play45 = true;
		if (true == Play45)
		{
			Sound = Play(Sound, "Chap01Shifumi08.wav", 0.1f);
			Play45 = false;
		}
		Font10 = NFontCreate(Font10, "알겠지만, 가위, 바위, 보가 있는 게임이에요.", GetTransform(), 2.5f);
	}
}

