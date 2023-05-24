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

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PasswordIcons;
	std::shared_ptr<class GameEngineCollision> PasswordIconsCollision;

	std::shared_ptr<class FolderNote_Password> FolderNote_PasswordPtr;
	std::shared_ptr<class BoxCroix_FN1> BoxCroix_FN1Ptr;

};

