#include "PrecompileHeader.h"
#include "FolderNote3.h"

//PlatForm
//Core
 
//Actor
#include "LevelStateManager.h"


FolderNote3::FolderNote3()
{
}

FolderNote3::~FolderNote3()
{
}

void FolderNote3::Start()
{
	Init(FolderNote3s, "BlocNote.png", { 831,612 }, { 0,-65 });

	Font1 = FontCreate(Font1, 28, "������ 11ȣ�� ���� ����", { -370,100 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 28, "�ȳ��ϼ���,", { -370,-50 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);
	Font3 = FontCreate(Font3, 28, "������ �ⱸ�Դϴ�.\n\nFBI.", { -370,-100 }, GetTransform(), 2);
	Font3->SetFontFlag(FW1_LEFT);
	
}

void FolderNote3::Update(float _DeltaTime)
{

}

void FolderNote3::Render(float _Delta)
{

};
