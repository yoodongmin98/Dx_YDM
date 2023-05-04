#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class F_Spanish : public G_ActorBase
{
public:
	// constrcuter destructer
	F_Spanish();
	~F_Spanish();

	// delete Function
	F_Spanish(const F_Spanish& _Other) = delete;
	F_Spanish(F_Spanish&& _Other) noexcept = delete;
	F_Spanish& operator=(const F_Spanish& _Other) = delete;
	F_Spanish& operator=(F_Spanish&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> F_Spanishs;
	std::shared_ptr<class GameEngineSpriteRenderer> FlagChain;
};

