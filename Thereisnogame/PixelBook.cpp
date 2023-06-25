#include "PrecompileHeader.h"
#include "PixelBook.h"
//Base
//PlatForm
//Core
//Actor
PixelBook::PixelBook()
{
}

PixelBook::~PixelBook()
{
}
bool PixelBookAnimationLoadBool = true;
void PixelBook::Start()
{
	if (true == PixelBookAnimationLoadBool)
	{
		AnimationImageLoad("DisplayCog");
		AnimationImageLoad("DisPlaySheep");
		PixelBookAnimationLoadBool = false;
	}
	float4 Position = {-1280,-100};

	Lope1 = Init(Lope1, "MainMenu_LongRope.png", { 21,519 }, { -1480,150 });
	Lope2 = Init(Lope2, "MainMenu_LongRope.png", { 21,519 }, { -1070,150 });
	BoxMenus = Init(BoxMenus, "NotAgameBy_Panel.png", { 354,422 }, { -1700,300 });
	PixelBooks = NoChangeAnimationInit(PixelBooks, "DrawMeAPixelBook02.png", { 597,422 }, Position, "ChangeSheep", "DisPlaySheep", 2, 0.2f, false);
	PixelBooks = NoChangeAnimationInit(PixelBooks, "DrawMeAPixelBook05.png", { 597,422 }, Position, "ChangeCog", "DisplayCog", 2, 0.2f, false);
	PixelBooks = NullCheckInit(PixelBooks, "DrawMeAPixelBook01.png", { 597,457 }, Position);
	PixelBooksCollision = CollisionInit(PixelBooksCollision, { 597,422 }, Position);
}

void PixelBook::Update(float _DeltaTime)
{
	PageAnimationSet();
}

void PixelBook::Render(float _Delta)
{

};

void PixelBook::PageAnimationSet()
{
	if (true == ClickCheck(PixelBooksCollision)
		&& 2 > AnimationValue)
	{
		++AnimationValue;
		if (1 == AnimationValue)
		{
			PixelBooks->ChangeAnimation("ChangeSheep");
		}
		else if (2 == AnimationValue)
		{
			PixelBooks->ChangeAnimation("ChangeCog");
		}
	}
}