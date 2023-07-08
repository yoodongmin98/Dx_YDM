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
		MsgAssert("Collision Value�� �������Ǿ����ϴ�. �������� �Ѱ̴ϱ�");
	}
	CollisionValue = NextCollisionValue; //Ŭ�������� �� �������� �������ؼ� Order�� �ڷ� �̷Ｍ,�� �������� update(�ߺ�Ŭ������)
}

void LevelStateManager::PlusCollisionValue()
{
	NextCollisionValue = CollisionValue + 1;
}

void LevelStateManager::MinusCollisionValue()
{
	NextCollisionValue = CollisionValue - 1;
}

void LevelStateManager::LevelChangeStart()
{
	MG = this;
}
