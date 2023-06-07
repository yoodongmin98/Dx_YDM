#include "PrecompileHeader.h"
#include "R_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


R_TitleMetal::R_TitleMetal()
{
}

R_TitleMetal::~R_TitleMetal()
{

}

void R_TitleMetal::Start()
{
	R_TitleMetals = Init(R_TitleMetals, "TitleMetal_R.png", { 102,138 }, { -30,230,0 });
	R_TitleMetalsCollision = BlockCollisionInit(R_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void R_TitleMetal::Update(float _DeltaTime)
{

}

void R_TitleMetal::Render(float _Delta)
{

};


