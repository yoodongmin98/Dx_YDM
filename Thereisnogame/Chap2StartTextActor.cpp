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

}