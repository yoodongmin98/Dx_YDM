#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "S_ActorBase.h"

// ���� :
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

	//Text�� �������ִ� �Լ��߰�
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> Decapsuleurs;
};

