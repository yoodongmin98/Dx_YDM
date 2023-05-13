#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PurpleTextBox : public G_ActorBase
{
public:
	// constrcuter destructer
	PurpleTextBox();
	~PurpleTextBox();

	// delete Function
	PurpleTextBox(const PurpleTextBox& _Other) = delete;
	PurpleTextBox(PurpleTextBox&& _Other) noexcept = delete;
	PurpleTextBox& operator=(const PurpleTextBox& _Other) = delete;
	PurpleTextBox& operator=(PurpleTextBox&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PurpleTextBoxs;
};

