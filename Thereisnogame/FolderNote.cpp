#include "PrecompileHeader.h"
#include "FolderNote.h"

//PlatForm
//Core
//Actor



FolderNote::FolderNote()
{
}

FolderNote::~FolderNote()
{
}

void FolderNote::Start()
{
	Init(FolderNotes, "BlocNote.png", { 831,612 }, {0,-65});

	Font1 = FontCreate(Font1, 28, "로스웰에 대한 진실", { -370,100 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 28, "안녕하세요,", { -370,0 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);
	Font3 = FontCreate(Font3, 28, "기술적 문제로 인해, 이 문서의 내용이 사라졌습니다. 죄송", { -370,-50 }, GetTransform(), 2);
	Font3->SetFontFlag(FW1_LEFT);
	Font4 = FontCreate(Font4, 28, "합니다.\n\nFBI.", { -370,-100 }, GetTransform(), 2);
	Font4->SetFontFlag(FW1_LEFT);
	Font5 = FontCreate(Font5, 28, "PS: 아, 그리고UFO가 아니라 기상관측 기구였어요.", { -370,-220 }, GetTransform(), 2);
	Font5->SetFontFlag(FW1_LEFT);
}

void FolderNote::Update(float _DeltaTime)
{

}

void FolderNote::Render(float _Delta)
{

};
