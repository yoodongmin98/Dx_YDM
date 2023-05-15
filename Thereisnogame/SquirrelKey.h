#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// 설명 :
class SquirrelKey : public S_ActorBase
{
public:
	// constrcuter destructer
	SquirrelKey();
	~SquirrelKey();

	// delete Function
	SquirrelKey(const SquirrelKey& _Other) = delete;
	SquirrelKey(SquirrelKey&& _Other) noexcept = delete;
	SquirrelKey& operator=(const SquirrelKey& _Other) = delete;
	SquirrelKey& operator=(SquirrelKey&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SquirrelKeys;
};

