#include "PrecompileHeader.h"
#include "SoundAndTextActor.h"
//Base
//PlatForm
//Core
//Actor
#include "LevelStateManager.h"

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
		Font = NFontCreate(Font, "유저님. 덕분에 재밌는 경험을 했네요. 감사해요.", GetTransform(), 5.0f);
	}

	if (SoundTime > 9.5f)
	{
		static bool EndPlay2 = true;
		if (true == EndPlay2)
		{
			Sound = Play(Sound, "EndGame_Intro ThankyouUser2.wav", 0.1f);
			EndPlay2 = false;
		}
		Font2 = NFontCreate(Font2, "그 고집 덕분이에요.", GetTransform(), 5.0f);
	}
}


