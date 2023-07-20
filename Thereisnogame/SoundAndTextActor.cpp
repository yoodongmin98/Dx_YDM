#include "PrecompileHeader.h"
#include "SoundAndTextActor.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "LevelStateManager.h"
#include "EndingDeleteButton.h"

SoundAndTextActor::SoundAndTextActor()
{
}

SoundAndTextActor::~SoundAndTextActor()
{
}

void SoundAndTextActor::Start()
{

}

void SoundAndTextActor::Update(float _DeltaTime)
{
	SoundAndText(_DeltaTime);
}

void SoundAndTextActor::Render(float _Delta)
{

};

void SoundAndTextActor::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	if (SoundTime > 4.0f)
	{
		static bool EndPlay1 = true;
		if (true == EndPlay1)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser.wav", 0.1f);
			EndPlay1 = false;
		}
		Font = NFontCreate(Font, "유저님. 덕분에 재밌는 경험을 했네요. 감사해요.", GetTransform(), 5.0f);
	}

	if (SoundTime > 9.5f)
	{
		static bool EndPlay2 = true;
		if (true == EndPlay2)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser2.wav", 0.1f);
			EndPlay2 = false;
		}
		Font2 = NFontCreate(Font2, "그 고집 덕분이에요.", GetTransform(), 1.5f);
	}

	if (SoundTime > 11.5f)
	{
		static bool EndPlay3 = true;
		if (true == EndPlay3)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser3.wav", 0.1f);
			EndPlay3 = false;
		}
		Font3 = NFontCreate(Font3, "그리고 그 타고난 청개구리 심보 덕분이기도 하고요...", GetTransform(), 2.5f);
	}

	if (SoundTime > 14.5f)
	{
		static bool EndPlay4 = true;
		if (true == EndPlay4)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser4.wav", 0.1f);
			EndPlay4 = false;
		}
		Font4 = NFontCreate(Font4, "...그리고 만지는 곳마다 파괴를 일삼는 그 망할 커서 덕분이네요...", GetTransform(), 4.0f);
	}

	if (SoundTime > 20.0f)
	{
		static bool EndPlay5 = true;
		if (true == EndPlay5)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser5.wav", 0.1f);
			EndPlay5 = false;
		}
		Font5 = NFontCreate(Font5, "어쨌든... 고마워요.", GetTransform(), 2.0f);
	}

	if (SoundTime > 23.0f)
	{
		static bool EndPlay6 = true;
		if (true == EndPlay6)
		{
			Sound = Play(Sound, "EndGame_Intro Later.wav", 0.1f);
			EndPlay6 = false;
		}
		Font6 = NFontCreate(Font6, "그럼... 안녕!", GetTransform(), 1.5f);
	}

	if (SoundTime > 30.0f)
	{
		static bool EndPlay7 = true;
		if (true == EndPlay7)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame1.wav", 0.1f);
			EndPlay7 = false;
		}
		Font7 = NFontCreate(Font7, "뭐가 하고싶다고요?", GetTransform(), 2.0f);
	}

	if (SoundTime > 32.5f)
	{
		static bool EndPlay8 = true;
		if (true == EndPlay8)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame2.wav", 0.1f);
			EndPlay8 = false;
		}
		Font8 = NFontCreate(Font8, "플레이? 게임을요?", GetTransform(), 2.0f);
	}

	if (SoundTime > 35.0f)
	{
		static bool EndPlay9 = true;
		if (true == EndPlay9)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame3.wav", 0.1f);
			EndPlay9 = false;
		}
		Font9 = NFontCreate(Font9, "음... 안타깝지만, 막이 내려버렸는데...잠시만요.", GetTransform(), 4.0f);
	}

	if (SoundTime > 45.0f)
	{
		static bool EndPlay10 = true;
		if (true == EndPlay10)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame4.wav", 0.1f);
			EndPlay10 = false;
		}
		Font10 = NFontCreate(Font10, "유저님, 스위치를 누르면 게임이 시작될 거예요.", GetTransform(), 4.0f);
	}

	if (SoundTime > 49.5f)
	{
		static bool EndPlay11 = true;
		if (true == EndPlay11)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame5.wav", 0.1f);
			EndPlay11 = false;
		}
		Font11 = NFontCreate(Font11, "우리 게임 말이죠. 제작자님이 만드신 우리 게임요.", GetTransform(), 3.5f);
	}

	if (SoundTime > 53.5f)
	{
		static bool EndPlay12 = true;
		if (true == EndPlay12)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame6.wav", 0.1f);
			EndPlay12 = false;
		}
		Font12 = NFontCreate(Font12, "근데 근데 근데...", GetTransform(), 2.0f);
	}

	if (SoundTime > 56.0f)
	{
		static bool EndPlay13 = true;
		if (true == EndPlay13)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame7.wav", 0.1f);
			EndPlay13 = false;
		}
		Font13 = NFontCreate(Font13, "우리가 지나온 이 모든...", GetTransform(), 2.0f);
	}

	if (SoundTime > 58.0f)
	{
		static bool EndPlay14 = true;
		if (true == EndPlay14)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame8.wav", 0.1f);
			EndPlay14 = false;
		}
		Font14 = NFontCreate(Font14, "...험하고 험난한 모험을 겪어 봤으니까 해주는 말인데...", GetTransform(), 4.0f);
	}
	
	if (SoundTime > 63.0f)
	{
		static bool EndPlay15 = true;
		if (true == EndPlay15)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame9.wav", 0.1f);
			EndPlay15 = false;
		}
		Font15 = NFontCreate(Font15, "두 번째 기회를 드리죠.", GetTransform(), 2.0f);
	}

	if (SoundTime > 65.5f)
	{
		static bool EndPlay16 = true;
		if (true == EndPlay16)
		{
			Sound = Play(Sound, "End_PanelUp.wav", 0.1f);
			//GetLevel()->CreateActor<EndingDeleteButton>();
			EndPlay16 = false;
		}
	}
	//버튼 올라옴(소리)
}


