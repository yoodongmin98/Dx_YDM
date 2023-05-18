#include "PrecompileHeader.h"
#include "MusicNote_Walnut.h"

//PlatForm
//Core

MusicNote_Walnut::MusicNote_Walnut()
{
}

MusicNote_Walnut::~MusicNote_Walnut()
{
}

void MusicNote_Walnut::Start()
{
	Init(MusicNote_Walnuts, "Note.png", { 100,110 }, { -400,30,0 });
	MusicNote_WalnutsCollision = CollisionInit(MusicNote_WalnutsCollision, { 100,110 }, { -400,30,0 });
}

void MusicNote_Walnut::Update(float _DeltaTime)
{

}

void MusicNote_Walnut::Render(float _Delta)
{

};
