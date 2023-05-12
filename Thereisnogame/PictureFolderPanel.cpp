#include "PrecompileHeader.h"
#include "PictureFolderPanel.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "BoxCroix.h"


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


	//아직 Depth조절이 안된듯
	Croix = GetLevel()->CreateActor<BoxCroix>();
	Croix->SetPosition({ 65,95,-1 });
}

void PictureFolderPanel::Update(float _DeltaTime)
{

}

void PictureFolderPanel::Render(float _Delta)
{

};
