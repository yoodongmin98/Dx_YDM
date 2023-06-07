#include "PrecompileHeader.h"
#include "G_TitleMetal.h"

//Base
//PlatForm
//Core


//Actor


G_TitleMetal::G_TitleMetal()
{
}

G_TitleMetal::~G_TitleMetal()
{

}

void G_TitleMetal::Start()
{
	G_TitleMetals = Init(G_TitleMetals, "TitleMetal_G.png", { 102,138 }, { -300,140,0 });
	G_TitleMetalsCollision = BlockCollisionInit(G_TitleMetalsCollision, { 94,142 }, { -300,140,0 });
}

void G_TitleMetal::Update(float _DeltaTime)
{

}

void G_TitleMetal::Render(float _Delta)
{

};


