#include "PrecompileHeader.h"
#include "Chap2StartTextActor.h"
//Base
//PlatForm
//Core
//Actor
#include "LevelStateManager.h"

Chap2StartTextActor::Chap2StartTextActor()
{
}

Chap2StartTextActor::~Chap2StartTextActor()
{
}

void Chap2StartTextActor::Start()
{

}

void Chap2StartTextActor::Update(float _DeltaTime)
{
	if (false == LevelStateManager::MG->GetIsClickCalling())
	{
		SoundAndText(_DeltaTime);
	}
	else if(true == LevelStateManager::MG->GetIsClickCalling()
		&& 1 > LevelStateManager::MG->GetClockValue())
	{
		if (true == TSDeathBool)
		{
			if (Font != nullptr) { Font.get()->Death(); }
			if (Font2 != nullptr) { Font2.get()->Death(); }
			if (Font3 != nullptr) { Font3.get()->Death(); }
			if (Font4 != nullptr) { Font4.get()->Death(); }
			if (Font5 != nullptr) { Font5.get()->Death(); }
			if (Font6 != nullptr) { Font6.get()->Death(); }
			if (Font7 != nullptr) { Font7.get()->Death(); }
			if (Font8 != nullptr) { Font8.get()->Death(); }
			if (Font9 != nullptr) { Font9.get()->Death(); }
			if (Font10 != nullptr) { Font10.get()->Death(); }
			if (Font11 != nullptr) { Font11.get()->Death(); }
			if (Font12 != nullptr) { Font12.get()->Death(); }
			if (Font13 != nullptr) { Font13.get()->Death(); }
			if (Font14 != nullptr) { Font14.get()->Death(); }
			if (Font15 != nullptr) { Font15.get()->Death(); }
			Sound.Stop();
			TSDeathBool = false;
		}
		CallingText(_DeltaTime);
	}

	if (1 <= LevelStateManager::MG->GetClockValue())
	{
		if (true == TSDeathBool2)
		{
			if (CallingFont != nullptr) { CallingFont.get()->Death(); }
			if (CallingFont2 != nullptr) { CallingFont2.get()->Death(); }
			if (CallingFont3 != nullptr) { CallingFont3.get()->Death(); }
			if (CallingFont4 != nullptr) { CallingFont4.get()->Death(); }
			if (CallingFont5 != nullptr) { CallingFont5.get()->Death(); }
			if (CallingFont6 != nullptr) { CallingFont6.get()->Death(); }
			if (CallingFont7 != nullptr) { CallingFont7.get()->Death(); }
			if (CallingFont8 != nullptr) { CallingFont8.get()->Death(); }
			if (CallingFont9 != nullptr) { CallingFont9.get()->Death(); }
			if (CallingFont10 != nullptr) { CallingFont10.get()->Death(); }
			if (CallingFont11 != nullptr) { CallingFont11.get()->Death(); }
			if (CallingFont12 != nullptr) { CallingFont12.get()->Death(); }
			if (CallingFont13 != nullptr) { CallingFont13.get()->Death(); }
			if (CallingFont14 != nullptr) { CallingFont14.get()->Death(); }
			Sound.Stop();
			TSDeathBool2 = false;
		}
		ClockText(_DeltaTime);
	}
}

void Chap2StartTextActor::Render(float _Delta)
{

};

