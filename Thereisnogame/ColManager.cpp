#include "PrecompileHeader.h"
#include "ColManager.h"

//PlatForm
//Core
//Actor

ColManager* ColManager::MG;

ColManager::ColManager()
{
	MG = this;
}

ColManager::~ColManager()
{
}

void ColManager::Start()
{

}

void ColManager::Update(float _DeltaTime)
{
	CollisionValue = NextCollisionValue; //클릭했을때 한 프레임을 벌기위해서 Order를 뒤로미루고,맨 마지막에 update
}

void ColManager::PlusCollisionValue()
{
	NextCollisionValue = CollisionValue + 1;
}

void ColManager::MinusCollisionValue()
{
	NextCollisionValue = CollisionValue - 1;
}
