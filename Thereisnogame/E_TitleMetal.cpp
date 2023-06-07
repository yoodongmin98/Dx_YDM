#include "PrecompileHeader.h"
#include "E_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


E_TitleMetal::E_TitleMetal()
{
}

E_TitleMetal::~E_TitleMetal()
{

}

void E_TitleMetal::Start()
{
	E_TitleMetals = Init(E_TitleMetals, "TitleMetal_E.png", { 99,138 }, { -120,230,0 });
	E_TitleMetalsCollision = BlockCollisionInit(E_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void E_TitleMetal::Update(float _DeltaTime)
{

}

void E_TitleMetal::Render(float _Delta)
{

};


