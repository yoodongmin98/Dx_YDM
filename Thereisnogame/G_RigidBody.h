#pragma once

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
protected:



private:
	G_ActorBase* Parents; 

	float4 Force; //크기,방향
	float4 Accel; //가속도
	float Mass;//질량
	float4 Velocicy;//속도(크기: 속력,방향)

	// F = M * A;
	// V += A * DeltaTime;
	void Move();
};

