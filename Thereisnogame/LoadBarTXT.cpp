#include "PrecompileHeader.h"
#include "LoadBarTXT.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core

//Actor
#include "G_RigidBody.h"

LoadBarTXT::LoadBarTXT()
{
}

LoadBarTXT::~LoadBarTXT()
{
}

void LoadBarTXT::Start()
{
	LoadBarTXTs = Init(LoadBarTXTs, "TourneVis00.png", { 105,156 }, { 0,0,0 });
	//LoadBarTXTs = Init(LoadBarTXTs, "LoadBarTXT.png", { 384,60 }, { 0,0,0 });
	LoadBarTXTsCollision = CollisionInit(LoadBarTXTsCollision, { 384,60 }, { 0,0,0 });
}

bool TestBool = true;
void LoadBarTXT::Update(float _DeltaTime)
{
	/*if (GetLiveTime() > 4.0f)*/
	{
		G_RigidBody* Rigids = GetRigidBody();
		Rigids->SetFrictionCoeff(0);
		if (GetLiveTime() < 0.1f)
		{
			Rigids->AddForce(float4::Up * 30);
		}
		
		if (GetLiveTime() > 0.1f)
		{
			Rigids->AddForce(float4::Down * 50);
		}
		
		if (GetTransform()->GetLocalPosition().y > -GameEngineWindow::GetScreenSize().half().y + 30)
		{
			Rigids->RigidBodyUpdate();
		}
		
	}
}

void LoadBarTXT::Render(float _Delta)
{

};

