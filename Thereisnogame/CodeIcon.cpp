#include "PrecompileHeader.h"
#include "CodeIcon.h"

//PlatForm
//Core
#include <GameEngineCore/GameEngineLevel.h>



CodeIcon::CodeIcon()
{
}

CodeIcon::~CodeIcon()
{
}

void CodeIcon::Start()
{
	//�갡CodePicture Create
	Init(CodeIcons, "Picture03.png", { 90,93 }, {-20,20});
}

void CodeIcon::Update(float _DeltaTime)
{

}

void CodeIcon::Render(float _Delta)
{

};
