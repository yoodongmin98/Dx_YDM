#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>


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
	void AnimationImageLoad(const std::string_view& _FileName);
	std::shared_ptr<GameEngineSpriteRenderer> AnimationInit(
		std::shared_ptr<GameEngineSpriteRenderer> _Render,
		const std::string_view& _ImageName,
		float4 _Scale,
		float4 _Position,
		const std::string_view& _AnimationName,
		const std::string_view& _FileName,
		size_t _AnimationCount,
		float _InterTime);
	void Repeat(float _MoveValue, float _DeltaTime);
	void Down(float _DeltaTime);
	void Up(float _DeltaTime);
	void FlagDown(float _EndValue, float _DeltaTime);
	void FlagUp(float _PlusXvalue, float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;


private:
	float ReverseTime = 0.0f;
	float4 EndPos = float4::Zero;
};
