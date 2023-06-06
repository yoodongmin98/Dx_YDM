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
	, Mass(1.0f) //����
	, MaxSpeed(1000.0f) //�ִ�ӵ�
	, FrictionCoeff(10.0f) //�������
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
		MsgAssert("RigidBody�� �θ� �������� �ʽ��ϴ�");
	}
	//DeltaTime
	float Times = GameEngineTime::GlobalTime.GetDeltaTime(); //DeltaTime�� �� �����Ӹ��� ������ �޾ƿ;���
	//���ǹ���
	float Length = Force.Size();
	if (Length !=0.0f)
	{
		Force.Normalize();
		//���ӵ��� ũ��
		float fAccel = Length / Mass;
		//���ӵ�
		Accel = Force * fAccel;
		//�ӵ�
		Velocity += Accel * Times;
	}

	//�����¿� ���� �ݴ���������� ���ӵ�
	if (!Velocity.IsZero())
	{
		float4 FricDir = -Velocity;
		FricDir.Normalize();
		float4 VecDir = FricDir * FrictionCoeff * Times;
		if (VecDir.Size() > Velocity.Size())
		{
			//���� ���ӵ��� ���� �ӵ����� �� ū ���
			Velocity = float4::Zero;
		}
		else
		{
			Velocity += VecDir;
		}
	}

	//�ӵ����� �˻�
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

	Force = float4::Zero; //���������� ��� ���� �����ϰ� �ְ� ���� ������ �����.(Move�� �������)
}

void G_RigidBody::Move()
{
	//�̵��ӷ�
	float fSpeed = Velocity.Size();
	if (0.0f != fSpeed)
	{
		//�̵�����
		float4 Dir = Velocity;
		Dir.Normalize();
		//Actor�� ��ġ�� �����ͼ�
		float4 APosition = Parents->GetTransform()->GetLocalPosition();
		float Times = GameEngineTime::GlobalTime.GetDeltaTime();
		//�ӷ�*���� ���� DeltaTime��ŭ �����̴� ���� �����
		APosition += Dir * fSpeed * Times;
		//����ġ�� Setting
		Parents->GetTransform()->SetLocalPosition(APosition);
	}
}

