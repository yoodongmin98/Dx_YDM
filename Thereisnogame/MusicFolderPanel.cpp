#include "PrecompileHeader.h"
#include "MusicFolderPanel.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix.h"


MusicFolderPanel::MusicFolderPanel()
{
}

MusicFolderPanel::~MusicFolderPanel()
{
}

void MusicFolderPanel::Start()
{
	Init(MusicTopFolderPanels, "Panel03.png", { 329,73 }, { -344,122,0 });
	Init(MusicFolderPanels, "Panel01.png", { 388,415 }, { -315,-90,0 });
	Croix=GetLevel()->CreateActor<BoxCroix>();
	//Croix->GetTransform()->SetLocalPosition({ -200, 0, -1 });
}

void MusicFolderPanel::Update(float _DeltaTime)
{

}

void MusicFolderPanel::Render(float _Delta)
{

};
