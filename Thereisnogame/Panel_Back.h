#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Panel_Back : public G_ActorBase
{
public:
	// constrcuter destructer
	Panel_Back();
	~Panel_Back();

	// delete Function
	Panel_Back(const Panel_Back& _Other) = delete;
	Panel_Back(Panel_Back&& _Other) noexcept = delete;
	Panel_Back& operator=(const Panel_Back& _Other) = delete;
	Panel_Back& operator=(Panel_Back&& _Other) noexcept = delete;

	void ZRotations(float _DeltaTime);
	void RZRotations(float _DeltaTime);

	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Panel_Backs;
	std::shared_ptr<class GameEngineCollision> Panel_BacksCollision;

	std::shared_ptr<class GameEngineFontRenderer> Font;
};

