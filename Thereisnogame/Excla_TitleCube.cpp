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
	ProgressCheck();
}

void Excla_TitleCube::Render(float _Delta)
{

};

void Excla_TitleCube::ProgressCheck()
{
	if (true == LevelStateManager::MG->GetIsBoardDown()
		&& true == UpdateBool)
	{
		UpdateBool = false;
		Excla_TitleCubesCollision->On();
	}
	if (true == ClickCheck(Excla_TitleCubesCollision))
	{
		++ExclaClickCount;
		if (ExclaClickCount > 4)
		{
			Excla_TitleCubesCollision->Death();
			// 화면 밖으로나가면 밑판Create하고나서 Death
		}
	}
}


