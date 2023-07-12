#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PurpleBox : public G_ActorBase
{
public:
	// constrcuter destructer
	PurpleBox();
	~PurpleBox();

	// delete Function
	PurpleBox(const PurpleBox& _Other) = delete;
	PurpleBox(PurpleBox&& _Other) noexcept = delete;
	PurpleBox& operator=(const PurpleBox& _Other) = delete;
	PurpleBox& operator=(PurpleBox&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PurpleBoxs;
};

