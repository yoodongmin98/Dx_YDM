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
		Font = NFontCreate(Font, "������. ���п� ��մ� ������ �߳׿�. �����ؿ�.", GetTransform(), 5.0f);
	}

	if (SoundTime > 9.5f)
	{
		static bool EndPlay2 = true;
		if (true == EndPlay2)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser2.wav", 0.1f);
			EndPlay2 = false;
		}
		Font2 = NFontCreate(Font2, "�� ���� �����̿���.", GetTransform(), 1.5f);
	}

	if (SoundTime > 11.5f)
	{
		static bool EndPlay3 = true;
		if (true == EndPlay3)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser3.wav", 0.1f);
			EndPlay3 = false;
		}
		Font3 = NFontCreate(Font3, "�׸��� �� Ÿ�� û������ �ɺ� �����̱⵵ �ϰ��...", GetTransform(), 2.5f);
	}

	if (SoundTime > 14.5f)
	{
		static bool EndPlay4 = true;
		if (true == EndPlay4)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser4.wav", 0.1f);
			EndPlay4 = false;
		}
		Font4 = NFontCreate(Font4, "...�׸��� ������ ������ �ı��� �ϻ�� �� ���� Ŀ�� �����̳׿�...", GetTransform(), 4.0f);
	}

	if (SoundTime > 20.0f)
	{
		static bool EndPlay5 = true;
		if (true == EndPlay5)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser5.wav", 0.1f);
			EndPlay5 = false;
		}
		Font5 = NFontCreate(Font5, "��·��... ������.", GetTransform(), 2.0f);
	}

	if (SoundTime > 23.0f)
	{
		static bool EndPlay6 = true;
		if (true == EndPlay6)
		{
			Sound = Play(Sound, "EndGame_Intro Later.wav", 0.1f);
			EndPlay6 = false;
		}
		Font6 = NFontCreate(Font6, "�׷�... �ȳ�!", GetTransform(), 1.5f);
	}

	if (SoundTime > 30.0f)
	{
		static bool EndPlay7 = true;
		if (true == EndPlay7)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame1.wav", 0.1f);
			EndPlay7 = false;
		}
		Font7 = NFontCreate(Font7, "���� �ϰ�ʹٰ��?", GetTransform(), 2.0f);
	}

	if (SoundTime > 32.5f)
	{
		static bool EndPlay8 = true;
		if (true == EndPlay8)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame2.wav", 0.1f);
			EndPlay8 = false;
		}
		Font8 = NFontCreate(Font8, "�÷���? ��������?", GetTransform(), 2.0f);
	}

	if (SoundTime > 35.0f)
	{
		static bool EndPlay9 = true;
		if (true == EndPlay9)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame3.wav", 0.1f);
			EndPlay9 = false;
		}
		Font9 = NFontCreate(Font9, "��... ��Ÿ������, ���� �������ȴµ�...��ø���.", GetTransform(), 4.0f);
	}

	if (SoundTime > 45.0f)
	{
		static bool EndPlay10 = true;
		if (true == EndPlay10)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame4.wav", 0.1f);
			EndPlay10 = false;
		}
		Font10 = NFontCreate(Font10, "������, ����ġ�� ������ ������ ���۵� �ſ���.", GetTransform(), 4.0f);
	}

	if (SoundTime > 49.5f)
	{
		static bool EndPlay11 = true;
		if (true == EndPlay11)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame5.wav", 0.1f);
			EndPlay11 = false;
		}
		Font11 = NFontCreate(Font11, "�츮 ���� ������. �����ڴ��� ����� �츮 ���ӿ�.", GetTransform(), 3.5f);
	}

	if (SoundTime > 53.5f)
	{
		static bool EndPlay12 = true;
		if (true == EndPlay12)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame6.wav", 0.1f);
			EndPlay12 = false;
		}
		Font12 = NFontCreate(Font12, "�ٵ� �ٵ� �ٵ�...", GetTransform(), 2.0f);
	}

	if (SoundTime > 56.0f)
	{
		static bool EndPlay13 = true;
		if (true == EndPlay13)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame7.wav", 0.1f);
			EndPlay13 = false;
		}
		Font13 = NFontCreate(Font13, "�츮�� ������ �� ���...", GetTransform(), 2.0f);
	}

	if (SoundTime > 58.0f)
	{
		static bool EndPlay14 = true;
		if (true == EndPlay14)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame8.wav", 0.1f);
			EndPlay14 = false;
		}
		Font14 = NFontCreate(Font14, "...���ϰ� �賭�� ������ �޾� �����ϱ� ���ִ� ���ε�...", GetTransform(), 4.0f);
	}
	
	if (SoundTime > 63.0f)
	{
		static bool EndPlay15 = true;
		if (true == EndPlay15)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame9.wav", 0.1f);
			EndPlay15 = false;
		}
		Font15 = NFontCreate(Font15, "�� ��° ��ȸ�� �帮��.", GetTransform(), 2.0f);
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
	//��ư �ö��(�Ҹ�)
}


