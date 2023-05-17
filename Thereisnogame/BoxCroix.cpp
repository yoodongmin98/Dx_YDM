#include "PrecompileHeader.h"
#include "BoxCroix.h"

//PlatForm
//Core

BoxCroix::BoxCroix()
{

}

BoxCroix::BoxCroix(float4 _Position)
	: Position(_Position)
{
}

BoxCroix::~BoxCroix()
{
}

void BoxCroix::Start()
{
	BoxCroixs = Init(BoxCroixs, "BoxCroix.png", { 48,54 }, {0,0,0});
	//BoxCroixsCollision = CollisionInit(BoxCroixsCollision, { 48,54 }, { 0,0,0 });
}

void BoxCroix::Update(float _DeltaTime)
{
	if (Position != float4::Zero)
	{
		float4 asd = Position;
		BoxCroixs->GetTransform()->SetLocalPosition(Position);
		//BoxCroixsCollision->GetTransform()->SetLocalPosition(Position);
	}
}

void BoxCroix::Render(float _Delta)
{

};
