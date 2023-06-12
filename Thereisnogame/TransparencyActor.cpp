#include "PrecompileHeader.h"
#include "TransparencyActor.h"

//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineSpriteRenderer.h>

//Actor
#include "BackCurtain.h"
#include "Play within a play Level.h"

TransparencyActor::TransparencyActor()
{
}

TransparencyActor::~TransparencyActor()
{
}

void TransparencyActor::Start()
{
	TransparencyActors = Init(TransparencyActors, "Chap04_ArrowLeft.png", { 100,100,1 }, { -600,100,0 });
}

void TransparencyActor::Update(float _DeltaTime)
{

}
void TransparencyActor::Render(float _Delta)
{

};


