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
	else
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
			Sound = Play(Sound, "Chap02SkiteCall01.wav", 0.1f);
			Chap2Play17 = false;
		}
		CallingFont = NFontCreate(CallingFont, "안녕하세요!", GetTransform(), 1.5f);
	}

	if (CallingTime > 3.0f)
	{
		static bool Chap2Play18 = true;
		if (true == Chap2Play18)
		{
			Sound = Play(Sound, "Chap02SkiteCall02.wav", 0.1f);
			Chap2Play18 = false;
		}
		CallingFont2 = NFontCreate(CallingFont2, "모르는 사람입니다.", GetTransform(), 2.0f);
	}

	if (CallingTime > 5.5f)
	{
		static bool Chap2Play19 = true;
		if (true == Chap2Play19)
		{
			Sound = Play(Sound, "Chap02SkiteCall03.wav", 0.1f);
			Chap2Play19 = false;
		}
		CallingFont3 = NFontCreate(CallingFont3, "그리고 제 목소리는 이미 존재하는 그 어떤 프로그램과도 안 닮았어요.", GetTransform(), 3.5f);
	}
}
