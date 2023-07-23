#include "PrecompileHeader.h"
#include "SoundAndTextActor.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "LevelStateManager.h"
#include "EndingDeleteButton.h"
#include "PlaySmallArrow.h"
#include "DeleteArrow.h"
#include "BlueErrorMessage.h"
#include "EndingLevel.h"
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
	ActorDeathCheck(_DeltaTime);
}

void SoundAndTextActor::Render(float _Delta)
{

};
bool SoundAndTextActorDeathBool = true;
void SoundAndTextActor::ActorDeathCheck(float _DeltaTime)
{
	if (true == LevelStateManager::MG->GetIsClickPlayButton())
	{
		LastTime += _DeltaTime;
		if (true == SoundAndTextActorDeathBool)
		{
			//Hmm�ϴ� Sound
			DeleteArrowPtr.get()->Death();
			PlaySmallArrowPtr.get()->Death();
			EndingDeleteButtonPtr.get()->Death();
			SoundAndTextActorDeathBool = false;
		}

		if (LastTime > 6.0f)
		{
			static bool EndPlay28 = true;
			if (true == EndPlay28)
			{
				GetLevel()->CreateActor<BlueErrorMessage>();
				Sound = Play(Sound, "End_ErrorSound.wav", 0.1f);
				EndPlay28 = false;
			}
		}
		
		if (LastTime > 8.0f)
		{
			static bool EndPlay29 = true;
			if (true == EndPlay29)
			{
				Sound = Play(Sound, "Vinyl.wav", 0.1f);
				EndPlay29 = false;
			}
		}

		if (LastTime > 9.0f)
		{
			static bool EndPlay30 = true;
			if (true == EndPlay30)
			{
				EndingLevel::EL->ChangeBGM("End_Credits_Track_A.wav");
				Sound = Play(Sound, "EndGame_Intro Last IKnewIt.wav", 0.1f);
				EndPlay30 = false;
			}
			Font24 = NFontCreate(Font24, "�Ϥ�! �׷��� �˾�����!!", GetTransform(), 1.5f);
		}

		if (LastTime > 11.0f)
		{
			static bool EndPlay31 = true;
			if (true == EndPlay31)
			{
				//Ŀư�ݰ�(LevelState)
				LevelStateManager::MG->IsCloseCurtainTrue();
				EndPlay31 = false;
			}
			Font24 = EndingFontCreate(Font24, "��û ���ּż� �����մϴ�.", GetTransform(), 2.3f);
		}

		if (LastTime > 12.5f)
		{
			Font25 = EndingFontCreate(Font25, "���� ���α׷��� �������ּŵ� �˴ϴ�", GetTransform(), 2.8f);
		}

		if (LastTime > 15.5f)
		{
			Font26 = EndingFontCreate(Font26, "�׸��� ������ �÷��� ���ּ���", GetTransform(), 2.8f);
		}

		if (LastTime > 18.5f)
		{
			Font27 = EndingFontCreate(Font27, "���±����� ������ �ƴϾ��ŵ��", GetTransform(), 2.8f);
		}

		if (LastTime > 21.5f)
		{
			Font28 = FontCreate(Font28, 35, "���� �ƴ� �� ���ۻ�", float4::Zero, GetTransform(), 2);
			Font29 = FontCreate(Font29, 30, "DRAW ME A PIXEL", float4::Zero, GetTransform(), 2);
			Font30 = FontCreate(Font30, 35, "���� �� ����", float4::Zero, GetTransform(), 2);
			Font31 = FontCreate(Font31, 30, "�ϴ� ���� �ƴ�", float4::Zero, GetTransform(), 2);
			Font32 = FontCreate(Font32, 35, "�ڵ� �� ��ũ����\n������", float4::Zero, GetTransform(), 2);
			Font33 = FontCreate(Font33, 30, "������", float4::Zero, GetTransform(), 2);
			Font34 = FontCreate(Font34, 35, "���� ȿ�� �� �߰� ����\n������", float4::Zero, GetTransform(), 2);
			Font35 = FontCreate(Font35, 30, "������", float4::Zero, GetTransform(), 2);
			Font36 = FontCreate(Font36, 35, "Ư�� �����Ѻ�", float4::Zero, GetTransform(), 2);
			Font37 = FontCreate(Font37, 30, "����, ���\n�츮 ����\n�÷��� �׽��� �� ������ �η���", float4::Zero, GetTransform(), 2);
			Font38 = FontCreate(Font38, 30, "�� ���� �ƴ� �Ϳ��� �� � ���α׷��� ��ġ�� �ʾҽ��ϴ�.", float4::Zero, GetTransform(), 2);


			/*Font28->GetTransform()->AddLocalPosition(0,50,0)*/
		}
	}
}

