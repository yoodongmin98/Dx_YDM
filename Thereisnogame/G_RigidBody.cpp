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
	//����ũ��(�����Ǳ���)
	float Length=sqrt(Xs * Xs + Ys * Ys);
	//���ǹ���
	if (Length !=0.0f)
	{
		Force.Normalize();
		//���ӵ��� ũ��
		float fAccel = Length / Mass;
		//���ӵ�
		Accel = Force * fAccel;
		//�ӵ�
		float Times = GameEngineTime::GlobalTime.GetDeltaTime();
		Velocity += Accel * Times;
	}

	Move();

	Force = float4::Zero; //���������� ��� ���� �����ϰ� �ְ� ���� ������ �����.
}

void G_RigidBody::Move()
{
	float VX = Velocity.x;
	float VY = Velocity.y;
	float VLength = sqrt(VX* VX + VY* VY);
	//�̵��ӷ�
	float fSpeed = VLength;
	if (0.0f != fSpeed)
	{
		//�̵�����
		float4 Dir = Velocity;
		Dir.Normalize();

		float4 vPos = Parents->GetTransform()->GetLocalPosition();
		float Times = GameEngineTime::GlobalTime.GetDeltaTime();
		vPos += Dir * fSpeed * Times;

		Parents->GetTransform()->SetLocalPosition(vPos);
	}
}