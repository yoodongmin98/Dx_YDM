#include "PrecompileHeader.h"
#include "FolderBackGround.h"
#include "ActorTypeEnum.h"

//PlatForm
//Core
//Actor


FolderBackGround::FolderBackGround()
{
}

FolderBackGround::~FolderBackGround()
{
}

void FolderBackGround::Start()
{
	FolderBackGrounds = Init(FolderBackGrounds,"FolderBackGround.png", { 1287, 720, 1 }, float4::Zero);
	FolderBackGrounds->ColorOptionValue.MulColor.a = 0.8f;
}

void FolderBackGround::Update(float _DeltaTime)
{
	
}

void FolderBackGround::Render(float _Delta)
{

};