void Chap2StartTextActor::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	if (SoundTime > 0.5f)
	{
		static bool Chap2Play1 = true;
		if (true == Chap2Play1)
		{
			Sound = Play(Sound, "Chap02_Larsen.wav", 0.1f);
			Chap2Play1 = false;
		}
	}

	if (SoundTime > 3.0f)
	{
		static bool Chap2Play2 = true;
		if (true == Chap2Play2)
		{
			Sound = Play(Sound, "Chap02Whisper1.wav", 0.1f);
			Chap2Play2 = false;
		}
		Font = NFontCreate(Font, "당신의 내면이 말하고 있습니다.", GetTransform(), 2.5f);
	}

	if (SoundTime > 6.0f)
	{
		static bool Chap2Play3 = true;
		if (true == Chap2Play3)
		{
			Sound = Play(Sound, "Chap02Whisper1b.wav", 0.1f);
			Chap2Play3 = false;
		}
		Font2 = NFontCreate(Font2, "컴퓨터를 재부팅 하세요.", GetTransform(), 2.5f);
	}

	
	if (SoundTime > 9.0f)
	{
		static bool Chap2Play4 = true;
		if (true == Chap2Play4)
		{
			Sound = Play(Sound, "Chap02Whisper1c.wav", 0.1f);
			Chap2Play4 = false;
		}
		Font3 = NFontCreate(Font3, "이건 가짜 OS가 아닙니다.", GetTransform(), 2.5f);
	}

	if (SoundTime > 12.0f)
	{
		static bool Chap2Play5 = true;
		if (true == Chap2Play5)
		{
			Sound = Play(Sound, "Chap02Whisper1d.wav", 0.1f);
			Chap2Play5 = false;
		}
		Font4 = NFontCreate(Font4, "정말입니다.", GetTransform(), 2.0f);
	}


	if (SoundTime > 14.5f)
	{
		static bool Chap2Play6 = true;
		if (true == Chap2Play6)
		{
			Sound = Play(Sound, "Chap02Whisper1e.wav", 0.1f);
			Chap2Play6 = false;
		}
		Font5 = NFontCreate(Font5, "그리고 무슨 이유가 되었건 간에 접근금지가 된 폴더를 열면 안 됩니다.", GetTransform(), 4.0f);
	}

	if (SoundTime > 19.0f)
	{
		static bool Chap2Play7 = true;
		if (true == Chap2Play7)
		{
			Sound = Play(Sound, "Chap02Whisper1f.wav", 0.1f);
			Chap2Play7 = false;
		}
		Font6 = NFontCreate(Font6, "당신의 내면이 권하는 중입니다.", GetTransform(), 2.5f);
	}

	if (SoundTime > 35.0f)
	{
		static bool Chap2Play8 = true;
		if (true == Chap2Play8)
		{
			Sound = Play(Sound, "Chap02Whisper2.wav", 0.1f);
			Chap2Play8 = false;
		}
		Font7 = NFontCreate(Font7, "TV에서 브레이킹 굿 독점 에피소드가 방영 중입니다.", GetTransform(), 3.5f);
	}

	if (SoundTime > 39.0f)
	{
		static bool Chap2Play9 = true;
		if (true == Chap2Play9)
		{
			Sound = Play(Sound, "Chap02Whisper2b.wav", 0.1f);
			Chap2Play9 = false;
		}
		Font8 = NFontCreate(Font8, "당신의 내면으로서 절대 놓치지 말라고 말하고 싶습니다.", GetTransform(), 4.0f);
	}

	if (SoundTime > 43.5f)
	{
		static bool Chap2Play10 = true;
		if (true == Chap2Play10)
		{
			Sound = Play(Sound, "Chap02Whisper2c.wav", 0.1f);
			Chap2Play10 = false;
		}
		Font9 = NFontCreate(Font9, "가세요!", GetTransform(), 2.0f);
	}

	if (SoundTime > 65.0f)
	{
		static bool Chap2Play11 = true;
		if (true == Chap2Play11)
		{
			Sound = Play(Sound, "Chap02Whisper3.wav", 0.1f);
			Chap2Play11 = false;
		}
		Font10 = NFontCreate(Font10, "컴퓨터에 있는 재시작 버튼이 고장난 거 같습니다.", GetTransform(), 4.0f);
	}

	if (SoundTime > 69.5f)
	{
		static bool Chap2Play12 = true;
		if (true == Chap2Play12)
		{
			Sound = Play(Sound, "Chap02Whisper3b.wav", 0.1f);
			Chap2Play12 = false;
		}
		Font11 = NFontCreate(Font11, "당신의 내면이 그걸 누르고 있으라고 조언합니다.", GetTransform(), 3.5f);
	}

	if (SoundTime > 73.5f)
	{
		static bool Chap2Play13 = true;
		if (true == Chap2Play13)
		{
			Sound = Play(Sound, "Chap02Whisper3c.wav", 0.1f);
			Chap2Play13 = false;
		}
		Font12 = NFontCreate(Font12, "손 떼지 말고요.", GetTransform(), 2.0f);
	}

	if (SoundTime > 100.0f)
	{
		static bool Chap2Play14 = true;
		if (true == Chap2Play14)
		{
			Sound = Play(Sound, "Chap02Whisper4.wav", 0.1f);
			Chap2Play14 = false;
		}
		Font13 = NFontCreate(Font13, "고양이가 굶고 있습니다.", GetTransform(), 2.0f);
	}

	if (SoundTime > 102.5f)
	{
		static bool Chap2Play15 = true;
		if (true == Chap2Play15)
		{
			Sound = Play(Sound, "Chap02Whisper4b.wav", 0.1f);
			Chap2Play15 = false;
		}
		Font14 = NFontCreate(Font14, "야옹 야옹", GetTransform(), 2.0f);
	}

	if (SoundTime > 105.0f)
	{
		static bool Chap2Play16 = true;
		if (true == Chap2Play16)
		{
			Sound = Play(Sound, "Chap02Whisper4c.wav", 0.1f);
			Chap2Play16 = false;
		}
		Font15 = NFontCreate(Font15, "그렇습니다. 당신의 내면이 말하길 당신한테 고양이가 있다네요!", GetTransform(), 2.0f);
	}
}


