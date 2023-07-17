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
		Font = NFontCreate(Font, "¾È µÅ, ¾È µÅ, ¾È µÅ, ¾È µÅ!!", GetTransform(), 2.5f);
	}
}