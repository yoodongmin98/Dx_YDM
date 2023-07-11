#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
class UltraPrivate : public G_ActorBase
{
public:
	// constrcuter destructer
	UltraPrivate();
	~UltraPrivate();

	// delete Function
	UltraPrivate(const UltraPrivate& _Other) = delete;
	UltraPrivate(UltraPrivate&& _Other) noexcept = delete;
	UltraPrivate& operator=(const UltraPrivate& _Other) = delete;
	UltraPrivate& operator=(UltraPrivate&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> UltraPrivates;
	std::shared_ptr<class GameEngineCollision> UltraPrivatesCollision;

	std::shared_ptr<class Gigaprivate> GigaprivatePtr;
	std::shared_ptr<class Truth3Icon> Truth3IconPtr;
	std::shared_ptr<class PrivatePanel_Giga> PrivatePanel_GigaPtr;
	std::shared_ptr<class BoxCroix_PR_Giga> BoxCroix_PR_GigaPtr;
};

