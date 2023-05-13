#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class PasswordIcon : public G_ActorBase
{
public:
	// constrcuter destructer
	PasswordIcon();
	~PasswordIcon();

	// delete Function
	PasswordIcon(const PasswordIcon& _Other) = delete;
	PasswordIcon(PasswordIcon&& _Other) noexcept = delete;
	PasswordIcon& operator=(const PasswordIcon& _Other) = delete;
	PasswordIcon& operator=(PasswordIcon&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PasswordIcons;


};

