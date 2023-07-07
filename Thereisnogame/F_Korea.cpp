#include "PrecompileHeader.h"
#include "F_Korea.h"
#include "MainMenuLevel.h"

F_Korea::F_Korea()
{
}

F_Korea::~F_Korea()
{
}

void F_Korea::Start()
{
	F_Koreas=Init(F_Koreas, "Flag_Korea.png", { 198,727,1 }, { 330,750,0 });//400
	F_KoreasCollision = CollisionInit(F_KoreasCollision, { 198,133,1 }, { 330,550,0 });
}

void F_Korea::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.7f);
	if (true == ClickCheck(F_KoreasCollision))
	{
		Play(Sound, "MainMenu_Click.wav", 0.1f);
		MainMenuLevel::ML->SetIsClicktheFlagTrue();
	}
}

void F_Korea::Render(float _Delta)
{

};