void Chap2StartTextActor::CallingText(float _DeltaTime)
{
	CallingTime += _DeltaTime;
	if (CallingTime > 1.0f)
	{
		static bool Chap2Play17 = true;
		if (true == Chap2Play17)
		{
			Sound = Play(Sound, "Chap02SkiteCall01.wav", 0.2f);
			Chap2Play17 = false;
		}
		CallingFont = NFontCreate(CallingFont, "안녕하세요!", GetTransform(), 1.2f);
	}

	if (CallingTime > 2.5f)
	{
		static bool Chap2Play18 = true;
		if (true == Chap2Play18)
		{
			Sound = Play(Sound, "Chap02SkiteCall02.wav", 0.2f);
			Chap2Play18 = false;
		}
		CallingFont2 = NFontCreate(CallingFont2, "모르는 사람입니다.", GetTransform(), 1.7f);
	}

	if (CallingTime > 4.5f)
	{
		static bool Chap2Play19 = true;
		if (true == Chap2Play19)
		{
			Sound = Play(Sound, "Chap02SkiteCall03.wav", 0.2f);
			Chap2Play19 = false;
		}
		CallingFont3 = NFontCreate(CallingFont3, "그리고 제 목소리는 이미 존재하는 그 어떤 프로그램과도 안 닮았어요.", GetTransform(), 3.5f);
	}

	if (CallingTime > 8.0f)
	{
		static bool Chap2Play20 = true;
		if (true == Chap2Play20)
		{
			Sound = Play(Sound, "Chap02SkiteCall04.wav", 0.2f);
			Chap2Play20 = false;
		}
		CallingFont4 = NFontCreate(CallingFont4, "그냥 이 사진들 참 못찍었다고 말하려고요.", GetTransform(), 4.0f);
	}

	if (CallingTime > 12.5f)
	{
		static bool Chap2Play21 = true;
		if (true == Chap2Play21)
		{
			Sound = Play(Sound, "Chap02SkiteCall05.wav", 0.2f);
			Chap2Play21 = false;
		}
		CallingFont5 = NFontCreate(CallingFont5, "당장 정부에 이 게임 분류에 대해서 물어보려고 합니다.", GetTransform(), 4.0f);
	}

	if (CallingTime > 17.0f)
	{
		static bool Chap2Play22 = true;
		if (true == Chap2Play22)
		{
			Sound = Play(Sound, "Chap02SkiteCall06.wav", 0.2f);
			Chap2Play22 = false;
		}
		CallingFont6 = NFontCreate(CallingFont6, "게임 아닌 거 말이에요!", GetTransform(), 1.3f);
	}

	if (CallingTime > 19.0f)
	{
		static bool Chap2Play23 = true;
		if (true == Chap2Play23)
		{
			Sound = Play(Sound, "Chap02SkiteCall07.wav", 0.2f);
			Chap2Play23 = false;
		}
		CallingFont7 = NFontCreate(CallingFont7, "내 것도 아니에요! 친구 거예요.", GetTransform(), 2.0f);
	}

	if (CallingTime > 21.0f)
	{
		static bool Chap2Play24 = true;
		if (true == Chap2Play24)
		{
			Sound = Play(Sound, "CallingOff.wav", 0.2f);
			Chap2Play24 = false;
		}
	}


	if (CallingTime > 35.0f)
	{
		static bool Chap2Play25 = true;
		if (true == Chap2Play25)
		{
			Sound = Play(Sound, "Chap02Whisper7.wav", 0.1f);
			Chap2Play25 = false;
		}
		CallingFont8 = NFontCreate(CallingFont8, "당신의 내면이 말하길 태양이 막 폭발했다고 합니다.", GetTransform(), 4.0f);
	}

	if (CallingTime > 49.5f)
	{
		static bool Chap2Play26 = true;
		if (true == Chap2Play26)
		{
			Sound = Play(Sound, "Chap02Whisper7b.wav", 0.1f);
			Chap2Play26 = false;
		}
		CallingFont9 = NFontCreate(CallingFont9, "인생에 남은 8분을 정말로 모니터 앞에서 보내시겠습니까?", GetTransform(), 4.0f);
	}

	if (CallingTime > 54.0f)
	{
		static bool Chap2Play27 = true;
		if (true == Chap2Play27)
		{
			Sound = Play(Sound, "Chap02Whisper7c.wav", 0.1f);
			Chap2Play27 = false;
		}
		CallingFont10 = NFontCreate(CallingFont10, "그거 엄청 시간낭비일 텐데요...", GetTransform(), 2.0f);
	}

	if (CallingTime > 70.0f)
	{
		static bool Chap2Play28 = true;
		if (true == Chap2Play28)
		{
			Sound = Play(Sound, "Chap02Whisper8.wav", 0.1f);
			Chap2Play28 = false;
		}
		CallingFont11 = NFontCreate(CallingFont11, "거 참 안 떠납니까?", GetTransform(), 3.2f);
	}

	if (CallingTime > 73.5f)
	{
		static bool Chap2Play29 = true;
		if (true == Chap2Play29)
		{
			Sound = Play(Sound, "Chap02Whisper8b.wav", 0.1f);
			Chap2Play29 = false;
		}
		CallingFont12 = NFontCreate(CallingFont12, "... 그러니까...", GetTransform(), 1.2f);
	}


	if (CallingTime > 75.0f)
	{
		static bool Chap2Play30 = true;
		if (true == Chap2Play30)
		{
			Sound = Play(Sound, "Chap02Whisper8c.wav", 0.1f);
			Chap2Play30 = false;
		}
		CallingFont13 = NFontCreate(CallingFont13, "당신의 내면에서 이 어플리케이션을 종료하라고 제안하고 있습니다.", GetTransform(), 3.2f);
	}

	if (CallingTime > 78.5f)
	{
		static bool Chap2Play31 = true;
		if (true == Chap2Play31)
		{
			Sound = Play(Sound, "Chap02Whisper8d.wav", 0.1f);
			Chap2Play31 = false;
		}
		CallingFont14 = NFontCreate(CallingFont14, "매우 공손하게요. 네.", GetTransform(), 3.2f);
	}
}

