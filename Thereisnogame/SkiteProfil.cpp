#include "PrecompileHeader.h"
#include "SkiteProfil.h"

//PlatForm
//Core




SkiteProfil::SkiteProfil()
{
}

SkiteProfil::~SkiteProfil()
{
}

void SkiteProfil::Start()
{
	Init(SkiteProfils, "SkiteProfil.png", { 699,530 }, { -140,-50 });

	Font1 = FontCreate(Font1, 28, "���ƴ�\n������", { -310,130 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 25, "����: ������ ���α׷�", { -450,30 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);
	Font3 = FontCreate(Font3, 25, "�����ϴ°�: ����, �� �׸��� ���� 50", { -450,-40 }, GetTransform(), 2);
	Font3->SetFontFlag(FW1_LEFT);
	Font4 = FontCreate(Font4, 25, "�Ⱦ��ϴ� ��: ���׿� ����!", { -450,-120 }, GetTransform(), 2);
	Font4->SetFontFlag(FW1_LEFT);
	Font5 = FontCreate(Font5, 25, "�����ϴ� ����: CPU.", { -450,-190 }, GetTransform(), 2);
	Font5->SetFontFlag(FW1_LEFT);
}

void SkiteProfil::Update(float _DeltaTime)
{

}

void SkiteProfil::Render(float _Delta)
{

};
