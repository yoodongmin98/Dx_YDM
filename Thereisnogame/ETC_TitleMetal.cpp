#include "PrecompileHeader.h"
#include "ETC_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


ETC_TitleMetal::ETC_TitleMetal()
{
}

ETC_TitleMetal::~ETC_TitleMetal()
{

}

void ETC_TitleMetal::Start()
{
	ETC_TitleMetals = Init(ETC_TitleMetals, "TitleMetal_T.png", { 94,142 }, { -300,140,0 });
	ETC_TitleMetalsCollision = BlockCollisionInit(ETC_TitleMetalsCollision, { 94,142 }, { -300,140,0 }); 
}

void ETC_TitleMetal::Update(float _DeltaTime)
{

}

void ETC_TitleMetal::Render(float _Delta)
{

};


