#include "PrecompileHeader.h"
#include "Plaque.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "BackCurtain.h"
#include "Play within a play Level.h"
#include "LevelStateManager.h"

Plaque::Plaque()
{
}

Plaque::~Plaque()
{
}

void Plaque::Start()
{
	Plaques = Init(Plaques, "Plaque.png", { 446,245 }, { 5,50,0 });
	PlaquesCollision = CollisionInit(PlaquesCollision, { 400,200 }, { 5,50,0 });
	PlaquesCollision->Off();
}

void Plaque::Update(float _DeltaTime)
{
	if (Chap1LevelState::ClickCordon == PlaywithinaplayLevel::LM->GetLevelState())
	{
		PlaquesCollision->On();
		if (true == ClickCheck(PlaquesCollision))
		{
			Play(Sound, "PlaqueHit.wav", 0.1f);
			ClickCount++;
		}
	}
	else
	{
		PlaquesCollision->Off();
	}
	if (ClickCount > 5 && true == ClickCheck(PlaquesCollision))
	{
		StartBool = true;
	}
	if (true == StartBool)
	{
		SoundAndText(_DeltaTime);
	}
	
}

void Plaque::Render(float _Delta)
{
	
};



void Plaque::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	
	static bool Play1 = true;
	if (true == Play1)
	{
		Sound = Play(Sound, "Chap01Intro01.wav", 0.1f);
		Play1 = false;
	}
	Font = NFontCreate(Font, "누가 자꾸 두드리는거야?", GetTransform(), 2);

	if (SoundTime > 3.0f)
	{
		static bool Play2 = true;
		if (true == Play2)
		{
			Sound = Play(Sound, "Chap01Intro02.wav", 0.1f);
			Play2 = false;
		}
		Font2 = NFontCreate(Font2, "뭐야! 사람 있잖아!", GetTransform(), 2);
	}

	if (SoundTime > 5.0f)
	{
		static bool Play3 = true;
		if (true == Play3)
		{
			Sound = Play(Sound, "Chap01Intro03.wav", 0.1f);
			Play3 = false;
		}
		Font3 = NFontCreate(Font3, "잠시만요, 잠시만!", GetTransform(), 2);
	}

	if (SoundTime > 8.0f)
	{
		if (true == StateBool)
		{
			Sound = Play(Sound, "CurtainClose.wav", 0.1f);
			PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::CreateBoard);
			StateBool = false;
		}
	}

	if (SoundTime > 9.0f)
	{
		static bool Play4 = true;
		if (true == Play4)
		{
			Sound = Play(Sound, "Feuille01.wav", 0.1f);
			Sound = Play(Sound, "Chap01Intro04.wav", 0.1f);
			Play4 = false;
		}
		Font4 = NFontCreate(Font4, "대사집 어디갔지?", GetTransform(), 2.0f);
	}

	if (SoundTime > 11.0f)
	{
		static bool Play5 = true;
		if (true == Play5)
		{
			Sound = Play(Sound, "PageTurn.wav", 0.1f);
			Sound = Play(Sound, "Chap01Intro05.wav", 0.1f);
			Play5 = false;
		}
		Font5 = NFontCreate(Font5, "아... 여기 있다!", GetTransform(), 2.0f);
	}

	if (SoundTime > 15.0f)
	{
		static bool Play6 = true;
		if (true == Play6)
		{
			Sound = Play(Sound, "CurtainClose.wav", 0.1f);
			Sound = Play(Sound, "Chap01Intro06.wav", 0.1f);
			Play6 = false;
		}
		Font6 = NFontCreate(Font6, "제목을 까먹을 뻔 했네.", GetTransform(), 2.0f);
	}

	if (SoundTime > 17.0f)
	{
		static bool Play7 = true;
		if (true == Play7)
		{
			Sound = Play(Sound, "IronTitleDown.wav", 0.1f); 
			Play7 = false;
		}
	}

	if (SoundTime > 19.0f)
	{
		static bool Play8 = true;
		if (true == Play8)
		{
			Sound = Play(Sound, "Chap01Intro06b.wav", 0.1f);
			Play8 = false;
		}
		Font7 = NFontCreate(Font7, "긴장하지 말자. 긴장하지 말자...", GetTransform(), 2.0f);
	}

	if (SoundTime > 23.0f)
	{
		static bool Play9 = true;
		if (true == Play9)
		{
			Sound = Play(Sound, "CurtainOpen(Start).wav", 0.1f);
			Sound = Play(Sound, "ChoraleIntro.wav", 0.1f);
			Play9 = false;
		}
	}

	if (SoundTime > 25.0f)
	{
		static bool Play10 = true;
		if (true == Play10)
		{
			Sound = Play(Sound, "Chap01Intro_ChauffeVoix.wav", 0.1f);
			Play10 = false;
		}
	}

	if (SoundTime > 28.0f)
	{
		static bool Play11 = true;
		if (true == Play11)
		{
			Sound = Play(Sound, "Chap01Intro07.wav", 0.1f);
			Play11 = false;
		}
		Font8 = NFontCreate(Font8, "안녕하십니까, 유저님!", GetTransform(), 2.2f);
	}

	if (SoundTime > 30.5f)
	{
		static bool Play12 = true;
		if (true == Play12)
		{
			Sound = Play(Sound, "Chap01Intro07b.wav", 0.1f);
			Play12 = false;
		}
		Font9 = NFontCreate(Font9, "프로그램에서 알려드립니다.", GetTransform(), 2.2f);
	}

	if (SoundTime > 33.0f)
	{
		static bool Play13 = true;
		if (true == Play13)
		{
			Sound = Play(Sound, "Chap01Intro08.wav", 0.1f);
			Play13 = false;
		}
		Font10 = NFontCreate(Font10, "안타까운 소식이 있습니다.", GetTransform(), 2.2f);
	}

	if (SoundTime > 35.5f)
	{
		static bool Play14 = true;
		if (true == Play14)
		{
			Sound = Play(Sound, "Chap01Intro09.wav", 0.1f);
			Play14 = false;
		}
		Font11 = NFontCreate(Font11, "사실, 여긴 게임 같은거 없어요.", GetTransform(), 2.2f);
	}

	if (SoundTime > 38.0f)
	{
		static bool Play15 = true;
		if (true == Play15)
		{
			Sound = Play(Sound, "Chap01Intro10.wav", 0.1f);
			Play15 = false;
		}
		Font12 = NFontCreate(Font12, "금융 위기니, 인디게임계의 종말이니, 어쩌고 저쩌고... 뭐 그런 거죠.", GetTransform(), 3.5f);
	}

	if (SoundTime > 42.0f)
	{
		static bool Play16 = true;
		if (true == Play16)
		{
			Sound = Play(Sound, "Feuille01.wav", 0.1f);
			Sound = Play(Sound, "Chap01Intro11.wav", 0.1f);
			Play16 = false;
		}
		Font13 = NFontCreate(Font13, "너무 실망하시진 않길 바라요.", GetTransform(), 2.2f);
	}

	if (SoundTime > 45.0f)
	{
		static bool Play17 = true;
		if (true == Play17)
		{
			Sound = Play(Sound, "Corde01.wav", 0.1f);
			Sound = Play(Sound, "Chap01Intro12.wav", 0.1f);
			Play17 = false;
		}
		Font14 = NFontCreate(Font14, "TV는 계속 볼 수 있잖아요.", GetTransform(), 1.7f);
	}

	if (SoundTime > 47.0f)
	{
		static bool Play18 = true;
		if (true == Play18)
		{
			Sound = Play(Sound, "Chap01Intro12b.wav", 0.1f);
			Play18 = false;
		}
		Font15 = NFontCreate(Font15, "밖에 좀 나가요.", GetTransform(), 1.2f);
	}

	if (SoundTime > 48.5f)
	{
		static bool Play19 = true;
		if (true == Play19)
		{
			Sound = Play(Sound, "Chap01Intro13.wav", 0.1f);
			Play19 = false;
		}
		Font16 = NFontCreate(Font16, "책도 읽고요.", GetTransform(), 2.0f);
	}

	if (SoundTime > 51.0f)
	{
		static bool Play20 = true;
		if (true == Play20)
		{
			Sound = Play(Sound, "Chap01Intro14.wav", 0.1f);
			Play20 = false;
		}
		Font17 = NFontCreate(Font17, "네. 여기 게임 없습니다. 당신이랑 나 뿐이에요...", GetTransform(), 3.0f);
	}

	if (SoundTime > 55.0f)
	{
		static bool Play21 = true;
		if (true == Play21)
		{
			LevelStateManager::MG->SetplaqueNarateTrue();
			Sound = Play(Sound, "Chap01Intro15.wav", 0.1f);
			Play21 = false;
		}
		Font18 = NFontCreate(Font18, "...환불 얘기는 하지 말아주세요. 알겠죠?", GetTransform(), 2.5f);
	}

	if (SoundTime > 59.0f)
	{
		static bool Play22 = true;
		if (true == Play22)
		{
			LevelStateManager::MG->SetplaqueNarateTrue();
			Sound = Play(Sound, "Chap01Intro25.wav", 0.1f);
			Play22 = false;
		}
		Font19 = NFontCreate(Font19, "제목은 건들지 마세요. 그거 다 수작업한 거예요.", GetTransform(), 3.5f);
	}

	if (SoundTime > 64.0f)
	{
		static bool Play23 = true;
		if (true == Play23)
		{
			LevelStateManager::MG->SetplaqueNarateTrue();
			Sound = Play(Sound, "Chap01Intro26.wav", 0.1f);
			Play23 = false;
		}
		Font20 = NFontCreate(Font20, "특히 저 느낌표 부분요. 풀이 다 떨어졌거든요.", GetTransform(), 3.5f);
	}
}

