#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Chain : public GameEngineActor
{
public:

	Chain();
	~Chain();


	Chain(const Chain& _Other) = delete;
	Chain(Chain&& _Other) noexcept = delete;
	Chain& operator=(const Chain& _Other) = delete;
	Chain& operator=(Chain&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _Time) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> RightChain;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftChain;
};

