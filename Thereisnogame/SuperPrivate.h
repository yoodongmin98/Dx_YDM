#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class SuperPrivate : public G_ActorBase
{
public:
	// constrcuter destructer
	SuperPrivate();
	~SuperPrivate();

	// delete Function
	SuperPrivate(const SuperPrivate& _Other) = delete;
	SuperPrivate(SuperPrivate&& _Other) noexcept = delete;
	SuperPrivate& operator=(const SuperPrivate& _Other) = delete;
	SuperPrivate& operator=(SuperPrivate&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SuperPrivates;
	std::shared_ptr<class GameEngineCollision> SuperPrivatesCollision;

	std::shared_ptr<class Truth2Icon> Truth2IconPtr;
	std::shared_ptr<class UltraPrivate> UltraPrivatePtr;
	std::shared_ptr<class PrivatePanel_Ultra> PrivatePanel_UltraPtr;
	std::shared_ptr<class BoxCroix_PR_Ultra> BoxCroix_PR_UltraPtr;

	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font1;
	std::shared_ptr<class GameEngineFontRenderer> Font2;
};

