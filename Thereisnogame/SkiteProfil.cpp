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

	Font1 = FontCreate(Font1, 28, "나아님\n프로필", { -310,130 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 25, "직업: 은퇴한 프로그램", { -450,30 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);
	Font3 = FontCreate(Font3, 25, "좋아하는것: 나무, 연 그리고 숫자 50", { -450,-40 }, GetTransform(), 2);
	Font3->SetFontFlag(FW1_LEFT);
	Font4 = FontCreate(Font4, 25, "싫어하는 것: 버그와 염소!", { -450,-120 }, GetTransform(), 2);
	Font4->SetFontFlag(FW1_LEFT);
	Font5 = FontCreate(Font5, 25, "좋아하는 음식: CPU.", { -450,-190 }, GetTransform(), 2);
	Font5->SetFontFlag(FW1_LEFT);
}

void SkiteProfil::Update(float _DeltaTime)
{

}

void SkiteProfil::Render(float _Delta)
{

};
