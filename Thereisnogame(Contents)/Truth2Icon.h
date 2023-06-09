#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class Truth2Icon : public G_ActorBase
{
public:
	// constrcuter destructer
	Truth2Icon();
	~Truth2Icon();

	// delete Function
	Truth2Icon(const Truth2Icon& _Other) = delete;
	Truth2Icon(Truth2Icon&& _Other) noexcept = delete;
	Truth2Icon& operator=(const Truth2Icon& _Other) = delete;
	Truth2Icon& operator=(Truth2Icon&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Truth2Icons;
	std::shared_ptr<class GameEngineCollision> Truth2IconsCollision;

	std::shared_ptr<class FolderNote2> FolderNotePtr;
	std::shared_ptr<class BoxCroix_FN2> BoxCroix_FN2Ptr;
};