void Chap2StartTextActor::ClockText(float _DeltaTime)
{
	ClockTime += _DeltaTime;

	if (ClockTime > 1.0f)
	{
		static bool Chap2Play32 = true;
		if (true == Chap2Play32)
		{
			Sound = Play(Sound, "Chap02ClockUnlocked01.wav", 0.1f);
			Chap2Play32 = false;
		}
		ClockFont = NFontCreate(ClockFont, "내 비밀번호를 알아냈다고?", GetTransform(), 2.0f);
	}

	if (ClockTime > 3.5f)
	{
		static bool Chap2Play33 = true;
		if (true == Chap2Play33)
		{
			Sound = Play(Sound, "Chap02ClockUnlocked02.wav", 0.1f);
			Chap2Play33 = false;
		}
		ClockFont2 = NFontCreate(ClockFont2, "그래도 시스템 시계로 뭘 할 수는 없겠지?", GetTransform(), 2.0f);
	}

	if (ClockTime > 6.0f)
	{
		static bool Chap2Play34 = true;
		if (true == Chap2Play34)
		{
			Sound = Play(Sound, "Chap02ClockUnlocked03.wav", 0.1f);
			Chap2Play34 = false;
		}
		ClockFont3 = NFontCreate(ClockFont3, "또 뭔가 부수지 않으면 좋겠는데...", GetTransform(), 2.0f);
	}

	if (ClockTime > 20.0f)
	{
		static bool Chap2Play35 = true;
		if (true == Chap2Play35)
		{
			Sound = Play(Sound, "Chap02Whisper9.wav", 0.1f);
			Chap2Play35 = false;
		}
		ClockFont4 = NFontCreate(ClockFont4, "업데이트가 다운로드 되었습니다.", GetTransform(), 2.0f);
	}

	if (ClockTime > 22.5f)
	{
		static bool Chap2Play36 = true;
		if (true == Chap2Play36)
		{
			Sound = Play(Sound, "Chap02Whisper9b.wav", 0.1f);
			Chap2Play36 = false;
		}
		ClockFont5 = NFontCreate(ClockFont5, "당신의 내면이 컴퓨터를 재부팅 하라고 권합니다.", GetTransform(), 3.0f);
	}


	if (ClockTime > 26.0f)
	{
		static bool Chap2Play37 = true;
		if (true == Chap2Play37)
		{
			Sound = Play(Sound, "Chap02Whisper9c.wav", 0.1f);
			Chap2Play37 = false;
		}
		ClockFont6 = NFontCreate(ClockFont6, "한 2주 동안 쉬다가 오세요.", GetTransform(), 3.0f);
	}

	if (ClockTime > 29.5f)
	{
		static bool Chap2Play38 = true;
		if (true == Chap2Play38)
		{
			Sound = Play(Sound, "Chap02Whisper9d.wav", 0.1f);
			Chap2Play38 = false;
		}
		ClockFont7 = NFontCreate(ClockFont7, "업데이트가 설치되는 동안 말이죠.", GetTransform(), 2.2f);
	}

	if (ClockTime > 32.0f)
	{
		static bool Chap2Play39 = true;
		if (true == Chap2Play39)
		{
			Sound = Play(Sound, "Chap02Whisper9e.wav", 0.1f);
			Chap2Play39 = false;
		}
		ClockFont8 = NFontCreate(ClockFont8, "업데이트는 매주 있습니다.", GetTransform(), 3.0f);
	}

	if (ClockTime > 55.0f)
	{
		static bool Chap2Play40 = true;
		if (true == Chap2Play40)
		{
			Sound = Play(Sound, "Chap02Whisper10.wav", 0.1f);
			Chap2Play40 = false;
		}
		ClockFont9 = NFontCreate(ClockFont9, "당신의 내면이 3에서 0까지 숫자를 셀 겁니다.", GetTransform(), 4.0f);
	}

	if (ClockTime > 59.5f)
	{
		static bool Chap2Play41 = true;
		if (true == Chap2Play41)
		{
			Sound = Play(Sound, "Chap02Whisper10b.wav", 0.1f);
			Chap2Play41 = false;
		}
		ClockFont10 = NFontCreate(ClockFont10, "0이 되면, 당신은 깊은 수면 속으로 빠져듭니다...", GetTransform(), 4.0f);
	}

	if (ClockTime > 64.0f)
	{
		static bool Chap2Play42 = true;
		if (true == Chap2Play42)
		{
			Sound = Play(Sound, "Chap02Whisper10b.wav", 0.1f);
			Chap2Play42 = false;
		}
		ClockFont11 = NFontCreate(ClockFont11, "0이 되면, 당신은 깊은 수면 속으로 빠져듭니다...", GetTransform(), 4.0f);
	}

	if (ClockTime > 68.5f)
	{
		static bool Chap2Play43 = true;
		if (true == Chap2Play43)
		{
			Sound = Play(Sound, "Chap02Whisper10c.wav", 0.1f);
			Chap2Play43 = false;
		}
		ClockFont12 = NFontCreate(ClockFont12, "3", GetTransform(), 1.7f);
	}

	if (ClockTime > 70.5f)
	{
		static bool Chap2Play44 = true;
		if (true == Chap2Play44)
		{
			Sound = Play(Sound, "Chap02Whisper10d.wav", 0.1f);
			Chap2Play44 = false;
		}
		ClockFont13 = NFontCreate(ClockFont13, "2", GetTransform(), 1.7f);
	}

	if (ClockTime > 72.5f)
	{
		static bool Chap2Play45 = true;
		if (true == Chap2Play45)
		{
			Sound = Play(Sound, "Chap02Whisper10e.wav", 0.1f);
			Chap2Play45 = false;
		}
		ClockFont14 = NFontCreate(ClockFont14, "1", GetTransform(), 1.7f);
	}

	if (ClockTime > 74.5f)
	{
		static bool Chap2Play46 = true;
		if (true == Chap2Play46)
		{
			Sound = Play(Sound, "Chap02Whisper10f.wav", 0.1f);
			Chap2Play46 = false;
		}
		ClockFont15 = NFontCreate(ClockFont15, "0", GetTransform(), 1.7f);
	}


	if (ClockTime > 77.5f)
	{
		static bool Chap2Play47 = true;
		if (true == Chap2Play47)
		{
			Sound = Play(Sound, "Chap02Whisper10g.wav", 0.1f);
			Chap2Play47 = false;
		}
		ClockFont16 = NFontCreate(ClockFont16, "-1?", GetTransform(), 1.7f);
	}

	if (ClockTime > 79.5f)
	{
		static bool Chap2Play48 = true;
		if (true == Chap2Play48)
		{
			Sound = Play(Sound, "Chap02Whisper10h.wav", 0.1f);
			Chap2Play48 = false;
		}
		ClockFont17 = NFontCreate(ClockFont17, "-2?", GetTransform(), 1.7f);
	}

	if (ClockTime > 81.5f)
	{
		static bool Chap2Play49 = true;
		if (true == Chap2Play49)
		{
			Sound = Play(Sound, "Chap02Whisper10i.wav", 0.1f);
			Chap2Play49 = false;
		}
		ClockFont18 = NFontCreate(ClockFont18, "TV에선 먹히던데.", GetTransform(), 1.7f);
	}

	if (ClockTime > 100.0f)
	{
		static bool Chap2Play50 = true;
		if (true == Chap2Play50)
		{
			Sound = Play(Sound, "Chap02Whisper11.wav", 0.1f);
			Chap2Play50 = false;
		}
		ClockFont19 = NFontCreate(ClockFont19, "당신의 내면이 이제 무슨 말을 해야할지 모르겠다고 합니다...", GetTransform(), 4.5f);
	}
}