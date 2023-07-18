#include "PrecompileHeader.h"
#include "TextActor2.h"
//Base
//PlatForm
//Core
//Actor
TextActor2::TextActor2()
{
}

TextActor2::~TextActor2()
{
}

void TextActor2::Start()
{

}

void TextActor2::Update(float _DeltaTime)
{
	SoundAndText(_DeltaTime);
}

void TextActor2::Render(float _Delta)
{

};

void TextActor2::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	if (SoundTime > 3.0f)
	{
		static bool Play80 = true;
		if (true == Play80)
		{
			Sound = Play(Sound, "Chap01SafeOpen01.wav", 0.1f);
			Play80 = false;
		}
		Font = NFontCreate(Font, "아이고! 더 할 수 있는 게 없는데!", GetTransform(), 2.5f);
	}

	if (SoundTime > 6.0f)
	{
		static bool Play81 = true;
		if (true == Play81)
		{
			Sound = Play(Sound, "Chap01SafeOpen02.wav", 0.1f);
			Play81 = false;
		}
		Font2 = NFontCreate(Font2, "안 됐네요. 이제 남은 선택지가 없어요.", GetTransform(), 2.0f);
	}

	if (SoundTime > 8.5f)
	{
		static bool Play82 = true;
		if (true == Play82)
		{
			Sound = Play(Sound, "Chap01SafeOpen03.wav", 0.1f);
			Play82 = false;
		}
		Font3 = NFontCreate(Font3, "갑시다, 갑시다, 가요!", GetTransform(), 3.0f);
	}
}