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
	//나중엔 알파값으로 바꿔야함
	if (GetLiveTime() > 2.0f)
	{
		Death();
	}
}

void SquirrelCloud_Need::Render(float _Delta)
{

};
