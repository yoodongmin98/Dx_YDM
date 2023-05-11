#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>


class G_ActorBase : public GameEngineActor
{
public:

	G_ActorBase();
	~G_ActorBase();


	G_ActorBase(const G_ActorBase& _Other) = delete;
	G_ActorBase(G_ActorBase&& _Other) noexcept = delete;
	G_ActorBase& operator=(const G_ActorBase& _Other) = delete;
	G_ActorBase& operator=(G_ActorBase&& _Other) noexcept = delete;

	void Init(std::shared_ptr<GameEngineSpriteRenderer> _Render, const std::string_view& _ImageName, float4 _Scale, float4 _Position);
	void AnimationImageLoad(const std::string_view& _FileName);
	void Repeat(float _MoveValue, float _DeltaTime);
	void Down(float _DeltaTime);
	void Up(float _DeltaTime);
	void FlagDown(float _EndValue, float _DeltaTime);
	void FlagUp(float _PlusXvalue,float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;


private:
	float ReverseTime = 0.0f;
	float4 EndPos = float4::Zero;
};
