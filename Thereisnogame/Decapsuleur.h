#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// 설명 :
class Decapsuleur : public S_ActorBase
{
public:
	// constrcuter destructer
	Decapsuleur();
	~Decapsuleur();

	// delete Function
	Decapsuleur(const Decapsuleur& _Other) = delete;
	Decapsuleur(Decapsuleur&& _Other) noexcept = delete;
	Decapsuleur& operator=(const Decapsuleur& _Other) = delete;
	Decapsuleur& operator=(Decapsuleur&& _Other) noexcept = delete;

	//Text를 받을수있는 함수추가
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Decapsuleurs;
};

