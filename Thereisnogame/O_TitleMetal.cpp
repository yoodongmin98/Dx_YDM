#include "PrecompileHeader.h"
#include "O_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


O_TitleMetal::O_TitleMetal()
{
}

O_TitleMetal::~O_TitleMetal()
{

}

void O_TitleMetal::Start()
{
	O_TitleMetals = Init(O_TitleMetals, "TitleMetal_O.png", { 102,138 }, { -300,140,0 });
	O_TitleMetalsCollision = BlockCollisionInit(O_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void O_TitleMetal::Update(float _DeltaTime)
{

}

void O_TitleMetal::Render(float _Delta)
{

};


