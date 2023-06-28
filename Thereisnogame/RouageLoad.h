#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

class RouageLoad : public S_ActorBase
{
public:
	RouageLoad();
	~RouageLoad();

	RouageLoad(const RouageLoad& _Other) = delete;
	RouageLoad(RouageLoad&& _Other) noexcept = delete;
	RouageLoad& operator=(const RouageLoad& _Other) = delete;
	RouageLoad& operator=(RouageLoad&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> RouageLoads;
	std::shared_ptr<class GameEngineSpriteRenderer> RouageLoads_overlap;
	
	std::shared_ptr<class GameEngineCollision> RouageLoadsCollision;
};

