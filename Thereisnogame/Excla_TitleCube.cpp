#include "PrecompileHeader.h"
#include "Excla_TitleCube.h"

//Base
//PlatForm
//Core


//Actor
#include "LevelStateManager.h"

Excla_TitleCube::Excla_TitleCube()
{
}

Excla_TitleCube::~Excla_TitleCube()
{
}

void Excla_TitleCube::Start()
{
	Excla_TitleCubes = Init(Excla_TitleCubes, "TitleCube_Excla.png", { 45,109 }, { 300,40,0 });
	Excla_TitleCubesCollision = CollisionInit(Excla_TitleCubesCollision, { 45,109 }, { 300,40,0 });
	Excla_TitleCubesCollision->Off();
}

void Excla_TitleCube::Update(float _DeltaTime)
{
	if (true == LevelStateManager::MG->GetIsBoardDown()
		&& true == UpdateBool)
	{
		UpdateBool = false;
		GetTransform()->SetLocalRotation({ 0,0,-30 });
		GetTransform()->AddLocalPosition({ 30,0,0 });
		Excla_TitleCubesCollision->On();
	}
}

void Excla_TitleCube::Render(float _Delta)
{

};


