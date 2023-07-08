#include "PrecompileHeader.h"
#include "Box_Conformation_Yes.h"

//PlatForm
//Core
//Actor

Box_Conformation_Yes::Box_Conformation_Yes()
{
}

Box_Conformation_Yes::~Box_Conformation_Yes()
{
}

void Box_Conformation_Yes::Start()
{
	Boxs = Init(Boxs, "MenuOptions_Confirmation_Yes.png", { 435*0.7f,447*0.7f,1 }, {-200,-350,0});
}

void Box_Conformation_Yes::Update(float _DeltaTime)
{
	
}

void Box_Conformation_Yes::Render(float _Delta)
{

};
