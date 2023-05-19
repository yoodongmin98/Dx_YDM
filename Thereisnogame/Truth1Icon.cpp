#include "PrecompileHeader.h"
#include "Truth1Icon.h"

//PlatForm
//Core

 
 
//Actor
#include "ColManager.h"



Truth1Icon::Truth1Icon()
{
}

Truth1Icon::~Truth1Icon()
{
}

void Truth1Icon::Start()
{
	//ScaleÁ¶Á¤
	Truth1Icons=Init(Truth1Icons, "Document.png", { 75,93 }, {-100,20});
	Truth1IconsCollision = CollisionInit(Truth1IconsCollision, { 75,93,1 }, { -100,20 });
}

void Truth1Icon::Update(float _DeltaTime)
{
	ManagedCollision(Truth1IconsCollision, 1);
	if (true == ClickCheck(Truth1IconsCollision))
	{
		//ColManager::MG->PlusCollisionValue();
		//CreateFolderNote
	}
}

void Truth1Icon::Render(float _Delta)
{

};
