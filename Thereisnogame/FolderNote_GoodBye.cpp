#include "PrecompileHeader.h"
#include "FolderNote_GoodBye.h"

//PlatForm
//Core
//Actor



FolderNote_GoodBye::FolderNote_GoodBye()
{
}

FolderNote_GoodBye::~FolderNote_GoodBye()
{
}

void FolderNote_GoodBye::Start()
{
	Init(FolderNote_GoodByes, "BlocNote.png", { 831,612 }, { 0,-65 });

	Font1 = FontCreate(Font1, 28, "게임, 나 떠나야 해.\n미안.", { -370,-50 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 28, "지지", { -370,-170 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);
}

void FolderNote_GoodBye::Update(float _DeltaTime)
{

}

void FolderNote_GoodBye::Render(float _Delta)
{

};
