#include "PrecompileHeader.h"
#include "Plaque.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "BackCurtain.h"
#include "Play within a play Level.h"

Plaque::Plaque()
{
}

Plaque::~Plaque()
{
}

void Plaque::Start()
{
	Plaques = Init(Plaques, "Plaque.png", { 446,245 }, { 5,50,0 });
	PlaquesCollision = CollisionInit(PlaquesCollision, { 400,200 }, { 5,50,0 });
	PlaquesCollision->Off();
}

void Plaque::Update(float _DeltaTime)
{
	if (Chap1LevelState::ClickCordon == PlaywithinaplayLevel::LM->GetLevelState())
	{
		PlaquesCollision->On();
		if (true == ClickCheck(PlaquesCollision))
		{
			Play(Sound, "PlaqueHit.wav", 0.1f);
			ClickCount++;
		}
	}
	else
	{
		PlaquesCollision->Off();
	}
	if (ClickCount > 5 && true == ClickCheck(PlaquesCollision))
	{
		StartBool = true;
	}
	if (true == StartBool)
	{
		SoundAndText(_DeltaTime);
	}
	
}

void Plaque::Render(float _Delta)
{
	
};



void Plaque::SoundAndText(float _DeltaTime)
{
	SoundTime += _DeltaTime;
	
	static bool Play1 = true;
	if (true == Play1)
	{
		Sound = Play(Sound, "Chap01Intro01.wav", 0.1f);
		Play1 = false;
	}
	Font = NFontCreate(Font, "���� �ڲ� �ε帮�°ž�?", GetTransform(), 3);

	if (SoundTime > 3.0f)
	{
		static bool Play2 = true;
		if (true == Play2)
		{
			Sound = Play(Sound, "Chap01Intro02.wav", 0.1f);
			Play2 = false;
		}
		Font2 = NFontCreate(Font2, "����! ��� ���ݾ�!", GetTransform(), 2);
	}

	if (SoundTime > 6.0f)
	{
		static bool Play3 = true;
		if (true == Play3)
		{
			Sound = Play(Sound, "Chap01Intro03.wav", 0.1f);
			Play3 = false;
		}
		Font3 = NFontCreate(Font3, "��ø���, ��ø�!", GetTransform(), 2);
	}

	if (SoundTime > 8.0f)
	{
		if (true == StateBool)
		{
			PlaywithinaplayLevel::LM->ChangeState(Chap1LevelState::CreateBoard);
			StateBool = false;
		}
	}

	if (SoundTime > 9.0f)
	{
		static bool Play4 = true;
		if (true == Play4)
		{
			Sound = Play(Sound, "Chap01Intro04.wav", 0.1f);
			Play4 = false;
		}
		Font4 = NFontCreate(Font4, "����� �����?", GetTransform(), 2.0f);
	}

	if (SoundTime > 11.0f)
	{
		static bool Play5 = true;
		if (true == Play5)
		{
			Sound = Play(Sound, "Chap01Intro05.wav", 0.1f);
			Play5 = false;
		}
		Font5 = NFontCreate(Font5, "��... ���� �ִ�!", GetTransform(), 2.0f);
	}

	if (SoundTime > 15.0f)
	{
		static bool Play6 = true;
		if (true == Play6)
		{
			Sound = Play(Sound, "Chap01Intro06.wav", 0.1f);
			Play6 = false;
		}
		Font6 = NFontCreate(Font6, "������ ����� �� �߳�.", GetTransform(), 2.0f);
	}

	if (SoundTime > 17.0f)
	{
		static bool Play7 = true;
		if (true == Play7)
		{
			Sound = Play(Sound, "IronTitleDown.wav", 0.1f); 
			Play7 = false;
		}
	}

	if (SoundTime > 19.0f)
	{
		static bool Play8 = true;
		if (true == Play8)
		{
			Sound = Play(Sound, "Chap01Intro06b.wav", 0.1f);
			Play8 = false;
		}
		Font7 = NFontCreate(Font7, "�������� ����. �������� ����...", GetTransform(), 2.0f);
	}
}

