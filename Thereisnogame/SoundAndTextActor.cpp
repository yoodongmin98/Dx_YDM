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
			//Hmm하는 Sound
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
			Font24 = NFontCreate(Font24, "하ㅋ! 그럴줄 알았지롱!!", GetTransform(), 1.5f);
		}

		if (LastTime > 11.0f)
		{
			static bool EndPlay31 = true;
			if (true == EndPlay31)
			{
				//커튼닫고(LevelState)
				LevelStateManager::MG->IsCloseCurtainTrue();
				EndPlay31 = false;
			}
			Font24 = EndingFontCreate(Font24, "시청 해주셔서 감사합니다.", GetTransform(), 2.3f);
		}

		if (LastTime > 12.5f)
		{
			Font25 = EndingFontCreate(Font25, "이제 프로그램을 종료해주셔도 됩니다", GetTransform(), 2.8f);
		}

		if (LastTime > 15.5f)
		{
			Font26 = EndingFontCreate(Font26, "그리고 게임을 플레이 해주세요", GetTransform(), 2.8f);
		}

		if (LastTime > 18.5f)
		{
			Font27 = EndingFontCreate(Font27, "여태까지는 게임이 아니었거든요", GetTransform(), 2.8f);
		}

		if (LastTime > 21.5f)
		{
			Font28 = FontCreate(Font28, 35, "게임 아닌 것 제작사", float4::Zero, GetTransform(), 2);
			Font29 = FontCreate(Font29, 30, "DRAW ME A PIXEL", float4::Zero, GetTransform(), 2);
			Font30 = FontCreate(Font30, 35, "각본 및 감독", float4::Zero, GetTransform(), 2);
			Font31 = FontCreate(Font31, 30, "일단 나는 아님", float4::Zero, GetTransform(), 2);
			Font32 = FontCreate(Font32, 35, "코딩 및 스크립팅\n유동민", float4::Zero, GetTransform(), 2);
			Font33 = FontCreate(Font33, 30, "유동민", float4::Zero, GetTransform(), 2);
			Font34 = FontCreate(Font34, 35, "음향 효과 및 추가 음악\n유동민", float4::Zero, GetTransform(), 2);
			Font35 = FontCreate(Font35, 30, "유동민", float4::Zero, GetTransform(), 2);
			Font36 = FontCreate(Font36, 35, "특히 감사한분", float4::Zero, GetTransform(), 2);
			Font37 = FontCreate(Font37, 30, "유저, 당신\n우리 가족\n플레이 테스터 및 만인의 인류들", float4::Zero, GetTransform(), 2);
			Font38 = FontCreate(Font38, 30, "이 게임 아닌 것에서 그 어떤 프로그램도 다치지 않았습니다.", float4::Zero, GetTransform(), 2);


			/*Font28->GetTransform()->AddLocalPosition(0,50,0)*/
		}
	}
}

void SoundAndTextActor::SoundAndText(float _DeltaTime)
{
	Font28 = FontCreate(Font28, 35, "게임 아닌 것 제작사", float4::Zero, GetTransform(), 2);
	Font29 = FontCreate(Font29, 30, "DRAW ME A PIXEL", {0,-50, 0}, GetTransform(), 2);
	Font30 = FontCreate(Font30, 35, "각본 및 감독", {0,-300,-0}, GetTransform(), 2);
	Font31 = FontCreate(Font31, 30, "일단 나는 아님", {0,-350,0}, GetTransform(), 2);
	Font32 = FontCreate(Font32, 35, "코딩 및 스크립팅\n유동민", float4::Zero, GetTransform(), 2);
	Font33 = FontCreate(Font33, 30, "유동민", float4::Zero, GetTransform(), 2);
	Font34 = FontCreate(Font34, 35, "음향 효과 및 추가 음악\n유동민", float4::Zero, GetTransform(), 2);
	Font35 = FontCreate(Font35, 30, "유동민", float4::Zero, GetTransform(), 2);
	Font36 = FontCreate(Font36, 35, "특히 감사한분", float4::Zero, GetTransform(), 2);
	Font37 = FontCreate(Font37, 30, "유저, 당신\n우리 가족\n플레이 테스터 및 만인의 인류들", float4::Zero, GetTransform(), 2);
	Font38 = FontCreate(Font38, 30, "이 게임 아닌 것에서 그 어떤 프로그램도 다치지 않았습니다.", float4::Zero, GetTransform(), 2);


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
		Font = NFontCreate(Font, "유저님. 여러모로 평범하지않은 경험을 주시는군요. 참 감사해요...", GetTransform(), 5.0f);
	}

	if (SoundTime > 9.5f)
	{
		static bool EndPlay2 = true;
		if (true == EndPlay2)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser2.wav", 0.1f);
			EndPlay2 = false;
		}
		Font2 = NFontCreate(Font2, "그 고집 덕분에요.", GetTransform(), 1.5f);
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
		Font16 = NFontCreate(Font16, "이 스위치를 누르면 제 소스 코드를 삭제할 수 있어요...", GetTransform(), 3.0f);
	}
	
	if (SoundTime > 71.0f)
	{
		static bool EndPlay18 = true;
		if (true == EndPlay18)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame11.wav", 0.1f);
			EndPlay18 = false;
		}
		Font17 = NFontCreate(Font17, "...현실로 버그가 탈출하는 일이 없게 막아주는 버튼이죠.", GetTransform(), 4.0f);
	}

	if (SoundTime > 76.0f)
	{
		static bool EndPlay19 = true;
		if (true == EndPlay19)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame12.wav", 0.1f);
			EndPlay19 = false;
		}
		Font18 = NFontCreate(Font18, "이제 선택해줘요...친구.", GetTransform(), 3.0f);
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
		Font19 = NFontCreate(Font19, "게임이냐...", GetTransform(), 1.0f);
	}

	if (SoundTime > 81.5f)
	{
		static bool EndPlay22 = true;
		if (true == EndPlay22)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame14.wav", 0.1f);
			EndPlay22 = false;
		}
		Font20 = NFontCreate(Font20, "...아니면...", GetTransform(), 1.0f);
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
		Font21 = NFontCreate(Font21, "...세상의 안전...", GetTransform(), 1.0f);
	}

	if (SoundTime > 86.0f)
	{
		static bool EndPlay25 = true;
		if (true == EndPlay25)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame16.wav", 0.1f);
			EndPlay25 = false;
		}
		Font22 = NFontCreate(Font22, "지구 전체의 안전...", GetTransform(), 1.0f);
	}

	if (SoundTime > 87.0f)
	{
		static bool EndPlay26 = true;
		if (true == EndPlay26)
		{
			Sound = Play(Sound, "EndGame_Intro WhatGame17.wav", 0.1f);
			EndPlay26 = false;
		}
		Font23 = NFontCreate(Font23, "아니 범 우주적 안정이냐.", GetTransform(), 2.5f);
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


