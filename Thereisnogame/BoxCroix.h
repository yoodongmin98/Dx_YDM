#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class BoxCroix : public G_ActorBase
{
public:
	// constrcuter destructer
	BoxCroix(float4);
	BoxCroix();
	~BoxCroix();

	// delete Function
	BoxCroix(const BoxCroix& _Other) = delete;
	BoxCroix(BoxCroix&& _Other) noexcept = delete;
	BoxCroix& operator=(const BoxCroix& _Other) = delete;
	BoxCroix& operator=(BoxCroix&& _Other) noexcept = delete;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BoxCroixs;

	float4 Position;

};

