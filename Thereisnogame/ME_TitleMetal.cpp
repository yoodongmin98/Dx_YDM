#include "PrecompileHeader.h"
#include "ME_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


ME_TitleMetal::ME_TitleMetal()
{
}

ME_TitleMetal::~ME_TitleMetal()
{

}

void ME_TitleMetal::Start()
{
	ME_TitleMetals = Init(ME_TitleMetals, "TitleMetal_E.png", { 99,138 }, { 270,80,0 });
	ME_TitleMetalsCollision = BlockCollisionInit(ME_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void ME_TitleMetal::Update(float _DeltaTime)
{

}

void ME_TitleMetal::Render(float _Delta)
{

};


