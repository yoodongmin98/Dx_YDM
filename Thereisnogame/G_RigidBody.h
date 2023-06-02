#pragma once
#include <GameEngineBase/GameEngineTime.h>

class G_ActorBase;
class G_RigidBody 
{
public:
	friend class G_ActorBase;
	G_RigidBody();
	~G_RigidBody();

	// delete Function
	G_RigidBody(const G_RigidBody& _Other) = delete;
	G_RigidBody(G_RigidBody&& _Other) noexcept = delete;
	G_RigidBody& operator=(const G_RigidBody& _Other) = delete;
	G_RigidBody& operator=(G_RigidBody&& _Other) noexcept = delete;

	void RigidBodyUpdate();
	void AddForce(float4 _Forces)
	{
		Force += _Forces;
	}
	//�⺻������ 1 ��������
	void SetMass(float _Mass)
	{
		Mass = _Mass;
	}
	float GetMass()
	{
		return Mass;
	}
	//�ӵ�
	void SetVelocity(float4 _Velocity)
	{
		Velocity = _Velocity;
	}
	//�ִ�ӷ�
	void SetMaxVelocity(float _MaxMaxSpeed)
	{
		MaxSpeed = _MaxMaxSpeed;
	}
protected:



private:
	G_ActorBase* Parents;

	float4 Force = float4::Zero; //ũ��,����
	float4 Accel; //���ӵ�
	float Mass;//����
	float4 Velocity;//�ӵ�(ũ��: �ӷ�,����)
	float MaxSpeed;//�ִ�ӷ�

	float FrictionCoeff;//�������



	// F = M * A;
	// V += A * DeltaTime;
	void Move();
	
};

