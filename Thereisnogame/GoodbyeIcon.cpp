#include "PrecompileHeader.h"
#include "GoodbyeIcon.h"

//PlatForm
//Core




GoodbyeIcon::GoodbyeIcon()
{
}

GoodbyeIcon::~GoodbyeIcon()
{
}

void GoodbyeIcon::Start()
{
	//¾ê°¡ FolderNote Create
	GoodbyeIcons = Init(GoodbyeIcons, "Document.png", { 75,93 }, float4::Zero);
}

void GoodbyeIcon::Update(float _DeltaTime)
{

}

void GoodbyeIcon::Render(float _Delta)
{

};
