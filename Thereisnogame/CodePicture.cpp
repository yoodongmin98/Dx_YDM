#include "PrecompileHeader.h"
#include "CodePicture.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>



CodePicture::CodePicture()
{
}

CodePicture::~CodePicture()
{
}

void CodePicture::Start()
{
	CodePictures=Init(CodePictures, "Picture03 #75249.png", { 642,642 }, float4::Zero);
}

void CodePicture::Update(float _DeltaTime)
{
	RenderRotateCheck(CodePictures);
}

void CodePicture::Render(float _Delta)
{

};
