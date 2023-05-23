#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// 설명 :
class Nut_Close : public S_ActorBase
{
public:
	// constrcuter destructer
	Nut_Close();
	~Nut_Close();

	// delete Function
	Nut_Close(const Nut_Close& _Other) = delete;
	Nut_Close(Nut_Close&& _Other) noexcept = delete;
	Nut_Close& operator=(const Nut_Close& _Other) = delete;
	Nut_Close& operator=(Nut_Close&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Nut_Closes;
	std::shared_ptr<class GameEngineSpriteRenderer> Nut_Closes_overlap;

	std::shared_ptr<class GameEngineCollision> Nut_ClosesCollision;
};

