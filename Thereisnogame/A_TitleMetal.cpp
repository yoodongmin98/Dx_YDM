#include "PrecompileHeader.h"
#include "A_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


A_TitleMetal::A_TitleMetal()
{
}

A_TitleMetal::~A_TitleMetal()
{

}

void A_TitleMetal::Start()
{
	A_TitleMetals = Init(A_TitleMetals, "TitleMetal_A.png", { 120,138 }, { -300,140,0 });
	A_TitleMetalsCollision = BlockCollisionInit(A_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void A_TitleMetal::Update(float _DeltaTime)
{

}

void A_TitleMetal::Render(float _Delta)
{

};


