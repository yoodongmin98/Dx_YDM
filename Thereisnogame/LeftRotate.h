#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// 설명 :
class LeftRotate : public G_ActorBase
{
public:
	// constrcuter destructer
	LeftRotate();
	~LeftRotate();

	// delete Function
	LeftRotate(const LeftRotate& _Other) = delete;
	LeftRotate(LeftRotate&& _Other) noexcept = delete;
	LeftRotate& operator=(const LeftRotate& _Other) = delete;
	LeftRotate& operator=(LeftRotate&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftRotates;
};

