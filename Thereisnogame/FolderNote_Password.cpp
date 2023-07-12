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

	Font1 = FontCreate(Font1, 28, "관리자 비밀번호를 잊어버렸다면, 이 순서대로 입력하자:", { -370,0 }, GetTransform(), 2);
	Font1->SetFontFlag(FW1_LEFT);
	Font2 = FontCreate(Font2, 28, "1) 내 ID 카드에 있는 이상한 숫자.\n2) 내가 제일 좋아하는 숫자.\n3) 미스 도쿄의 비밀번호.", { -370,-100 }, GetTransform(), 2);
	Font2->SetFontFlag(FW1_LEFT);

}

void FolderNote_Password::Update(float _DeltaTime)
{

}

void FolderNote_Password::Render(float _Delta)
{

};
