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
	Boxs = Init(Boxs, "MenuOptions_Confirmation_Yes.png", { 435*0.6f,447*0.6f,1 }, {-230,-320,0});
	Font = FontCreate(Font, 40, "¿¹", { -240,-250,0 }, GetTransform(), 1);
}

void Box_Conformation_Yes::Update(float _DeltaTime)
{
	
}

void Box_Conformation_Yes::Render(float _Delta)
{

};
