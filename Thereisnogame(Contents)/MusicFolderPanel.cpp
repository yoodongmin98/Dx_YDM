#include "PrecompileHeader.h"
#include "MusicFolderPanel.h"
#include "ActorTypeEnum.h"
//PlatForm
//Core
//Actor



MusicFolderPanel::MusicFolderPanel()
{
}

MusicFolderPanel::~MusicFolderPanel()
{
}

void MusicFolderPanel::Start()
{
	Init(MusicTopFolderPanels, "Panel03.png", { 329,73 }, { -344,122,0 });
	MusicFolderPanels=Init(MusicFolderPanels, "Panel01.png", { 388,415 }, { -315,-90,0 });	
}

void MusicFolderPanel::Update(float _DeltaTime)
{

}

void MusicFolderPanel::Render(float _Delta)
{

};


