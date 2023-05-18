#include "PrecompileHeader.h"
#include "MusicNote_Archive.h"

//PlatForm
//Core




MusicNote_Archive::MusicNote_Archive()
{
}

MusicNote_Archive::~MusicNote_Archive()
{
}

void MusicNote_Archive::Start()
{
	Init(MusicNote_Archives, "Note.png", { 100,110 }, { -245,30,0 });
	MusicNote_ArchivesCollision = CollisionInit(MusicNote_ArchivesCollision, { 100,110 }, { -245,30,0 });
}

void MusicNote_Archive::Update(float _DeltaTime)
{

}

void MusicNote_Archive::Render(float _Delta)
{

};
