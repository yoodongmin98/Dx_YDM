#include "PrecompileHeader.h"
#include "GoodbyeIcon.h"

//PlatForm
//Core

//Actor
#include "ColManager.h"


GoodbyeIcon::GoodbyeIcon()
{
}

GoodbyeIcon::~GoodbyeIcon()
{
}

void GoodbyeIcon::Start()
{
	GoodbyeIcons = Init(GoodbyeIcons, "Document.png", { 75,93 }, {-10,20,0,});
}

void GoodbyeIcon::Update(float _DeltaTime)
{

}

void GoodbyeIcon::Render(float _Delta)
{

};
