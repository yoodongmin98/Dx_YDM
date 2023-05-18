#include "PrecompileHeader.h"
#include "BoxCroix.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core

BoxCroix::BoxCroix()
{

}

BoxCroix::~BoxCroix()
{
}

void BoxCroix::Start()
{
	Init(BoxCroixs, "BoxCroix.png", { 48,54 }, { -158,110,0 });
	BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54,1 }, { -158,110,0 });
}

void BoxCroix::Update(float _DeltaTime)
{
	//¿©±â
	if (true == ClickCheck(BoxCroixsCollision))
	{
		int a = 0;
		MusicFolderPanels.get()
		//MusicNote_Archives;
		//MusicNote_Radios;
		//MusicNote_Rains;
		//MusicNote_Walnuts;
		//MediaPlayers;
		//MediaPlays;
		//MediaPauses;
		//MediaPictures;
	}
}

void BoxCroix::Render(float _Delta)
{

};
