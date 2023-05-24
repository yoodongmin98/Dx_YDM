#include "PrecompileHeader.h"
#include "PasswordIcon.h"

//PlatForm
//Core

//Actor
#include "ColManager.h"


PasswordIcon::PasswordIcon()
{
}

PasswordIcon::~PasswordIcon()
{
}

void PasswordIcon::Start()
{
	PasswordIcons = Init(PasswordIcons, "Document.png", { 75,93 }, {-170,20});
}

void PasswordIcon::Update(float _DeltaTime)
{

}

void PasswordIcon::Render(float _Delta)
{

};
