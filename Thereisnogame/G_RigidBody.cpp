#include "PrecompileHeader.h"
#include "G_RigidBody.h"
#include <math.h>
#include "G_ActorBase.h"
//Base
#include <GameEngineBase/GameEngineTime.h>
//PlatForm
//Core


G_RigidBody::G_RigidBody()
	:Parents(nullptr)
	, Mass(1.0f)
{
}

G_RigidBody::~G_RigidBody()
{
}

void G_RigidBody::RigidBodyUpdate()
{
	float Xs = Force.x;
	float Ys = Force.y;
	//힘의크기(벡터의길이)
	float Length=sqrt(Xs * Xs + Ys * Ys);
	//힘의방향
	if (Length !=0.0f)
	{
		Force.Normalize();
		//가속도의 크기
		float fAccel = Length / Mass;
		//가속도
		Accel = Force * fAccel;
		//속도
		float Times = GameEngineTime::GlobalTime.GetDeltaTime();
		Velocity += Accel * Times;
	}

	Move();

	Force = float4::Zero; //끝날때마다 계속 힘을 꾸준하게 주고 있지 않으면 멈춘다.
}

void G_RigidBody::Move()
{
	float VX = Velocity.x;
	float VY = Velocity.y;
	float VLength = sqrt(VX* VX + VY* VY);
	//이동속력
	float fSpeed = VLength;
	if (0.0f != fSpeed)
	{
		//이동방향
		float4 Dir = Velocity;
		Dir.Normalize();

		float4 vPos = Parents->GetTransform()->GetLocalPosition();
		float Times = GameEngineTime::GlobalTime.GetDeltaTime();
		vPos += Dir * fSpeed * Times;

		Parents->GetTransform()->SetLocalPosition(vPos);
	}
}