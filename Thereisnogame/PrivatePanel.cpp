#include "PrecompileHeader.h"
#include "PrivatePanel.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix_Music.h"


PrivatePanel::PrivatePanel()
{
}

PrivatePanel::~PrivatePanel()
{
}

void PrivatePanel::Start()
{
	//Scale¡∂¡§
	Init(PrivateTopPanels, "Panel03.png", { 289,73 }, { -220,95,0 });
	PrivatePanels = Init(PrivatePanels, "Panel01.png", { 380,310 }, { -175,-70,0 });
}

void PrivatePanel::Update(float _DeltaTime)
{

}

void PrivatePanel::Render(float _Delta)
{

};
