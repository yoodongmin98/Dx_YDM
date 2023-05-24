#include "PrecompileHeader.h"
#include "LevelStateManager.h"

//PlatForm
//Core
//Actor

LevelStateManager* LevelStateManager::MG;

LevelStateManager::LevelStateManager()
{
	MG = this;
}

LevelStateManager::~LevelStateManager()
{
}

void LevelStateManager::Start()
{

}

void LevelStateManager::Update(float _DeltaTime)
{
	if (0 > CollisionValue || NextCollisionValue < 0)
	{
		MsgAssert("Collision Value가 음수가되었습니다. 무슨짓을 한겁니까");
	}
	CollisionValue = NextCollisionValue; //클릭했을때 한 프레임을 벌기위해서 Order를 뒤로미루고,맨 마지막에 update
}

void LevelStateManager::PlusCollisionValue()
{
	NextCollisionValue = CollisionValue + 1;
}

void LevelStateManager::MinusCollisionValue()
{
	NextCollisionValue = CollisionValue - 1;
}
