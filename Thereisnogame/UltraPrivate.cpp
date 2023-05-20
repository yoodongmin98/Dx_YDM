#include "PrecompileHeader.h"
#include "UltraPrivate.h"

//PlatForm
//Core



UltraPrivate::UltraPrivate()
{
}

UltraPrivate::~UltraPrivate()
{
}

void UltraPrivate::Start()
{
	UltraPrivates = Init(UltraPrivates, "Folder.png", { 96,87 }, {-220,20});
	UltraPrivatesCollision = CollisionInit(UltraPrivatesCollision, { 96,87,1 }, { -220,20 });
}

void UltraPrivate::Update(float _DeltaTime)
{
	ManagedCollision(UltraPrivatesCollision, 2);
	if (true == ClickCheck(UltraPrivatesCollision))
	{
		//Create¾îÂ¼±¸ÀúÂ¼±¸
	}
}

void UltraPrivate::Render(float _Delta)
{

};
