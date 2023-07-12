#include "PrecompileHeader.h"
#include "FolderNote2.h"

//PlatForm
//Core
//Actor



FolderNote2::FolderNote2()
{
}

FolderNote2::~FolderNote2()
{
}

void FolderNote2::Start()
{
	Init(FolderNote2s, "BlocNote.png", { 831,612 }, { 0,-65 });

	Font1 = FontCreate(Font1, 28, "�ɳ׵��� ������ ���� ����", { -370,100 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 28, "�ȳ��ϼ���,", { -370,0 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);
	Font3 = FontCreate(Font3, 28, "����� ������ ����, �� ������ ������ ��������ϴ�. �˼�", { -370,-50 }, GetTransform(), 2);
	Font3->SetFontFlag(FW1_LEFT);
	Font4 = FontCreate(Font4, 28, "�մϴ�.\n\nFBI.", { -370,-100 }, GetTransform(), 2);
	Font4->SetFontFlag(FW1_LEFT);
	Font5 = FontCreate(Font5, 28, "PS: �ϻ��ڴ� ������ �ⱸ�����ϴ�.", { -370,-220 }, GetTransform(), 2);
	Font5->SetFontFlag(FW1_LEFT);
}

void FolderNote2::Update(float _DeltaTime)
{

}

void FolderNote2::Render(float _Delta)
{

};
