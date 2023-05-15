#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// 설명 :
class Cup : public S_ActorBase
{
public:
	// constrcuter destructer
	Cup();
	~Cup();

	// delete Function
	Cup(const Cup& _Other) = delete;
	Cup(Cup&& _Other) noexcept = delete;
	Cup& operator=(const Cup& _Other) = delete;
	Cup& operator=(Cup&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Cups;
};

