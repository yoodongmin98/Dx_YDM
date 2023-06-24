#include "PrecompileHeader.h"
#include "FlagPicture_Back.h"
//Base
//PlatForm
//Core
//Actor
FlagPicture::FlagPicture()
{
}

FlagPicture::~FlagPicture()
{
}

void FlagPicture::Start()
{
	F_Chinese = Init(F_Chinese, "Flag_Chinese.png", { 198,727 }, { -2560+330,-30 });
	F_French = Init(F_French, "Flag_French_With_Support.png", { 198,727 }, { -2560 + 50,30 });
	F_Japan = Init(F_Japan, "Flag_Japan.png", { 198,727 }, { -2560-340,-30 });
	F_Italian = Init(F_Italian, "Flag_Italian.png", { 198,727 }, { -2560 + 420,170 });
	F_German = Init(F_German, "Flag_German.png", { 198,727 }, { -2560 + 180,220 });
	F_Brazilian = Init(F_Brazilian, "Flag_Brazilian.png", { 198,727 }, { -2560-170,130 });
	F_Russian = Init(F_Russian, "Flag_Russian.png", { 198,727 }, { -2560-400,200 });
	F_Korea = Init(F_Korea, "Flag_Korea.png", { 198,727 }, { -2560 +330,400 });
	F_Spanish = Init(F_Spanish, "Flag_Spanish.png", { 198,727 }, { -2560-310,400 });
	F_English = Init(F_English, "Flag_English.png", { 198,727 }, { -2560-70,320 });
}

void FlagPicture::Update(float _DeltaTime)
{

}

void FlagPicture::Render(float _Delta)
{

};
