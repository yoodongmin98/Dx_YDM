#include "PrecompileHeader.h"
#include "SquirrelCloud_Crack.h"

//PlatForm
//Core



//Actor


SquirrelCloud_Crack::SquirrelCloud_Crack()
{
}

SquirrelCloud_Crack::~SquirrelCloud_Crack()
{
}

void SquirrelCloud_Crack::Start()
{
	SquirrelCloud_Cracks=Init(SquirrelCloud_Cracks, "SquirrelCloud_Crack.png", { 297,207 }, { 197,133,0 });
}

void SquirrelCloud_Crack::Update(float _DeltaTime)
{
	if (GetLiveTime() > 1.0f)
	{
		SquirrelCloud_Cracks->ColorOptionValue.MulColor.a -= _DeltaTime * 0.5f;
	}
	if (SquirrelCloud_Cracks->ColorOptionValue.MulColor.a <= 0.0f)
	{
		Death();
	}
}

void SquirrelCloud_Crack::Render(float _Delta)
{

};