void SoundAndTextActor::SoundAndText(float _DeltaTime)
{
	Font28 = FontCreate(Font28, 35, "���� �ƴ� �� ���ۻ�", float4::Zero, GetTransform(), 2);
	Font29 = FontCreate(Font29, 30, "DRAW ME A PIXEL", {0,-50, 0}, GetTransform(), 2);
	Font30 = FontCreate(Font30, 35, "���� �� ����", {0,-300,-0}, GetTransform(), 2);
	Font31 = FontCreate(Font31, 30, "�ϴ� ���� �ƴ�", {0,-350,0}, GetTransform(), 2);
	Font32 = FontCreate(Font32, 35, "�ڵ� �� ��ũ����\n������", float4::Zero, GetTransform(), 2);
	Font33 = FontCreate(Font33, 30, "������", float4::Zero, GetTransform(), 2);
	Font34 = FontCreate(Font34, 35, "���� ȿ�� �� �߰� ����\n������", float4::Zero, GetTransform(), 2);
	Font35 = FontCreate(Font35, 30, "������", float4::Zero, GetTransform(), 2);
	Font36 = FontCreate(Font36, 35, "Ư�� �����Ѻ�", float4::Zero, GetTransform(), 2);
	Font37 = FontCreate(Font37, 30, "����, ���\n�츮 ����\n�÷��� �׽��� �� ������ �η���", float4::Zero, GetTransform(), 2);
	Font38 = FontCreate(Font38, 30, "�� ���� �ƴ� �Ϳ��� �� � ���α׷��� ��ġ�� �ʾҽ��ϴ�.", float4::Zero, GetTransform(), 2);


	Font28->GetTransform()->AddLocalPosition({ 0, 50* _DeltaTime, 0 });
	Font29->GetTransform()->AddLocalPosition({ 0, 50 * _DeltaTime, 0 });
	Font30->GetTransform()->AddLocalPosition({ 0, 50 * _DeltaTime, 0 });
	Font31->GetTransform()->AddLocalPosition({ 0, 50 * _DeltaTime, 0 });

	SoundTime += _DeltaTime;
	if (SoundTime > 4.0f)
	{
		static bool EndPlay1 = true;
		if (true == EndPlay1)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser.wav", 0.1f);
			EndPlay1 = false;
		}
		Font = NFontCreate(Font, "������. ������� ����������� ������ �ֽô±���. �� �����ؿ�...", GetTransform(), 5.0f);
	}

	if (SoundTime > 9.5f)
	{
		static bool EndPlay2 = true;
		if (true == EndPlay2)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser2.wav", 0.1f);
			EndPlay2 = false;
		}
		Font2 = NFontCreate(Font2, "�� ���� ���п���.", GetTransform(), 1.5f);
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
			EndingDeleteButtonPtr=GetLevel()->CreateActor<EndingDeleteButton>();
			EndPlay16 = false;
		}
	}

	if (SoundTime > 67.5f)
	{
		static bool EndPlay17 = true;
		if (true == EndPlay17)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame10.wav", 0.1f);
			EndPlay17 = false;
		}
		Font16 = NFontCreate(Font16, "�� ����ġ�� ������ �� �ҽ� �ڵ带 ������ �� �־��...", GetTransform(), 3.0f);
	}
	
	if (SoundTime > 71.0f)
	{
		static bool EndPlay18 = true;
		if (true == EndPlay18)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame11.wav", 0.1f);
			EndPlay18 = false;
		}
		Font17 = NFontCreate(Font17, "...���Ƿ� ���װ� Ż���ϴ� ���� ���� �����ִ� ��ư����.", GetTransform(), 4.0f);
	}

	if (SoundTime > 76.0f)
	{
		static bool EndPlay19 = true;
		if (true == EndPlay19)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame12.wav", 0.1f);
			EndPlay19 = false;
		}
		Font18 = NFontCreate(Font18, "���� ���������...ģ��.", GetTransform(), 3.0f);
	}

	if (SoundTime > 79.0f)
	{
		static bool EndPlay20 = true;
		if (true == EndPlay20)
		{
			PlaySmallArrowPtr=GetLevel()->CreateActor<PlaySmallArrow>();
			EndPlay20 = false;
		}
	}

	if (SoundTime > 80.0f)
	{
		static bool EndPlay21 = true;
		if (true == EndPlay21)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame13.wav", 0.1f);
			EndPlay21 = false;
		}
		Font19 = NFontCreate(Font19, "�����̳�...", GetTransform(), 1.0f);
	}

	if (SoundTime > 81.5f)
	{
		static bool EndPlay22 = true;
		if (true == EndPlay22)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame14.wav", 0.1f);
			EndPlay22 = false;
		}
		Font20 = NFontCreate(Font20, "...�ƴϸ�...", GetTransform(), 1.0f);
	}

	if (SoundTime > 83.0f)
	{
		static bool EndPlay23 = true;
		if (true == EndPlay23)
		{
			DeleteArrowPtr=GetLevel()->CreateActor<DeleteArrow>();
			EndPlay23 = false;
		}
	}

	if (SoundTime > 84.5f)
	{
		static bool EndPlay24 = true;
		if (true == EndPlay24)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame15.wav", 0.1f);
			EndPlay24 = false;
		}
		Font21 = NFontCreate(Font21, "...������ ����...", GetTransform(), 1.0f);
	}

	if (SoundTime > 86.0f)
	{
		static bool EndPlay25 = true;
		if (true == EndPlay25)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame16.wav", 0.1f);
			EndPlay25 = false;
		}
		Font22 = NFontCreate(Font22, "���� ��ü�� ����...", GetTransform(), 1.0f);
	}

	if (SoundTime > 87.0f)
	{
		static bool EndPlay26 = true;
		if (true == EndPlay26)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame17.wav", 0.1f);
			EndPlay26 = false;
		}
		Font23 = NFontCreate(Font23, "�ƴ� �� ������ �����̳�.", GetTransform(), 2.5f);
	}

	if (SoundTime > 90.0f)
	{
		static bool EndPlay27 = true;
		if (true == EndPlay27)
		{
			Sound = Play(Sound, "End_ButtonOpenCase.wav", 0.1f);
			EndPlay27 = false;
		}
	}
}


