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

	Font1 = FontCreate(Font1, 28, "쓰레기통", { -355,140 }, GetTransform(), 2);
	Font2 = FontCreate(Font2, 25, "WORST\nPINBALL\nEVER,", { -330,-20 }, GetTransform(), 2);
	Font3 = FontCreate(Font3, 28, "비밀번호", { -175,-40 }, GetTransform(), 2);
	Font4 = FontCreate(Font4, 28, "안녕", { -15,-40 }, GetTransform(), 2);
	
}

void TrashCanFolderPanel::Update(float _DeltaTime)
{

}

void TrashCanFolderPanel::Render(float _Delta)
{

};
