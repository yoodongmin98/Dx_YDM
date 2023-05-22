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
	if (0 > CollisionValue || NextCollisionValue < 0)
	{
		MsgAssert("Collision Value�� �������Ǿ����ϴ�. �������� �Ѱ̴ϱ�");
	}
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
