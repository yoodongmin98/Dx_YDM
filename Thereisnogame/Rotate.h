#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "G_ActorBase.h"

// ���� :
class Rotate : public G_ActorBase
{
public:
	// constrcuter destructer
	Rotate();
	~Rotate();

	// delete Function
	Rotate(const Rotate& _Other) = delete;
	Rotate(Rotate&& _Other) noexcept = delete;
	Rotate& operator=(const Rotate& _Other) = delete;
	Rotate& operator=(Rotate&& _Other) noexcept = delete;


protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> LeftRotate;
	std::shared_ptr<class GameEngineSpriteRenderer> RightRotate;

	

};

