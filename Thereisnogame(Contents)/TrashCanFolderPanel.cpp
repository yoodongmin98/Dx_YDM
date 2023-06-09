#include "PrecompileHeader.h"
#include "TrashCanFolderPanel.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix_Music.h"


TrashCanFolderPanel::TrashCanFolderPanel()
{
}

TrashCanFolderPanel::~TrashCanFolderPanel()
{
}

void TrashCanFolderPanel::Start()
{
	Init(TrashCanTopFolderPanels, "Panel03.png", { 329,93 }, { -270,112,0 });
	TrashCanFolderPanels = Init(TrashCanFolderPanels, "Panel01.png", { 550,305 }, { -160,-50,0 });
}

void TrashCanFolderPanel::Update(float _DeltaTime)
{

}

void TrashCanFolderPanel::Render(float _Delta)
{

};
