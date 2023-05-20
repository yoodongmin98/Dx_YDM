#include "PrecompileHeader.h"
#include "PrivatePanel_Miss.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix_Music.h"


PrivatePanel_Miss::PrivatePanel_Miss()
{
}

PrivatePanel_Miss::~PrivatePanel_Miss()
{
}

void PrivatePanel_Miss::Start()
{
	PrivateTopPanels = Init(PrivateTopPanels, "Panel03.png", { 329,73 }, { -80,95,0 });
	PrivatePanel_Misss = Init(PrivatePanel_Misss, "Panel01.png", { 560,310 }, { 35,-70,0 });
}

void PrivatePanel_Miss::Update(float _DeltaTime)
{

}

void PrivatePanel_Miss::Render(float _Delta)
{

};
