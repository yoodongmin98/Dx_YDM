#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class Private18 : public G_ActorBase
{
public:
	// constrcuter destructer
	Private18();
	~Private18();

	// delete Function
	Private18(const Private18& _Other) = delete;
	Private18(Private18&& _Other) noexcept = delete;
	Private18& operator=(const Private18& _Other) = delete;
	Private18& operator=(Private18&& _Other) noexcept = delete;

	void BoxCroixDeathCheck();
	GameEngineSoundPlayer Sound;
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Private18s;
	std::shared_ptr<class GameEngineCollision> Private18sCollision;

	std::shared_ptr<class PrivatePanel_Miss> PrivatePanel_MissPtr;
	std::shared_ptr<class BoxCroix_PR_Miss> BoxCroix_PR_MissPtr;
	std::shared_ptr<class FRMissIcon> FRMissIconPtr;
	std::shared_ptr<class JPMissIcon> JPMissIconPtr;
	std::shared_ptr<class USMissIcon> USMissIconPtr;

	std::shared_ptr<class GameEngineFontRenderer> Font;
	std::shared_ptr<class GameEngineFontRenderer> Font1;
};

