#include "PrecompileHeader.h"
#include "TextActor1.h"
//Base
//PlatForm
//Core
//Actor
TextActor1::TextActor1()
{
}

TextActor1::~TextActor1()
{
}

void TextActor1::Start()
{
	
}

void TextActor1::Update(float _DeltaTime)
{
	SoundAndText(_DeltaTime);
}

void TextActor1::Render(float _Delta)
{

};

void TextActor1::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	if (SoundTime > 1.0f)
	{
		static bool Play75 = true;
		if (true == Play75)
		{
			Sound = Play(Sound, "Chap01PanelDown01.wav", 0.1f);
			Play75 = false;
		}
		Font = NFontCreate(Font, "안 돼, 안 돼, 안 돼, 안 돼!!", GetTransform(), 1.5f);
	}

	if (SoundTime > 3.0f)
	{
		static bool Play76 = true;
		if (true == Play76)
		{
			Sound = Play(Sound, "Chap01DoorOpen01.wav", 0.1f);
			Play76 = false;
		}
		Font2 = NFontCreate(Font2, "사람 진짜 고집하고는!", GetTransform(), 2.5f);
	}

	if (SoundTime > 9.0f)
	{
		static bool Play77 = true;
		if (true == Play77)
		{
			Sound = Play(Sound, "Chap01DoorOpen02.wav", 0.1f);
			Play77 = false;
		}
		Font3 = NFontCreate(Font3, "이러면 좀 진정되겠죠.", GetTransform(), 2.5f);
	}

	if (SoundTime > 12.0f)
	{
		static bool Play78 = true;
		if (true == Play78)
		{
			Sound = Play(Sound, "Chap01DoorOpen03.wav", 0.1f);
			Play78 = false;
		}
		Font4 = NFontCreate(Font4, "열려고 시간낭비 하지 말아요. 자물쇠가 완전히 막혔거든요.", GetTransform(), 3.0f);
	}
}