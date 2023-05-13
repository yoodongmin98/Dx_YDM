#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class JPMissIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	JPMissIcon();
	~JPMissIcon();

	// delete Function
	JPMissIcon(const JPMissIcon& _Other) = delete;
	JPMissIcon(JPMissIcon&& _Other) noexcept = delete;
	JPMissIcon& operator=(const JPMissIcon& _Other) = delete;
	JPMissIcon& operator=(JPMissIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> JPMissIcons;
};

