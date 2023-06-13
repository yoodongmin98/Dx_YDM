#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>

class G_RigidBody;
class G_ActorBase : public GameEngineActor
{
public:
	G_ActorBase();
	~G_ActorBase();


	G_ActorBase(const G_ActorBase& _Other) = delete;
	G_ActorBase(G_ActorBase&& _Other) noexcept = delete;
	G_ActorBase& operator=(const G_ActorBase& _Other) = delete;
	G_ActorBase& operator=(G_ActorBase&& _Other) noexcept = delete;

	std::shared_ptr<GameEngineSpriteRenderer> Init(
		std::shared_ptr<GameEngineSpriteRenderer> _Render,
		const std::string_view& _ImageName,
		float4 _Scale,
		float4 _Position);

	void AnimationImageLoad(const std::string_view& _FileName);

	std::shared_ptr<GameEngineSpriteRenderer> AnimationInit(
		std::shared_ptr<GameEngineSpriteRenderer> _Render,
		const std::string_view& _ImageName,
		float4 _Scale,
		float4 _Position,
		const std::string_view& _AnimationName,
		const std::string_view& _FileName,
		size_t _AnimationCount,
		float _InterTime,
		bool _Loop);

	std::shared_ptr<GameEngineCollision> CollisionInit(
		std::shared_ptr<GameEngineCollision> _Collision,
		float4 _Scale,
		float4 _Position);

	std::shared_ptr<GameEngineCollision> BlockCollisionInit(
		std::shared_ptr<GameEngineCollision> _Collision,
		float4 _Scale,
		float4 _Position);

	std::shared_ptr<GameEngineCollision> BallCollisionInit(
		std::shared_ptr<GameEngineCollision> _Collision,
		float4 _Scale,
		float4 _Position);

	bool ClickCheck(std::shared_ptr<GameEngineCollision> _Collision);

	void RenderRotateCheck(std::shared_ptr<GameEngineSpriteRenderer> _Render);

	void ManagedCollision(std::shared_ptr<GameEngineCollision> _Collision, int Value);

	void Repeat(float _MoveValue, float _DeltaTime);

	void Down(float _DeltaTime);

	void Up(float _DeltaTime);

	void FlagDown(float _EndValue, float _DeltaTime);

	void FlagUp(float _PlusXvalue,float _DeltaTime);

	void CreateRigidBody();

	G_RigidBody* GetRigidBody()
	{
		return pRigidBody;
	}

	void CubeMoveDeathCheck(std::shared_ptr<GameEngineCollision> _Collision);

	void InfinityShape(float _DeltaTime);

	void RoShamboStateCheck(std::shared_ptr<GameEngineCollision> _Collision);

	void RightFallRigid(float _RightValue, float _DownValue, bool _globalvariable, float _DeltaTime);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;


private:
	float ReverseTime = 0.0f;
	float BlockDeathTime = 0.0f;
	float Progress = 0.0f;
	float4 EndPos = float4::Zero;
	
	G_RigidBody* pRigidBody;
};
