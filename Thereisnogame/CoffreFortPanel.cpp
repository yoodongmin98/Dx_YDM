#include "PrecompileHeader.h"
#include "CoffreFortPanel.h"
//Base
//PlatForm
//Core
//Actor
CoffreFortPanel::CoffreFortPanel()
{
}

CoffreFortPanel::~CoffreFortPanel()
{
}

void CoffreFortPanel::Start()
{
	CoffreFortPanels = Init(CoffreFortPanels, "CoffreFortPanel.png", { 390,285 }, float4::Zero);
}

void CoffreFortPanel::Update(float _DeltaTime)
{

}

void CoffreFortPanel::Render(float _Delta)
{

};

