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
	, MaxSpeed(100.0f) //�ִ�ӵ�
	, FrictionCoeff(0.0f) //�������
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
	//���ǹ���
	float XX = Force.x;
	float YY = Force.y;
	float Length = sqrt(XX * XX + YY * YY);
	if (Length !=0.0f)
	{
		Force.Normalize();
		//���ӵ��� ũ��
		float fAccel = Length / Mass;
		//���ӵ�
		Accel = Force * fAccel;
		//�ӵ�
		float Times = GameEngineTime::GlobalTime.GetDeltaTime(); //DeltaTime�� �� �����Ӹ��� ������ �޾ƿ;���
		Velocity += Accel * Times;
		if (MaxSpeed < Length)
		{
			Velocity.Normalize();
			Velocity *= MaxSpeed;
		}
	}

	Move();

	Force = float4::Zero; //���������� ��� ���� �����ϰ� �ְ� ���� ������ �����.(Move�� �������)
}

void G_RigidBody::Move()
{
	//�̵��ӷ�
	float XX = Velocity.x;
	float YY = Velocity.y;
	float fSpeed = sqrt(XX * XX + YY * YY);
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

