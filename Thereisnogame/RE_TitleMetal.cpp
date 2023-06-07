#include "PrecompileHeader.h"
#include "RE_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


RE_TitleMetal::RE_TitleMetal()
{
}

RE_TitleMetal::~RE_TitleMetal()
{

}

void RE_TitleMetal::Start()
{
	RE_TitleMetals = Init(RE_TitleMetals, "TitleMetal_E.png", { 99,138 }, { 60,230,0 });
	RE_TitleMetalsCollision = BlockCollisionInit(RE_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void RE_TitleMetal::Update(float _DeltaTime)
{

}

void RE_TitleMetal::Render(float _Delta)
{

};


