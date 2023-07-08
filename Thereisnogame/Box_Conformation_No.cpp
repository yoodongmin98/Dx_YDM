#include "PrecompileHeader.h"
#include "Box_Conformation_No.h"

//PlatForm
//Core
//Actor
#include "LevelStateManager.h"

Box_Conformation_No::Box_Conformation_No()
{
}

Box_Conformation_No::~Box_Conformation_No()
{
}

void Box_Conformation_No::Start()
{
	float4 Position = { 230,-300,0 };
	Boxs = Init(Boxs, "MenuOptions_Confirmation_No.png", { 273 * 0.7f,309 * 0.7f,1 }, Position);
	BoxsCollision = CollisionInit(BoxsCollision, { 150,50,1 }, Position + float4::Up * 60);
}

void Box_Conformation_No::Update(float _DeltaTime)
{
	ManagedCollision(BoxsCollision, 1);
	if (true == ClickCheck(BoxsCollision))
	{
		Play(Sound, "MainMenu_Click.wav", 0.1f);
		BoxsCollision->Death();
		IsClick = true;
	}
	if (true == IsClick)
	{
		Boxs->GetTransform()->AddLocalPosition({ 0,-500 * _DeltaTime,0 });
		if (Boxs->GetTransform()->GetLocalPosition().y < -800.0f)
		{
			LevelStateManager::MG->MinusCollisionValue();
			Death();
		}
	}
}

void Box_Conformation_No::Render(float _Delta)
{

};
