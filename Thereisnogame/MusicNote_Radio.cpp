#include "PrecompileHeader.h"
#include "MusicNote_Radio.h"

//PlatForm
//Core




MusicNote_Radio::MusicNote_Radio()
{
}

MusicNote_Radio::~MusicNote_Radio()
{
}

void MusicNote_Radio::Start()
{
	Init(MusicNote_Radios, "Note.png", { 100,110 }, { -245,-150,0 });
	MusicNote_RadiosCollision = CollisionInit(MusicNote_RadiosCollision, { 100,110 }, { -245,-150,0 });
}

void MusicNote_Radio::Update(float _DeltaTime)
{

}

void MusicNote_Radio::Render(float _Delta)
{

};
