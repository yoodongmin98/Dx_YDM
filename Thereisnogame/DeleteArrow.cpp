#include "PrecompileHeader.h"
#include "DeleteArrow.h"
//PlatForm
//Core


DeleteArrow::DeleteArrow()
{
}

DeleteArrow::~DeleteArrow()
{
}


void DeleteArrow::Start()
{
	Arrow1 = Init(Arrow1, "ArrowLightOff.png", { 376 * 0.5f,145 * 0.5f }, { -150,-100 });
	Arrow1->GetTransform()->SetLocalRotation({0,0,-40});
	Arrow1->Off();
	Arrow2 = Init(Arrow2, "ArrowLightOff.png", { 376 * 0.6f,145 * 0.6f }, { -250,-140 });
	Arrow2->GetTransform()->SetLocalRotation({ 0,0,-30 });
	Arrow2->Off();
	Arrow3 = Init(Arrow3, "ArrowLightOff.png", { 376 * 0.7f,145 * 0.7f }, { -230,-250 });
	Arrow3->Off();
	Arrow4 = Init(Arrow4, "ArrowLightOff.png", { 376 * 0.7f,145 * 0.7f }, { -210,-370 });
	Arrow4->GetTransform()->SetLocalRotation({ 0,0,30 });
	Arrow4->Off();
}

void DeleteArrow::Update(float _DeltaTime)
{
	if (GetLiveTime() > 0.1f)
	{
		static bool Arrows1 = true;
		if (true == Arrows1)
		{
			Play(Sound, "End_Pop02.wav", 0.1f);
			Arrow2->On();
			Arrows1 = false;
		}
		
	}
	if (GetLiveTime() > 0.2f)
	{
		static bool Arrows2 = true;
		if (true == Arrows2)
		{
			Play(Sound, "End_Pop02.wav", 0.1f);
			Arrow4->On();
			Arrows2 = false;
		}
	}
	if (GetLiveTime() > 0.3f)
	{
		static bool Arrows3 = true;
		if (true == Arrows3)
		{
			Play(Sound, "End_Pop02.wav", 0.1f);
			Arrow3->On();
			Arrows3 = false;
		}
	}
	if (GetLiveTime() > 0.4f)
	{
		static bool Arrows4 = true;
		if (true == Arrows4)
		{
			Play(Sound, "End_Pop02.wav", 0.1f);
			Arrow1->On();
			Arrows4 = false;
		}
	}
}

void DeleteArrow::Render(float _Delta)
{

};


