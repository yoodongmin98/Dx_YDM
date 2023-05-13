#include "PrecompileHeader.h"
#include "PasswordIcon.h"

//PlatForm
//Core




PasswordIcon::PasswordIcon()
{
}

PasswordIcon::~PasswordIcon()
{
}

void PasswordIcon::Start()
{
	//¾ê°¡ PasswordIconIcon Create
	PasswordIcons = Init(PasswordIcons, "Document.png", { 75,93 }, float4::Zero);
}

void PasswordIcon::Update(float _DeltaTime)
{

}

void PasswordIcon::Render(float _Delta)
{

};
