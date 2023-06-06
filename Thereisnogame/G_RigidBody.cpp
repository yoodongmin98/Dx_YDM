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
	, Mass(1.0f) //질량
	, MaxSpeed(1000.0f) //최대속도
	, FrictionCoeff(10.0f) //마찰계수
	, MinSpeed(500.0f)
{

}

G_RigidBody::~G_RigidBody()
{
}

void G_RigidBody::RigidBodyUpdate()
{
	if (Parents == nullptr)
	{
		MsgAssert("RigidBody의 부모가 존재하지 않습니다");
	}
	//DeltaTime
	float Times = GameEngineTime::GlobalTime.GetDeltaTime(); //DeltaTime은 매 프레임마다 꾸준히 받아와야함
	//힘의방향
	float Length = Force.Size();
	if (Length !=0.0f)
	{
		Force.Normalize();
		//가속도의 크기
		float fAccel = Length / Mass;
		//가속도
		Accel = Force * fAccel;
		//속도
		Velocity += Accel * Times;
	}

	//마찰력에 의한 반대방향으로의 가속도
	if (!Velocity.IsZero())
	{
		float4 FricDir = -Velocity;
		FricDir.Normalize();
		float4 VecDir = FricDir * FrictionCoeff * Times;
		if (VecDir.Size() > Velocity.Size())
		{
			//마찰 가속도가 본래 속도보다 더 큰 경우
			Velocity = float4::Zero;
		}
		else
		{
			Velocity += VecDir;
		}
	}

	//속도제한 검사
	if (MaxSpeed < Length)
	{
		Velocity.Normalize();
		Velocity *= MaxSpeed;
	}
	else if (MinSpeed > Length)
	{
		Velocity.Normalize();
		Velocity *= MinSpeed;
	}

	Move();

	Force = float4::Zero; //끝날때마다 계속 힘을 꾸준하게 주고 있지 않으면 멈춘다.(Move는 계속진행)
}

void G_RigidBody::Move()
{
	//이동속력
	float fSpeed = Velocity.Size();
	if (0.0f != fSpeed)
	{
		//이동방향
		float4 Dir = Velocity;
		Dir.Normalize();
		//Actor의 위치를 가져와서
		float4 APosition = Parents->GetTransform()->GetLocalPosition();
		float Times = GameEngineTime::GlobalTime.GetDeltaTime();
		//속력*방향 으로 DeltaTime만큼 움직이는 값을 만들고
		APosition += Dir * fSpeed * Times;
		//그위치에 Setting
		Parents->GetTransform()->SetLocalPosition(APosition);
	}
}

