#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// 설명 :
class Cup_Full : public S_ActorBase
{
public:
	// constrcuter destructer
	Cup_Full();
	~Cup_Full();

	// delete Function
	Cup_Full(const Cup_Full& _Other) = delete;
	Cup_Full(Cup_Full&& _Other) noexcept = delete;
	Cup_Full& operator=(const Cup_Full& _Other) = delete;
	Cup_Full& operator=(Cup_Full&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Cup_Fulls;
	std::shared_ptr<class GameEngineSpriteRenderer> Cup_Fulls_overlap;

	std::shared_ptr<class GameEngineCollision> Cup_FullsCollision;
};

