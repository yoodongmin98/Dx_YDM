#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class EndingDeleteButton : public G_ActorBase
{
public:
	// constrcuter destructer
	EndingDeleteButton();
	~EndingDeleteButton();

	// delete Function
	EndingDeleteButton(const EndingDeleteButton& _Other) = delete;
	EndingDeleteButton(EndingDeleteButton&& _Other) noexcept = delete;
	EndingDeleteButton& operator=(const EndingDeleteButton& _Other) = delete;
	EndingDeleteButton& operator=(EndingDeleteButton&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> WoodPanel;
	std::shared_ptr<class GameEngineSpriteRenderer> Buttons;

};

