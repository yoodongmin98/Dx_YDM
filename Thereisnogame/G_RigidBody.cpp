#include "PrecompileHeader.h"
#include "G_RigidBody.h"
#include <math.h>

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
	float Length=sqrt(Xs + Ys);
	//���ǹ���
	Force.Normalize();
	//���ӵ��� ũ��
	float fAccel = Length / Mass;
	//���ӵ�
	Accel = Force * fAccel;
	//�ӵ�
	Velocicy += Accel;

	Move();

	Force = { 0.0f,0.0f }; //���������� ��� ���� �����ϰ� �ְ� ���� ������ �����.
}

void G_RigidBody::Move()
{

}