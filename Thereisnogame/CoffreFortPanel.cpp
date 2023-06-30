#include "PrecompileHeader.h"
#include "CoffreFortPanel.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
//Actor
#include "LevelStateManager.h"

CoffreFortPanel::CoffreFortPanel()
{
}

CoffreFortPanel::~CoffreFortPanel()
{
}

void CoffreFortPanel::Start()
{
	CoffreFortPanels = Init(CoffreFortPanels, "CoffreFortPanel.png", { 390,285 }, float4::Zero + float4::Right * 64);
	CoffreFortPanelsColliision = CollisionInit(CoffreFortPanelsColliision, { 80,150 }, float4::Right * 210);

	
	PanelCogCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::PanelCog);
	PanelCogCollision->GetTransform()->SetLocalScale({ 19,18 });
	PanelCogCollision->GetTransform()->SetLocalPosition(float4::Zero);
	
	PanelRouageCollision = CreateComponent<GameEngineCollision>(ActorTypeEnum::PanelRouge);
	PanelRouageCollision->GetTransform()->SetLocalScale({11,11});
	PanelRouageCollision->GetTransform()->SetLocalPosition(float4::Zero);

	CogRender = Init(CogRender, "Cog_OBJ.png", { 190,184 }, float4::Zero);
	RougeRender = Init(RougeRender, "RouageLoad.png", { 109,109 }, float4::Zero);
	CogRender->Off();
	RougeRender->Off();
}

void CoffreFortPanel::Update(float _DeltaTime)
{
	PanelInterCheck(_DeltaTime);
	RenderOnCheck();
}

void CoffreFortPanel::Render(float _Delta)
{

};


void CoffreFortPanel::PanelInterCheck(float _DeltaTime)
{
	PanelTime += _DeltaTime;
	if (true == ClickCheck(CoffreFortPanelsColliision))
	{
		PanelOpen = !PanelOpen;
		PanelTime = 0.0f;
		StartPosX = CoffreFortPanels->GetTransform()->GetLocalPosition();
		CogValue = { 17,45 };
		RougeValue = {-57,-63};
	}
	if (true == PanelOpen)
	{
		CoffreFortPanelsColliision->GetTransform()->SetLocalPosition({ 496,0,0 });
		EndPosX = { 350,0,0 };
		CoffreFortPanels->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX, EndPosX, PanelTime * 1.5f));
		CogRender->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX+ CogValue, EndPosX + CogValue, PanelTime * 1.5f));
		PanelCogCollision->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX + CogValue, EndPosX + CogValue, PanelTime * 1.5f));
		RougeRender->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX+ RougeValue, EndPosX + RougeValue, PanelTime * 1.5f));
		PanelRouageCollision->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX + RougeValue, EndPosX + RougeValue, PanelTime * 1.5f));
	}
	else
	{
		CoffreFortPanelsColliision->GetTransform()->SetLocalPosition({ 210,0,0 });
		EndPosX = {64,0,0};
		CoffreFortPanels->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX, EndPosX, PanelTime*1.5f));
		CogRender->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX + CogValue, EndPosX + CogValue, PanelTime * 1.5f));
		PanelCogCollision->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX + CogValue, EndPosX + CogValue, PanelTime * 1.5f));
		RougeRender->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX + RougeValue, EndPosX + RougeValue, PanelTime * 1.5f));
		PanelRouageCollision->GetTransform()->SetLocalPosition(float4::LerpClamp(StartPosX + RougeValue, EndPosX + RougeValue, PanelTime * 1.5f));
	}
}

void CoffreFortPanel::RenderOnCheck()
{
	if (true == CogOnBool && LevelStateManager::MG->GetIsCogStick())
	{
		CogRender->On();
		CogOnBool = false;
	}
	if (true == RougeOnBool && LevelStateManager::MG->GetIsRougeStick())
	{
		RougeRender->On();
		RougeOnBool = false;
	}
}
