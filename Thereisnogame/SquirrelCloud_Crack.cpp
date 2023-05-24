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
	//나중엔 알파값으로 바꿔야함
	if (GetLiveTime() > 3.0f)
	{
		Death();
	}
}

void SquirrelCloud_Crack::Render(float _Delta)
{

};
