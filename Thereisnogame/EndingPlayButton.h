#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class EndingPlayButton : public G_ActorBase
{
public:
	// constrcuter destructer
	EndingPlayButton();
	~EndingPlayButton();

	// delete Function
	EndingPlayButton(const EndingPlayButton& _Other) = delete;
	EndingPlayButton(EndingPlayButton&& _Other) noexcept = delete;
	EndingPlayButton& operator=(const EndingPlayButton& _Other) = delete;
	EndingPlayButton& operator=(EndingPlayButton&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> Button;
	
	std::shared_ptr<class GameEngineFontRenderer> Font;
};

