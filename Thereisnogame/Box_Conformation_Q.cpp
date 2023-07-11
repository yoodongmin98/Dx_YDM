#include "PrecompileHeader.h"
#include "Box_Conformation_Q.h"

//PlatForm
//Core
//Actor

Box_Conformation_Q::Box_Conformation_Q()
{
}

Box_Conformation_Q::~Box_Conformation_Q()
{
}

void Box_Conformation_Q::Start()
{
	Boxs = Init(Boxs, "MenuOptions_Confirmation_Question.png", { 348,276,1 }, { 0,-270,0 });
	Font = FontCreate(Font, 30, "종료합니까?", { 0,-200,0 }, GetTransform(), 1);
}

void Box_Conformation_Q::Update(float _DeltaTime)
{

}

void Box_Conformation_Q::Render(float _Delta)
{

};
