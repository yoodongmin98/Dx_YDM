#include "PrecompileHeader.h"
#include "PrivatePanel_Ultra.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix_Music.h"


PrivatePanel_Ultra::PrivatePanel_Ultra()
{
}

PrivatePanel_Ultra::~PrivatePanel_Ultra()
{
}

void PrivatePanel_Ultra::Start()
{
	PrivateTopPanels = Init(PrivateTopPanels, "Panel03.png", { 329,73 }, { -170,95,0 });
	PrivatePanel_Ultras = Init(PrivatePanel_Ultras, "Panel01.png", { 380,310 }, { -145,-70,0 });
}

void PrivatePanel_Ultra::Update(float _DeltaTime)
{

}

void PrivatePanel_Ultra::Render(float _Delta)
{

};
