#include "PrecompileHeader.h"
#include "FlagPicture_Back.h"
#include "ActorTypeEnum.h"
//Base
//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>
//Actor
#include "RouageLoad.h"
#include "Mouse.h"

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

	F_LockOpenRender = Init(F_LockOpenRender, "Lock_Opened.png", { 81,111 }, { -2560+30,250 });
	F_LockOpenRender->Off();
	F_LockRender = Init(F_LockRender, "Lock_Default.png", { 81,111 }, { -2560+30,250 });

	LockCollision = CollisionInit(LockCollision, { 81,111 }, { -2560 + 30,250 });
}

void FlagPicture::Update(float _DeltaTime)
{
	CollisionInterCheck(_DeltaTime);
}

void FlagPicture::Render(float _Delta)
{

};

bool RouageLoadCreateBool = true;
void FlagPicture::CollisionInterCheck(float _DeltaTime)
{
	if (LockCollision->Collision(ActorTypeEnum::Cursor, ColType::AABBBOX2D, ColType::AABBBOX2D)
		&&true==Mouse::MainMouse->IsInteractable())
	{
		Play(Sound, "Unlock.wav", 0.1f);
		LockCollision->Death();
		F_LockRender->Death();
		F_LockOpenRender->On();
	}
	if (true == LockCollision->IsDeath())
	{
		LockFallTime += _DeltaTime;
		if (LockFallTime > 2.0f)
		{
			F_LockOpenRender->GetTransform()->AddLocalPosition({ 0,-700 * _DeltaTime,0 });
			if(true== RouageLoadCreateBool)
			{ 
				GetLevel()->CreateActor<RouageLoad>();
				RouageLoadCreateBool = false;
			}
		}
	}
}