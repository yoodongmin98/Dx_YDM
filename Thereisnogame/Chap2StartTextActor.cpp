#include "PrecompileHeader.h"
#include "Chap2StartTextActor.h"
//Base
//PlatForm
//Core
//Actor
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
	SoundAndText(_DeltaTime);
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

}