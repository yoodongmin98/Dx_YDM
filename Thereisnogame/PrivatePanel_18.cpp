#include "PrecompileHeader.h"
#include "PrivatePanel_18.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix_Music.h"


PrivatePanel_18::PrivatePanel_18()
{
}

PrivatePanel_18::~PrivatePanel_18()
{
}

void PrivatePanel_18::Start()
{
	PrivateTopPanels = Init(PrivateTopPanels, "Panel03.png", { 329,73 }, { -80,95,0 });
	PrivatePanel_18s = Init(PrivatePanel_18s, "Panel01.png", { 380,310 }, { -55,-70,0 });
}

void PrivatePanel_18::Update(float _DeltaTime)
{

}

void PrivatePanel_18::Render(float _Delta)
{

};
