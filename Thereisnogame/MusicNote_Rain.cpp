#include "PrecompileHeader.h"
#include "MusicNote_Rain.h"

//PlatForm
//Core




MusicNote_Rain::MusicNote_Rain()
{
}

MusicNote_Rain::~MusicNote_Rain()
{
}

void MusicNote_Rain::Start()
{
	Init(MusicNote_Rains, "Note.png", { 100,110 }, { -400,-150,0 });
	MusicNote_RainsCollision = CollisionInit(MusicNote_RainsCollision, { 100,110 }, { -400,-150,0 });
}

void MusicNote_Rain::Update(float _DeltaTime)
{

}

void MusicNote_Rain::Render(float _Delta)
{

};
