#include "PrecompileHeader.h"
#include "FolderNote_Password.h"

//PlatForm
//Core
//Actor



FolderNote_Password::FolderNote_Password()
{
}

FolderNote_Password::~FolderNote_Password()
{
}

void FolderNote_Password::Start()
{
	Init(FolderNote_Passwords, "BlocNote.png", { 831,612 }, { 0,-65 });

	Font1 = FontCreate(Font1, 28, "������ ��й�ȣ�� �ؾ���ȴٸ�, �� ������� �Է�����:", { -370,0 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 28, "1) �� ID ī�忡 �ִ� �̻��� ����.\n2) ���� ���� �����ϴ� ����.\n3) �̽� ������ ��й�ȣ.", { -370,-100 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);

}

void FolderNote_Password::Update(float _DeltaTime)
{

}

void FolderNote_Password::Render(float _Delta)
{

};
