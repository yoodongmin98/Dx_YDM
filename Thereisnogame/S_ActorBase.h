#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>


class S_ActorBase : public GameEngineActor
{
public:

	S_ActorBase();
	~S_ActorBase();


	S_ActorBase(const S_ActorBase& _Other) = delete;
	S_ActorBase(S_ActorBase&& _Other) noexcept = delete;
	S_ActorBase& operator=(const S_ActorBase& _Other) = delete;
	S_ActorBase& operator=(S_ActorBase&& _Other) noexcept = delete;

	std::shared_ptr<GameEngineSpriteRenderer> Init(
		std::shared_ptr<GameEngineSpriteRenderer> _Render,
		const std::string_view& _ImageName,
		float4 _Scale,
		float4 _Position);

	void SAnimationImageLoad(const std::string_view& _FileName);

	std::shared_ptr<GameEngineSpriteRenderer> SAnimationInit(
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

	void Fall(std::shared_ptr<GameEngineSpriteRenderer> _Render,
		std::shared_ptr<GameEngineSpriteRenderer> _Render2,
		std::shared_ptr<GameEngineCollision> _Collision,
		float _ImageHalfScale, float _DeltaTime);

	bool CatchCheck(std::shared_ptr<GameEngineSpriteRenderer> _Render,
		std::shared_ptr<GameEngineSpriteRenderer> _Render2,
		std::shared_ptr<GameEngineCollision> _Collision);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float ScreenSizeX = GameEngineWindow::GetScreenSize().half().x;
	float ScreenSizeY = GameEngineWindow::GetScreenSize().half().y;

	float FallSpeed = 700.0f;
	float4 MoveDir = float4::Zero;
};
