#include "PrecompileHeader.h"
#include "Box_Conformation_No.h"

//PlatForm
//Core
//Actor

Box_Conformation_No::Box_Conformation_No()
{
}

Box_Conformation_No::~Box_Conformation_No()
{
}

void Box_Conformation_No::Start()
{
	Boxs = Init(Boxs, "MenuOptions_Confirmation_No.png", { 273,309,1 }, float4::Zero);
}

void Box_Conformation_No::Update(float _DeltaTime)
{

}

void Box_Conformation_No::Render(float _Delta)
{

};
