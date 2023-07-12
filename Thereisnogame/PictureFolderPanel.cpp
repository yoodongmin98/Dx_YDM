#include "PrecompileHeader.h"
#include "PictureFolderPanel.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix_Music.h"


PictureFolderPanel::PictureFolderPanel()
{
}

PictureFolderPanel::~PictureFolderPanel()
{
}

void PictureFolderPanel::Start()
{
	Init(PictureTopFolderPanels, "Panel03.png", { 329,73 }, { -270,115,0 });
	PictureFolderPanels = Init(PictureFolderPanels, "Panel01.png", { 550,305 }, { -160,-50,0 });
	Font = FontCreate(Font, 30, "����", { -390,140,0 }, GetTransform(), 2);
}

void PictureFolderPanel::Update(float _DeltaTime)
{

}

void PictureFolderPanel::Render(float _Delta)
{

};
