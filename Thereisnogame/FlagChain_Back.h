#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

class FlagChain_Back : public G_ActorBase
{
public:
	FlagChain_Back();
	~FlagChain_Back();

	FlagChain_Back(const FlagChain_Back& _Other) = delete;
	FlagChain_Back(FlagChain_Back&& _Other) noexcept = delete;
	FlagChain_Back& operator=(const FlagChain_Back& _Other) = delete;
	FlagChain_Back& operator=(FlagChain_Back&& _Other) noexcept = delete;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain_Backs;
};

