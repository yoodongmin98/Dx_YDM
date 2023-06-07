#include "PrecompileHeader.h"
#include "H_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


H_TitleMetal::H_TitleMetal()
{
}

H_TitleMetal::~H_TitleMetal()
{

}

void H_TitleMetal::Start()
{
	H_TitleMetals = Init(H_TitleMetals, "TitleMetal_H.png", { 102,138 }, { -210,230,0 });
	H_TitleMetalsCollision = BlockCollisionInit(H_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void H_TitleMetal::Update(float _DeltaTime)
{

}

void H_TitleMetal::Render(float _Delta)
{

};


