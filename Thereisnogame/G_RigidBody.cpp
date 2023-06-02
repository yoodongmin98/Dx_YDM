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
	//힘의크기(벡터의길이)
	float Length=sqrt(Xs + Ys);
	//힘의방향
	Force.Normalize();
	//가속도의 크기
	float fAccel = Length / Mass;
	//가속도
	Accel = Force * fAccel;
	//속도
	Velocicy += Accel;

	Move();

	Force = { 0.0f,0.0f }; //끝날때마다 계속 힘을 꾸준하게 주고 있지 않으면 멈춘다.
}

void G_RigidBody::Move()
{

}