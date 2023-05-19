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
	
}

void ColManager::PlusCollisionValue()
{
	CollisionValue += 1;
}

void ColManager::MinusCollisionValue()
{
	CollisionValue -= 1;
}
