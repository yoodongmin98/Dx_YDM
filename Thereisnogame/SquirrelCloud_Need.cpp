#include "PrecompileHeader.h"
#include "SquirrelCloud_Need.h"

//PlatForm
//Core

//Actor


SquirrelCloud_Need::SquirrelCloud_Need()
{
}

SquirrelCloud_Need::~SquirrelCloud_Need()
{
}

void SquirrelCloud_Need::Start()
{
	SquirrelCloud_Needs=Init(SquirrelCloud_Needs, "SquirrelCloud.png", { 279,207 }, { 197,133,0 });
	
}

void SquirrelCloud_Need::Update(float _DeltaTime)
{
	if (GetLiveTime() > 1.0f)
	{
		SquirrelCloud_Needs->ColorOptionValue.MulColor.a -= _DeltaTime*0.5f;
	}
	if (SquirrelCloud_Needs->ColorOptionValue.MulColor.a<=0.0f)
	{
		Death();
	}
}

void SquirrelCloud_Need::Render(float _Delta)
{

};
