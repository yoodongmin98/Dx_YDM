#include "PrecompileHeader.h"
#include "TrashcanFolder.h"

//PlatForm
//Core



TrashcanFolder::TrashcanFolder()
{
}

TrashcanFolder::~TrashcanFolder()
{
}

void TrashcanFolder::Start()
{
	Init(TrashcanFolders, "IconRubbish.png", { 63,84 }, { 420,-200,0 });
}

void TrashcanFolder::Update(float _DeltaTime)
{
	//ManagedCollision(SkiteFoldersCollision, 0);

}

void TrashcanFolder::Render(float _Delta)
{

};
