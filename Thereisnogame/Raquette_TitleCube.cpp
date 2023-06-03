#include "PrecompileHeader.h"
#include "Raquette_TitleCube.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

Raquette_TitleCube::Raquette_TitleCube()
{
}

Raquette_TitleCube::~Raquette_TitleCube()
{
}

void Raquette_TitleCube::Start()
{
	Raquette_TitleCubes = Init(Raquette_TitleCubes, "Raquette.png", { 101,64 }, { 0,0,0 });

	Raquette_TitleCubesCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::Excla);
	Raquette_TitleCubesCollision->GetTransform()->SetLocalScale({ 101,64 });
	Raquette_TitleCubesCollision->GetTransform()->SetLocalPosition({ 0,0,0 });
	Raquette_TitleCubesCollision->Off();
}

void Raquette_TitleCube::Update(float _DeltaTime)
{
	
}

void Raquette_TitleCube::Render(float _Delta)
{

};



