#include "PrecompileHeader.h"
#include "F_Chinese.h"

F_Chinese::F_Chinese()
{
}

F_Chinese::~F_Chinese()
{
}

void F_Chinese::Start()
{
	Init(F_Chineses, "Flag_Chinese.png", { 198,727,1 }, { 330,750,0 });//-30
	F_ChinesesCollision = CollisionInit(F_ChinesesCollision, { 198,133,1 }, { 330,550,0 });
	Play(Sound, "MainMenu_LanguageIn.wav", 0.1f);
}

void F_Chinese::Update(float _DeltaTime)
{
	Repeat(6, _DeltaTime * 0.5f);
}

void F_Chinese::Render(float _Delta)
{

};
