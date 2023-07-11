#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Truth3Icon : public G_ActorBase
{
public:
	// constrcuter destructer
	Truth3Icon();
	~Truth3Icon();

	// delete Function
	Truth3Icon(const Truth3Icon& _Other) = delete;
	Truth3Icon(Truth3Icon&& _Other) noexcept = delete;
	Truth3Icon& operator=(const Truth3Icon& _Other) = delete;
	Truth3Icon& operator=(Truth3Icon&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Truth3Icons;
	std::shared_ptr<class GameEngineCollision> Truth3IconsCollision;

	std::shared_ptr<class FolderNote3> FolderNotePtr;
	std::shared_ptr<class BoxCroix_FN3> BoxCroix_FN3Ptr;
};

