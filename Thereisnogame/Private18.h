#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// Ό³Έν :
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


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Private18s;

};

