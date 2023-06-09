#include "PrecompileHeader.h"
#include "PrivatePanel_Giga.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix_Music.h"


PrivatePanel_Giga::PrivatePanel_Giga()
{
}

PrivatePanel_Giga::~PrivatePanel_Giga()
{
}

void PrivatePanel_Giga::Start()
{
	PrivateTopPanels = Init(PrivateTopPanels, "Panel03.png", { 329,73 }, { -140,95,0 });
	PrivatePanel_Gigas = Init(PrivatePanel_Gigas, "Panel01.png", { 380,310 }, { -115,-70,0 });
}

void PrivatePanel_Giga::Update(float _DeltaTime)
{

}

void PrivatePanel_Giga::Render(float _Delta)
{

};
