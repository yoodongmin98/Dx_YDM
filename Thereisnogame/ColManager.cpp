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
	CollisionValue = NextCollisionValue; //Ŭ�������� �� �������� �������ؼ� Order�� �ڷι̷��,�� �������� update
}

void ColManager::PlusCollisionValue()
{
	NextCollisionValue = CollisionValue + 1;
}

void ColManager::MinusCollisionValue()
{
	NextCollisionValue = CollisionValue - 1;
}
