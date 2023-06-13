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
	//기본질량은 1 질량설정
	void SetMass(float _Mass)
	{
		Mass = _Mass;
	}
	float GetMass()
	{
		return Mass;
	}
	//속도
	void ChangeYDir()
	{
		Velocity.y = -Velocity.y;
	}
	void ChangeXDir()
	{
		Velocity.x = -Velocity.x;
	}
	void SetVelocity(float4 _Velocity)
	{
		Velocity = _Velocity;
	}
	void AddVelocity(float4 _AddVelocity)
	{
		Velocity += _AddVelocity;
	}
	//최대속력
	void SetMaxVelocity(float _MaxMaxSpeed)
	{
		MaxSpeed = _MaxMaxSpeed;
	}
	//마찰력
	void SetFrictionCoeff(float _Value)
	{
		FrictionCoeff = _Value;
	}

protected:



private:
	G_ActorBase* Parents;

	float4 Force = float4::Zero; //크기,방향
	float4 Accel; //가속도
	float Mass;//질량
	float4 Velocity;//속도(크기: 속력,방향)
	float MaxSpeed;//최대속력
	float MinSpeed;
	float FrictionCoeff;//마찰계수



	// F = M * A;
	// V += A * DeltaTime;
	void Move();
	
};

