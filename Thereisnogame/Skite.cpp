#include "PrecompileHeader.h"
#include "Skite.h"

//PlatForm
//Core

//Actor
#include "LevelStateManager.h"

Skite::Skite()
{
}

Skite::~Skite()
{
}

void Skite::Start()
{
	Init(Skites, "SkiteMain.png", { 357,501 }, { 300,0,0 });
	Font = FontCreate(Font, 30, "비어있음", { 335,30,0 }, GetTransform(), 2);
	Font2 = FontCreate(Font2, 25, "연락", { 335,105,0 }, GetTransform(), 2);
}

void Skite::Update(float _DeltaTime)
{
	if (true == LevelStateManager::MG->Get18OpenTrue())
	{
		Font->Death();
	}
}

void Skite::Render(float _Delta)
{

};
