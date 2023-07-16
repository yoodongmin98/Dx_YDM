#include "PrecompileHeader.h"
#include "TransparencyActor.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "BackCurtain.h"
#include "Play within a play Level.h"
#include "LevelStateManager.h"
TransparencyActor::TransparencyActor()
{
}

TransparencyActor::~TransparencyActor()
{
}

void TransparencyActor::Start()
{
	TransparencyActors = Init(TransparencyActors, "Chap04_ArrowLeft.png", { 0.1f,0.1f,1 }, { -370,140,0 });
}

void TransparencyActor::Update(float _DeltaTime)
{
	SoundAndText(_DeltaTime);
}
void TransparencyActor::Render(float _Delta)
{

};

void TransparencyActor::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;

	static bool Play60 = true;
	if (true == Play60)
	{
		Sound = Play(Sound, "Chap01ShifumiTakenScissor.wav", 0.1f);
		Play60 = false;
	}
	Font = NFontCreate(Font, "내 가위!", GetTransform(), 1.0f);

	if (SoundTime > 1.0f)
	{
		static bool Play61 = true;
		if (true == Play61)
		{
			Sound = Play(Sound, "Chap01RopeCut01.wav", 0.1f);
			Play61 = false;
		}
		Font2 = NFontCreate(Font2, "안 돼!", GetTransform(), 1.5f);
	}

	if (SoundTime > 1.7f)
	{
		static bool Play64 = true;
		if (true == Play64)
		{
			Sound = Play(Sound, "Balloon.wav", 0.1f);
			Play64 = false;
		}
	}

	if (SoundTime > 5.5f)
	{
		static bool Play62 = true;
		if (true == Play62)
		{
			Sound = Play(Sound, "Chap01RopeCut02.wav", 0.1f);
			Play62 = false;
		}
		Font3 = NFontCreate(Font3, "휴. 안전 에어백이 있었네.", GetTransform(), 2.0f);
	}

	if (SoundTime > 8.0f)
	{
		static bool Play63 = true;
		if (true == Play63)
		{
			Sound = Play(Sound, "Chap01RopeCut03.wav", 0.1f);
			Play63 = false;
		}
		Font4 = NFontCreate(Font4, "다행히, 게임을 보호하기 위해서라면 뭐든 생각해뒀죠.", GetTransform(), 2.5f);
	}

	if (SoundTime > 11.0f)
	{
		static bool Play65 = true;
		if (true == Play65)
		{
			Sound = Play(Sound, "Chap01RopeCut04.wav", 0.1f);
			Play65 = false;
		}
		Font5 = NFontCreate(Font5, "게임 아닌 거 말이에요!", GetTransform(), 1.5f);
	}

	if (SoundTime > 13.5f)
	{
		static bool Play66 = true;
		if (true == Play66)
		{
			Sound = Play(Sound, "Chap01RopeCut05.wav", 0.1f);
			Play66 = false;
		}
		Font6 = NFontCreate(Font6, "여긴 게임 없어요.", GetTransform(), 2.0f);
	}

	if (SoundTime > 15.5f)
	{
		static bool Play67 = true;
		if (true == Play67)
		{
			Sound = Play(Sound, "Chap01RopeCut06.wav", 0.1f);
			Play67 = false;
		}
		Font7 = NFontCreate(Font7, "끝이에요.", GetTransform(), 1.5f);
	}

	if (SoundTime > 19.0f)
	{
		static bool Play68 = true;
		if (true == Play68)
		{
			Sound = Play(Sound, "Chap01RopeCut07.wav", 0.1f);
			Play68 = false;
		}
		Font8 = NFontCreate(Font8, "이래서 이 프로그램을 끄고 나가야하는 거예요.", GetTransform(), 3.0f);
	}

	if (SoundTime > 22.5f)
	{
		static bool Play69 = true;
		if (true == Play69)
		{
			Sound = Play(Sound, "Chap01RopeCut08.wav", 0.1f);
			Play69 = false;
		}
		Font9 = NFontCreate(Font9, "멋진 벽돌 깨기 해서 재밌었길 바라요.", GetTransform(), 2.5f);
	}

	if (SoundTime > 25.5f)
	{
		static bool Play70 = true;
		if (true == Play70)
		{
			Sound = Play(Sound, "Chap01RopeCut09.wav", 0.1f);
			Play70 = false;
		}
		Font10 = NFontCreate(Font10, "그리고 하나도 조작하지 않은 로샴보도 말이죠.", GetTransform(), 3.0f);
	}
}

